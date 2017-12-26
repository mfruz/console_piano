#include "Song.hpp"

// getters
string Song::s_getTitle() const {
    return this->s_title;
}
double Song::s_getDuration() const {
    return this->s_duration;
}
string Song::s_getComposer() const {
    return this->s_composer;
}
std::vector<Note> Song::getScore() const {
    return this->s_score;
}


// setters
void Song::s_setTitle(string title) {
    this->s_title = title;
}
void Song::s_setDuration(double duration) {
    this->s_duration = duration;
}
void Song::s_setComposer(string composer) {
    this->s_composer = composer;
}
void Song::s_addNote(Note note) {
    this->getScore().push_back(note);
}



// DISPLAY FUNCTIONS
void Song::displayTitle() const {
    std::cout << this->s_getTitle();
}
void Song::displayDuration() const {
    std::cout << this->s_getDuration();
}
void Song::displayComposer() const {
    std::cout << this->s_getComposer();
}
void Song::displaySongInfo() const {
    displayTitle();
    std::cout << ", by ";
    displayComposer();
    std::cout << " | ";
    displayDuration();
    std::cout << std::endl;
}