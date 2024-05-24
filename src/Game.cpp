#include "../header/Game.hpp"

#include <cctype>

#include "../header/Board.hpp"

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
  string gameInput;
  output << "Please enter your game name: ";
  input >> gameName;
  output << "Please enter Player 1's name: ";
  input >> player1name;
  player1 = Player(PieceColor::WHITE, player1name);
  output << "Please enter Player 2's name: ";
  input >> player2name;
  player2 = Player(PieceColor::BLACK, player2name);

  output << "Enter \"quit\" to end the game." << endl;
  while (input >> gameInput) {
    if (gameInput == "quit") {
      break;
      quitGame();
    } else if (gameInput != "quit") {
      askUserForMove();
    }
  }
}

void Game::loadSavedGame() {
  output << "What game would you like to load?" << endl;
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
    }

    else if (choice == 'N' || choice == 'n') {
      askUserForMove();
      break;
    }

    else {
      output << "Invalid choice. Please enter 'Y' or 'N'." << endl;
      output << "Are you sure you want to end the game?" << endl;
      output << "Enter 'Y' to confirm, or 'N' to continue playing: ";
    }
  }
}

void Game::saveGame() {
}

void Game::askUserForMove() {
  output << "Enter position of piece you want to move: " << endl;
  std::pair<int, int> toCoordinate = getMoveCoordinateHelper();
  output << "Choose position to move piece to: " << endl;
  std::pair<int, int> fromCoordinate = getMoveCoordinateHelper();
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
          pair.first = inputChar - '0';
          pair.second = inputInt - '0';
          break;
        }
      }
    }
    output << "Invalid Move! Please enter a valid position: " << endl;
  }
  return pair;
}