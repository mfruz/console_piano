#ifndef PIANO_SONG_HPP
#define PIANO_SONG_HPP

#include <vector>
#include <string>
#include "Note.hpp"

using std::string;

class Song {
private:
    string s_title;
    double s_duration;
    string s_composer;
    std::vector<Note> s_score;

public:
    // getters
    string s_getTitle() const;
    double s_getDuration() const;
    string s_getComposer() const;
    std::vector<Note> getScore() const;

    // setters
    void s_setTitle(string title);
    void s_setDuration(double duration);
    void s_setComposer(string composer);
    void s_addNote(Note note);


    void displayTitle() const;
    void displayDuration() const;
    void displayComposer() const;
    void displaySongInfo() const;
};


#endif //PIANO_SONG_HPP
