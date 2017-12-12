#include <iostream>
#include <conio.h>
#include "include/Note.hpp"
#include "include/Keyboard.hpp"



int main() {
    Keyboard k;
    Note a = k.getRange().at('q');
    Note b = Note(493.88, 500);
    Note silence = Note(0, 500);

    a.play();


    k.getRange().at(getch()).play();

    return 0;
}