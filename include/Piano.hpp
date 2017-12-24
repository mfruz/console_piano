#ifndef PIANO_HPP
#define PIANO_HPP
#include "Keyboard.hpp"
#include "Note.hpp"
#include <cstdio>
#include <iostream>


class Piano {
protected:
    Keyboard k;

public:
    Piano(){};
    void run();
    void p_open();
    void p_close();

    void p_play();
    void p_compose();
    void p_listen();


    // affichage
    void home_message();
    void displayChoices();
    void displayKeyboard();

    //keyboard layout detection
    void keyboardInit();
    string keyboardLayout();
};


#endif //PIANO_HPP
