#include "FileManager.hpp"

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



bool FileManager::load() {
    this->getFile().open(this->getPath()+this->getFileName(), std::fstream::in | std::fstream::out | std::fstream::app);
    return this->getFile().is_open();
}

void FileManager::read() {

}


void FileManager::write(Song s) {
    /*string fileName;
    std::cout << "FILE NAME : " << std::endl;
    std::getline(std::cin, fileName);*/
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