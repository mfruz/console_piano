#ifndef PIANO_KEYBOARD_HPP
#define PIANO_KEYBOARD_HPP

#include <map>
#include <vector>
#include <cstring>
#include "Note.hpp"

using std::string;


class Keyboard {
protected:
    std::map<char, Note> k_range;

    // vector of all useful frequencies
    std::map<double, string> k_noteNames;


public:
    // getters
    std::map<char, Note> k_getRange() const;
    std::map<double, string> k_getNoteNames() const;

    // browsing and display
    void k_browseNotes() const;


    // constructor
    Keyboard() {};
    void k_initNotes();
    void k_initRange();
    void k_initRangeQW();


    // methods
    void k_play(char note);
    void k_displayNote(char key);
    void k_transpose(int semitone);
};


#endif //PIANO_KEYBOARD_HPP
