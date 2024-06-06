#include "../header/Game.hpp"

#include <cctype>
#include <fstream>

#include "../header/Board.hpp"
#include "rapidjson/stringbuffer.h"
#include "rapidjson/writer.h"

using namespace rapidjson;
using namespace std;

void Game::startGame() {
  string userInput;
  output << "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): ";
  while (getline(input, userInput)) {
    if (userInput.empty()) {
      output << "Please enter a choice." << endl;
      startGame();
    } else if (userInput == "start") {
      startNewGame();
      break;
    } else if (userInput == "continue") {
      loadSavedGame();
      break;
    } else {
      output << "This is not valid input, please try again." << endl;
      output << "Do you want to start a game (enter \"start\") or continue a previous one? (enter \"continue\"): ";
    }
  }
}

void Game::startNewGame() {
  string player1name;
  string player2name;

  board.initializeBoard();

  output << "Please enter your game name: ";
  getline(input, gameName);
  output << "Please enter Player 1's name: ";
  getline(input, player1name);
  player1 = Player(PieceColor::WHITE, player1name);
  output << "Please enter Player 2's name: ";
  getline(input, player2name);
  player2 = Player(PieceColor::BLACK, player2name);

  string message = "Welcome to the game! " + player1.getName() + " (White) will start the game.";

  currentPlayer = &player1;

  output << message << endl;

  playGame();
}

void Game::playGame() {
  string gameInput;
  DisplayBoard displayBoard(board);

  while (true) {
    string boardStr = displayBoard.displayBoard(currentPlayer != nullptr ? player2.getName() == currentPlayer->getName() : false);
    output << boardStr << endl;

    if (board.checkMate().first) {
      endGame(currentPlayer->getColor() == board.checkMate().second ? &player1 : &player2);
      output << "Thank you for playing!" << endl;
      break;
    }

    if (currentPlayer) {
      string message = "It is " + currentPlayer->getName() + "'s turn.";

      output << message << endl;
    }

    output << "Enter \"quit\" to end the game or \"move\" to proceed." << endl;

    input >> gameInput;

    if (gameInput == "quit") {
      quitGame();
      break;
    } else if (gameInput == "move") {
      askUserForMove();
    } else {
      output << "Invalid input." << endl;
    }
  }
}

void Game::loadSavedGame() {
  // need to choose from a list of saved games
  output << "What saved game would you like to load?" << endl << endl;
  vector<string> files;

  DIR* dir;
  dirent* ent;

  if((dir = opendir("./saves")) != nullptr) {
    while((ent = readdir(dir)) != nullptr) {
      string fullName = ent->d_name;
      if(fullName == "." or fullName == "..") continue;
      size_t pos = fullName.find(".json");
      string name = fullName.substr(0, pos);
      output << name << endl;
      files.push_back(name);
    }
    closedir(dir);
  }
  if((dir = opendir("./saves")) == nullptr or files.empty()) {
    output << "No saved games to load." << endl;
    startGame();
    return;
  }

checkFile:
  string filename;
  input >> filename;
  
  vector<string>::iterator itr = find(files.begin(), files.end(), filename);
  if(itr == files.end()) {
    output << "Could not find filename. Please try again." << endl;
    goto checkFile;
  }

  string loadPath = "saves/" + filename + ".json";
  const char* path = loadPath.c_str();

  // load the game
  FILE* file = fopen(path, "r");

  if (file == nullptr) {
    output << "Could not open file :(\n";
    return;
  }

  char readBuffer[65536];
  rapidjson::FileReadStream is(file, readBuffer, sizeof(readBuffer));

  rapidjson::Document document;

  document.ParseStream(is);
  // check if the document is valid
  if (document.HasParseError()) {
    output << "Error parsing the JSON file. Could not open game" << endl;
    return;
  }

  // get the game name
  gameName = document["gameName"].GetString();
  output << "Game: " << gameName << endl;

  // get the player names
  player1.setName(document["player1"]["name"].GetString());
  output << "Player 1: " << player1.getName() << endl;
  player1.setColor(document["player1"]["color"] == "White" ? WHITE : BLACK);
  currentPlayer = document["player1"]["currentPlayer"] == true ? &player1 : &player2;

  player2.setName(document["player2"]["name"].GetString());
  output << "Player 2: " << player2.getName() << endl;
  player2.setColor(document["player2"]["color"] == "White" ? WHITE : BLACK);

  output << "Current move belongs to: " << currentPlayer->getName() << endl;

  if (!document["board"].IsArray()) {
    output << "Error parsing the JSON file. Could not open game" << endl;
    return;
  }

  // get the board
  const rapidjson::Value& jsonBoard = document["board"].GetArray();
  std::vector<pair<pair<int, int>, string>> locsAndSymbol;
  for (rapidjson::Value::ConstValueIterator itr = jsonBoard.Begin(); itr != jsonBoard.End(); itr++) {
    pair<int, int> currentLocation = std::make_pair(itr->FindMember("location")->value.GetArray()[0].GetInt(), itr->FindMember("location")->value.GetArray()[1].GetInt());

    string symbol = itr->FindMember("piece")->value.GetString();

    locsAndSymbol.push_back(std::make_pair(currentLocation, symbol));
  }
  fclose(file);

  board.reinitializeBoard(locsAndSymbol);

  playGame();

  return;
}

