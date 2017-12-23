#ifndef PIANO_NOTE_HPP
#define PIANO_NOTE_HPP
#include <iostream>
#include <windows.h>
#include <cstring>

using std::string;

class Note {
protected:
    double m_frequency;
    int m_duration; // ms
    string allo = "mmm";

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



    void play() const;
};


#endif //PIANO_NOTE_HPP
