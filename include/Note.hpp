#ifndef PIANO_NOTE_HPP
#define PIANO_NOTE_HPP
#include <iostream>
#include <windows.h>
#include <vector>

enum noteLength {
    QUAVER = 250,
    CROTCHET = 500,
    MINIM = 1000,
    SEMIBREVE = 2000
};


class Note {
protected:
    double m_frequency;
    unsigned int m_duration = QUAVER; // ms

public:
    //constructor
    Note();
    Note(double m_frequency, int m_duration) : m_frequency(m_frequency), m_duration(m_duration) {
    }

    // getters
    double getFreq() const;
    unsigned int getDuration() const;

    // setters
    virtual void setFreq(double freq);
    void setDuration(unsigned int duration);
    void play() const;
};



#endif //PIANO_NOTE_HPP
