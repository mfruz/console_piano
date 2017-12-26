#include "Note.hpp"

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
