#include "Keyboard.hpp"
#include <conio.h>

// vector of all useful frequencies
void Keyboard::k_initNotes() {
    Keyboard::k_noteNames =
    {
        {220.000, "A"},     // A3
        {233.082, "A#"},    // A#3
        {246.942, "B"},     // B3
        {261.626, "C"},     // C4
        {277.183, "C#"},    // C#4
        {293.665, "D"},     // D4
        {311.127, "D#"},    // D#4
        {329.628, "E"},     // E4
        {349.228, "F"},     // F4
        {369.994, "F#"},    // F#4
        {391.995, "G"},     // G4
        {415.305, "G#"},    // G#4
        {440.000, "A"},     // A4
        {466.164, "A#"},    // A#4
        {493.883, "B"},     // B4
        {523.251, "C"}      // C5
    };
}


void Keyboard::k_initRange() {
    this->k_range =
    {
        {'q', Note(220.000, 250)},     // A3
        {'z', Note(233.082, 250)},      // A#3
        {'s', Note(246.942, 250)},     // B3
        {'d', Note(261.626, 250)},     // C4
        {'r', Note(277.183, 250)},       // C#4
        {'f', Note(293.665, 250)},     // D4
        {'t', Note(311.127, 250)},       // D#4
        {'g', Note(329.628, 250)},     // E4
        {'h', Note(349.228, 250)},     // F4
        {'u', Note(369.994, 250)},       // F#4
        {'j', Note(391.995, 250)},     // G4
        {'i', Note(415.305, 250)},       // G#4
        {'k', Note(440.000, 250)},     // A4
        {'o', Note(466.164, 250)},       // A#4
        {'l', Note(493.883, 250)},     // B4
        {'m', Note(523.251, 250)}      // C5
    };
}

void Keyboard::k_initRangeQW() {
    this->k_range =
            {
                    {'a', Note(220.000, 250)},     // A3
                    {'w', Note(233.082, 250)},      // A#3
                    {'s', Note(246.942, 250)},     // B3
                    {'d', Note(261.626, 250)},     // C4
                    {'r', Note(277.183, 250)},       // C#4
                    {'f', Note(293.665, 250)},     // D4
                    {'t', Note(311.127, 250)},       // D#4
                    {'g', Note(329.628, 250)},     // E4
                    {'h', Note(349.228, 250)},     // F4
                    {'u', Note(369.994, 250)},       // F#4
                    {'j', Note(391.995, 250)},     // G4
                    {'i', Note(415.305, 250)},       // G#4
                    {'k', Note(440.000, 250)},     // A4
                    {'o', Note(466.164, 250)},       // A#4
                    {'l', Note(493.883, 250)},     // B4
                    {';', Note(523.251, 250)}      // C5
            };
}


// getters
std::map<char, Note> Keyboard::k_getRange() const {
    return this->k_range;
};
std::map<double, string> Keyboard::k_getNoteNames() const {
    return this->k_noteNames;
};



// browsing and display
void Keyboard::k_browseNotes() const {
    for (auto &it : this->k_getNoteNames())
        std::cout << " [" << it.first << ':' << it.second << ']' << std::endl;
}


void Keyboard::k_play(char note) {
        this->k_displayNote(note);
        this->k_getRange().at(note).play();
}


void Keyboard::k_displayNote(char key) {
    double freq = this->k_getRange().at(key).getFreq();
    //std::cout << freq << std::endl;
    std::cout << "["<<  this->k_getNoteNames().at(freq) << "] ";
}

void Keyboard::k_transpose(int semitone) {
    if(semitone == 12) {
        //parcourir tableau et faire valeur[i]*2
    }
    else if(semitone < 0) {
        // parcourir tableau et faire une boucle for sur chaque valeur
        /*for (int i = 0; i < abs(semitone); i++)
        {
            setFreq(this->m_frequency /= 1.059475);
        }*/
    }
    else
    {
        // parcourir tableau et faire boucle for sur chaque valeur
        /*for(int i = 0; i < semitone; i++)
        {
            setFreq(this->m_frequency *= 1.059475); // 1.059 is * coefficient btw 2 semitones
        }*/
    }
}


