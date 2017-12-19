//
// Created by Pc on 05/12/2017.
//

#ifndef PIANO_KEYBOARD_HPP
#define PIANO_KEYBOARD_HPP
#include <map>
#include <vector>
#include "Note.hpp"

class Keyboard {
private:
    static std::map<char, Note> m_range;

protected:
    // vector of all useful frequencies
    const std::vector<double> m_frequencies = {
            220.000, // A3
            233.082, // A#3
            246.942, // B3
            261.626, // C4
            277.183, // C#4
            293.665, // D4
            311.127, // D#4
            329.628, // E4
            349.228, // F4
            369.994, // F#4
            391.995, // G4
            415.305, // G#4
            440.000, // A4
            466.164, // A#4
            493.883, // B4
            523.251  // C5
    };


public:
    // getters
    std::map<char, Note> &getRange();
    const std::vector<double> &getFreqs();

    // constructor
    Keyboard() {};


    //transpose
    void transpose(int semitone);
};


#endif //PIANO_KEYBOARD_HPP
