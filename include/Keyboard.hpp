#ifndef PIANO_KEYBOARD_HPP
#define PIANO_KEYBOARD_HPP
#include <map>
#include <vector>
#include "Note.hpp"
// idées pour les templates -> puisque l'opérateur [] ne marche pas avec la map, créer un itérator
// avec le [] au lieu de faire at() à chaque fois


class Keyboard {
private:
    static std::map<char, Note> k_range;

    // vector of all useful frequencies
    static std::map<double, string> k_noteNames;


public:
    // getters
    std::map<char, Note> &k_getRange() const;
    std::map<double, string> k_getNoteNames() const;

    // browsing and display
    void k_browseNotes() const;


    // constructor
    Keyboard() {};

    // methods
    void k_play();
    void k_displayNote(char key);


    void k_transpose(int semitone);


};


#endif //PIANO_KEYBOARD_HPP