void Game::endGame(Player* winner) {
  if (winner == &player1) {
    output << "Checkmate. " << player1.getName() << "(White) wins!" << endl;
    return;
  }

  if (winner == &player2) {
    output << "Checkmate. " << player2.getName() << "(Black) wins!" << endl;
    return;
  }
}

void Game::quitGame() {
  char choice;
  output << "Are you sure you want to end the game?" << endl;
  output << "Enter 'Y' to confirm, or 'N' to continue playing: ";
  while (input >> choice) {
    if (choice == 'Y' || choice == 'y') {
      // Ask if the user wants to save the game before ending
      char saveChoice;
      output << "Do you want to save the game before ending? (Y/N): ";
      input >> saveChoice;
      if (saveChoice == 'Y' || saveChoice == 'y') {
        saveGame();
      }
      output << "Game ended. Thank you for playing!" << endl;
      break;
    } else if (choice == 'N' || choice == 'n') {
      playGame();
      break;
    } else {
      output << "Invalid choice. Please enter 'Y' or 'N'." << endl;
      output << "Are you sure you want to end the game?" << endl;
      output << "Enter 'Y' to confirm, or 'N' to continue playing: ";
    }
  }
}

string Game::convertGameToJson() {
  StringBuffer s;
  Writer<StringBuffer> writer(s);
  writer.StartObject();
  // game name
  writer.Key("gameName");
  writer.String(gameName.c_str());
  // player 1
  writer.Key("player1");
  writer.StartObject();

  writer.Key("name");
  writer.String(player1.getName().c_str());

  writer.Key("color");
  writer.String(PieceColorToString(player1.getColor()));

  writer.Key("currentPlayer");
  writer.Bool(currentPlayer->getName() == player1.getName());  // see if this works too

  writer.EndObject();

  // player 2
  writer.Key("player2");
  writer.StartObject();

  writer.Key("name");
  writer.String(player2.getName().c_str());

  writer.Key("color");
  writer.String(PieceColorToString(player2.getColor()));

  writer.Key("currentPlayer");
  writer.Bool(currentPlayer->getName() == player2.getName());

  writer.EndObject();

  // board
  writer.Key("board");

  writer.StartArray();
  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 8; j++) {
      if (board.getSquare(i, j)->getPiece() == nullptr) {
        continue;
      }
      writer.StartObject();

      // location of the piece in [row, column] formate
      writer.Key("location");
      writer.StartArray();
      writer.Int(i);
      writer.Int(j);
      writer.EndArray();

      // the type of piece as a char
      writer.Key("piece");
      const string pieceSymbol = board.getSquare(i, j)->getPiece()->getSymbol();
      writer.String(pieceSymbol.c_str());

      writer.EndObject();
    }
  }
  writer.EndArray();

  writer.EndObject();
  return s.GetString();
}

bool Game::saveGame() {
  string jsonGame = convertGameToJson();

  string fileName = "saves/" + gameName + ".json";
  ofstream file(fileName);

  if (file.is_open()) {
    file << jsonGame;
    file.close();
    output << "Game saved successfully!" << endl;
    return true;
  } else {
    output << "Unable to save game. Please try again." << endl;
    return false;
  }
}

void Game::askUserForMove() {
  output << "Enter position of piece you want to move (ex e5): " << endl;
  std::pair<int, int> fromCoordinate = getMoveCoordinateHelper();

  // check if there is a piece at the fromCoordinate that is the same color as the current player
  Square* fromSquare = board.getSquare(fromCoordinate.first, fromCoordinate.second);

  if (fromSquare->getPiece() == nullptr || (currentPlayer && fromSquare->getPiece()->getColor() != currentPlayer->getColor())) {
    output << endl << endl << "We are here!" << endl;
    output << "There is no piece at that location or it is not your piece. Please try again." << endl;
    askUserForMove();
    return;
  }

  output << "Choose position to move the piece to: " << endl;
  std::pair<int, int> toCoordinate = getMoveCoordinateHelper();

  bool res = board.updateBoard(fromCoordinate, toCoordinate);

  if (!res) {
    output << "Invalid move. Please try again." << endl;
    askUserForMove();
    return;
  }

  if (currentPlayer) {
    currentPlayer = player1.getName() == currentPlayer->getName() ? &player2 : &player1;
  }
}

std::pair<int, int> Game::getMoveCoordinateHelper() {
  string inputMove;
  std::pair<int, int> pair;
  while (input >> inputMove) {
    if (inputMove.size() == 2) {
      char inputChar = inputMove[0];
      char inputInt = inputMove[1];
      inputChar = toupper(inputChar);
      if (('A' <= inputChar && inputChar <= 'H')) {
        inputChar = inputChar - 16;
        if (inputInt >= 49 && inputInt <= 56) {
          pair.first = 7 - ((inputInt - '0') - 1);
          pair.second = (inputChar - '0') - 1;

          if (pair.first >= 0 && pair.first < 8 && pair.second >= 0 && pair.second < 8) {
            break;
          }
        }
      }
    }
    output << "Invalid Move! Please enter a valid position: " << endl;
  }
  return pair;
}