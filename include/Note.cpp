//
// Created by Pc on 09/12/2017.
//

#include "Note.hpp"

// constructor


// getters
int Note::getFreq() const {
    return this->m_frequency;
}
int Note::getDuration() const {
    return this->m_duration;
}

// setters
void Note::setFreq(unsigned int freq) {
    this->m_frequency = freq;
}
void Note::setDuration(unsigned int duration) {
    this->m_duration = duration;
}

void Note::play() const {
    Beep(this->m_frequency, this->m_duration);
}

void Note::transpose(int semiTone) {
    this->m_frequency *= 1/12*semiTone;
}
