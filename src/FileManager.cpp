#include <conio.h>
#include "../include/FileManager.hpp"
#include "../include/Rest.hpp"

const std::vector<size_t> noteDuration = {
        4,
        3,
        2,
        1
};

string FileManager::path = "../include/songs/";
string FileManager::format = ".txt";


// getters
std::fstream& FileManager::getFile() {
    return this->file;
}

string FileManager::getPath() const {
    return this->path;
}

string FileManager::getFormat() const {
    return this->format;
}

string FileManager::getFileName() const {
    return this->fileName;
}

// setters
void FileManager::setFileName(const string &fileName) {
    this->fileName = fileName;
}
void FileManager::setPath(const string &path) {
    this->path = path;
}


unsigned int FileManager::convertDurationFormat(unsigned int ms) {
    switch(ms) {
        case QUAVER:
            return 4;
        case CROTCHET:
            return 3;
        case MINIM:
            return 2;
        case SEMIBREVE:
            return 1;
    }
}

unsigned int FileManager::convertFormatDuration(unsigned int time) {
    switch(time) {
        case 4:
            return QUAVER;
        case 3:
            return CROTCHET;
        case 2:
            return MINIM;
        case 1:
            return SEMIBREVE;
    }
}



bool FileManager::load() {
    this->getFile().open(this->getPath()+this->getFileName()+this->getFormat(),
                         std::ios::in);
    return this->getFile().is_open();
}

void FileManager::read() {
//    this->getFile().open(this->getPath()+this->getFileName()+this->getFormat(),
//                         std::ios::in);
    Keyboard k;
    k.k_initNotes();
    Song s;
    string line;
    string note;
    unsigned int duration;
    this->getFile().seekg(0);
    std::cout << " < --------------------- NOW PLAYING ---------------------- > " << std::endl;

    while(!this->getFile().eof()) {
        std::getline(this->getFile(), line);
        std::istringstream iss;
        iss.str(line);
        iss >> note >> duration;

        for (auto &it : k.k_getNoteNames()) {

             if(note == it.second) {
                 double ms = this->convertFormatDuration(duration);
                 Note n = Note(it.first, ms);

                 n.play();
                 break;
             }
            else if (note == "0") {
                 double ms = this->convertDurationFormat(duration);
                 Rest r(duration) ;

                 r.play();
                 break;
             }
            else {
                 this->wrongMusicFormat();
                 return;
             }
        }
    }
}


void FileManager::write(Song s) {
    std::ofstream outfile(this->getPath()+s.s_getTitle()+this->getFormat());

    Keyboard k;
    k.k_initNotes();

    outfile << "Title : " << s.s_getTitle() << "\n";
    outfile << "Composer : " << s.s_getComposer() << "\n";
    for(unsigned int i = 0; i < s.getScore().size(); i++) {
        double freq = s.getScore().at(i).getFreq();
        unsigned int duration = this->convertDurationFormat(s.getScore().at(i).getDuration());
        outfile << k.k_getNoteNames().at(freq) << " " << duration << "\n";
    }
    outfile.close();
}

void FileManager::close() {
    this->getFile().close();
}

void FileManager::displayLoadError() {
    std::cout << "Couldn't load song, try again" << std::endl;
}

void FileManager::wrongMusicFormat() {
    std::cout << "This file format can't be read" << std::endl;
}