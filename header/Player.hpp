#pragma once

#include <iostream>
#include <string>

using namespace std;

class Player {
public:
    string name;
    string color;
    
    Player(const string& color, const string& name) : color(color), name(name) {};
    Player() : color(""), name("") {};
};