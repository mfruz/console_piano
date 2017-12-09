//
// Created by Pc on 09/12/2017.
//

#ifndef PIANO_NOTE_HPP
#define PIANO_NOTE_HPP
#include <windows.h>

class Note {
protected:
    int m_frequency;
    int m_duration; // ms

public:
    //constructor
    Note(int m_frequency, int m_duration) : m_frequency(m_frequency), m_duration(m_duration) {}

    // getters
    int getFreq() const;
    int getDuration() const;

    // setters
    void setFreq(unsigned int freq);
    void setDuration(unsigned int duration);

    // play
    void play() const;

    //transpose
    void transpose(int semiTone);
};


#endif //PIANO_NOTE_HPP
