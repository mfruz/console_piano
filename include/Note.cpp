//
// Created by Pc on 09/12/2017.
//

#include "Note.hpp"

// constructor


// getters
double Note::getFreq() const {
    return this->m_frequency;
}
int Note::getDuration() const {
    return this->m_duration;
}

// setters
void Note::setFreq(double freq) {
    this->m_frequency = freq;
}
void Note::setDuration(unsigned int duration) {
    this->m_duration = duration;
}

void Note::play() const {
    Beep(this->m_frequency, this->m_duration);
}

void Note::transpose(int semitone) {
    if(semitone == 12) {
        setFreq(this->m_frequency*2);
    }
    else if(semitone < 0)
    {
        for (int i = 0; i < abs(semitone); i++)
        {
            setFreq(this->m_frequency /= 1.059475);
        }
    }
    else
    {
        for(int i = 0; i < semitone; i++)
        {
            setFreq(this->m_frequency *= 1.059475); // 1.059 is * coefficient btw 2 semitones
        }
    }
}
