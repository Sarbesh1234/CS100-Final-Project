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
    Player() : color(PieceColor::WHITE), name("") {};
    PieceColor getColor() {return color;}
    string getName(){ return name; }
    void setName(const string& name){ this->name = name; }
};