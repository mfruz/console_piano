#ifndef PIANO_SONG_HPP
#define PIANO_SONG_HPP

#include <vector>
#include <string>
#include "Note.hpp"

using std::string;

class Song {
private:
    string s_title;
    string s_composer;
    std::vector<Note> s_score;

public:
    // getters
    const string &s_getTitle() const;
    const string &s_getComposer() const;
    /*string s_getTitle();
    string s_getDuration();
    string s_getComposer();*/
    std::vector<Note>& getScore();

    // setters
    void s_setTitle(const string &s_title);
    void s_setComposer(const string &s_composer);

    /*void s_setTitle(string title);
    void s_setDuration(string duration);
    void s_setComposer(string composer);*/
    void s_addNote(Note note);


    void displayTitle();
    void displayDuration();
    void displayComposer();
    void displaySongInfo();




};


#endif //PIANO_SONG_HPP
