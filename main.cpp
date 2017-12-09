#include <iostream>
#include <windows.h>
#include <conio.h>
#include "include/Note.hpp"
#include "include/Keyboard.hpp"


int main(int argc, char *argv[]) {
    Note a = Note(440, 1000);
    Note b = Note(493.88, 500);
    Note c = Note(523.25, 500);
    Note d = Note(587.33, 500);
    Note e = Note(659.25, 500);
    Note f = Note(698.46, 500);
    Note g = Note(783.99, 500);
    Note a2 = Note(880, 500);
    Note silence = Note(0, 500);

    c.play();
    c.play();
    c.play();
    d.play();
    e.play();
    silence.play();
    d.play();
    silence.play();
    c.play();
    e.play();
    d.play();
    d.play();
    c.play();



    return 0;
}