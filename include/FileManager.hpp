#ifndef PIANO_FILEMANAGER_HPP
#define PIANO_FILEMANAGER_HPP

#include <iostream>
#include <fstream>
#include <cstring>
#include "Song.hpp"
#include "Keyboard.hpp"
#include "Note.hpp"

using std::string;

class FileManager {
protected:
    std::fstream file;
    string fileName;
    static string path;
    static string format;


public:
    FileManager() = default;
    //~FileManager() = default;

    // getters
    std::fstream & getFile();
    string getPath() const ;
    string getFormat() const;
    string getFileName() const;

    // setters
    void setFileName(const string &fileName);
    void setPath(const string &path);

    bool load();
    void read();
    void write(Song s);
    void close();

    unsigned int convertDurationFormat(unsigned int ms);

    // display functions
    void displayLoadError();

};


#endif //PIANO_FILEMANAGER_HPP
