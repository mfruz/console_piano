#ifndef PIANO_HPP
#define PIANO_HPP
#include "KeyboardQW.hpp"
#include "Note.hpp"
#include <cstdio>
#include <iostream>


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
    void home_message();
    void displayChoices();
    void displayKeyboard();

    //keyboard layout detection
    void keyboardInit();
    string keyboardLayout();
};


#endif //PIANO_HPP
