//
// Created by Pc on 05/12/2017.
//

#include "Keyboard.hpp"

std::map<char,Note> Keyboard::m_range =
{
    {'q', Note(2*220.000, 1000)},      // A3
    {'z', Note(233.082, 500)},     // A#3
    {'s', Note(246.942, 1000)},       // B3
    {'d', Note(261.626, 1000)},       // C4
    {'r', Note(277.183,500)},      // C#4
    {'f', Note(293.665, 1000)},       // D4
    {'t', Note(311.127,500)},      // D#4
    {'g', Note(329.628, 1000)},       // E4
    {'h', Note(349.228, 1000)},       // F4
    {'u', Note(369.994,500)},      // F#4
    {'j', Note(391.995, 1000)},       // G4
    {'i', Note(415.305,500)},      // G#4
    {'k', Note(440.000, 1000)},       // A4
    {'o', Note(466.164,500)},      // A#4
    {'l', Note(493.883, 1000)},       // B4
    {'m', Note(523.251, 1000)}        // C5
};

// getters
std::map<char, Note> &Keyboard::getRange() {
    return this->m_range;
};

const std::vector<double> &Keyboard::getFreqs() {
    return this->m_frequencies;
}



void Keyboard::transpose(int semitone) {
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