//
// Created by Pc on 05/12/2017.
//

#ifndef PIANO_KEYBOARD_HPP
#define PIANO_KEYBOARD_HPP
#include <map>
#include "Note.hpp"

class Keyboard {
protected:
    std::map<int, Note> range;

public:
    // constructor
    Keyboard();
};


#endif //PIANO_KEYBOARD_HPP
