#include <iostream>
#include <istream>

#include "../header/Game.hpp"

using std::cin;
using std::cout;
using std::endl;
using std::stringstream;

int main() {
  Game game(cin, cout);
  game.startGame();
  return 0;
}