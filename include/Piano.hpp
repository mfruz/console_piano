//
// Created by Pc on 12/12/2017.
//

#ifndef PIANO_HPP
#define PIANO_HPP
#include "Keyboard.hpp"
#include "Note.hpp"
#include <cstdio>
#include <iostream>

enum STATE {

};

class Piano {




public:
    Piano(){};
    void run();
    void p_open();
    void p_close();

    void p_play();
    void p_compose();
    void p_listen();


    // affichage
    void displayChoices();
    void displayKeyboard();
};


#endif //PIANO_HPP
