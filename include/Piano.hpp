#ifndef PIANO_HPP
#define PIANO_HPP
#include "Keyboard.hpp"
#include "Note.hpp"
#include "Song.hpp"
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

    void homeMenu();
    void p_play();
    void p_compose();
    void p_listen();


    // calls
    void callKeyboardPlay();

    Song initSong();
    string askTitle();
    string askComposer();
    bool askSaveSong();
    void saveSong(bool save);
    void addSongInfo(Song s);

    // display functions
    void home_message();
    void displayKeyboard();
    void displayChoices();
    void playMessage();
    void quitSession();
    void wrongMenuEntry();
    void warnQwerty();
    void whatNow();

    void composeMessage();

    // test functions
    void keyboardInit();
    string keyboardLayout();
    void checkMenuEntry();
    bool checkRange(char key);
};

#endif //PIANO_HPP
