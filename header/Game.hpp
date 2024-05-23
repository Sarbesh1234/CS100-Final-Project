using namespace std;
#include <istream>
#include <ostream>
#include "Player.hpp"

class Game {
    private:
    Player* currentPlayer;
    istream& input;
    ostream& output;
    std::pair<int,int> getMoveCoordinateHelper(istream& input,ostream& output);    

    public: 
        Game(istream& input, ostream& output) 
        : input(input), output(output)
        {};
        void startGame();
        void startNewGame();
        void loadSavedGame();
        void endGame();
        void saveGame();
        void askUserForMove();
};