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
    void composeAndPlay(Song &s);

    Song initSong();
    string addTitle();
    string addComposer();
    void askSaveSong(Song s);
    void saveSong(Song s);
    void addSongInfo(Song &s);

    string askFileName();

    // display functions
    void home_message();
    void displayKeyboard();
    void displayChoices();
    void playMessage();
    void quitSession();
    void wrongMenuEntry();
    void warnQwerty();
    void whatNow();
    void transposeMessage();
    void composeMessage();
    void listenMessage();

    // test functions
    void keyboardInit();
    string keyboardLayout();
    void checkMenuEntry();
};

#endif //PIANO_HPP
