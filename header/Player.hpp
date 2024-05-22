#pragma once

#include <iostream>
#include <string>
#include <Piece.hpp>

using namespace std;

class Player {
private:
    string name;
    PieceColor color;

public:
    Player(PieceColor color, const string& name) : color(color), name(name) {};
    Player() : color(), name("") {};
    PieceColor getColor() {return color;}
    string getName(){ return name; }
};