using namespace std;
#include <istream>
#include <ostream>
#include "Player.hpp"

class Game {
    private:
    Player player1;
    Player player2;
    string gameName;
    //Board board;
    Player* currentPlayer;
    istream& input;
    ostream& output;

    public: 
        Game(istream& input, ostream& output) 
        : input(input), output(output), player1(Player("White", "Player 1")), 
        player2(Player("Black", "Player 2")), currentPlayer(&player1)
        {};
        void startGame();
        void startNewGame();
        void loadSavedGame();
        void endGame();
        void saveGame();
        void askUserForMove();
};