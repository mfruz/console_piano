#include "../include/Note.hpp"
Note::Note() {}
Note::Note(double m_frequency, unsigned int m_duration) : m_frequency(m_frequency), m_duration(m_duration) {}


// getters
double Note::getFreq() const {
    return this->m_frequency;
}
unsigned int Note::getDuration() const {
    return this->m_duration;
}


// setters
void Note::setFreq(double freq) {
    this->m_frequency = freq;
}
void Note::setDuration(unsigned int duration) {
    this->m_duration = duration;
}

void Note::play() {
    Beep(this->m_frequency, this->m_duration);
}

// pre-fix
Note& Note::operator++() {
    m_frequency *= 1.059463;
    return *this;
}

Note& Note::operator--() {
    m_frequency -= 1.059463;
    return *this;
}



