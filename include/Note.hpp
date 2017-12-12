//
// Created by Pc on 09/12/2017.
//

#ifndef PIANO_NOTE_HPP
#define PIANO_NOTE_HPP
#include <windows.h>

class Note {
protected:
    double m_frequency;
    int m_duration; // ms

public:
    //constructor
    Note(double m_frequency, int m_duration) : m_frequency(m_frequency), m_duration(m_duration) {
        m_duration = 500;
    }

    // getters
    double getFreq() const;
    int getDuration() const;

    // setters
    void setFreq(double freq);
    void setDuration(unsigned int duration);

    // play
    void play() const;
};


#endif //PIANO_NOTE_HPP
