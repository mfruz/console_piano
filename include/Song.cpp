#include "Song.hpp"

// getters
const string &Song::s_getTitle() const {
    return s_title;
}

const string &Song::s_getComposer() const {
    return s_composer;
}

std::vector<Note> & Song::getScore() {
    return this->s_score;
}


// setters
void Song::s_setTitle(const string &s_title) {
    Song::s_title = s_title;
}
void Song::s_setComposer(const string &s_composer) {
    Song::s_composer = s_composer;
}

void Song::s_addNote(Note note) {
    this->getScore().push_back(note);
}

// DISPLAY FUNCTIONS
void Song::displayTitle() {
    std::cout << this->s_getTitle();
}
void Song::displayComposer() {
    std::cout << this->s_getComposer();
}
void Song::displaySongInfo() {
    displayTitle();
    std::cout << ", by ";
    displayComposer();
    std::cout << std::endl;
}