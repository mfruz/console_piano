#ifndef PIANO_SILENCE_HPP
#define PIANO_SILENCE_HPP


#include "Note.hpp"

class Rest: public Note {
public:
    Rest(int m_duration);

};


#endif //PIANO_SILENCE_HPP
