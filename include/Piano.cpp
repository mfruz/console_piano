#include "Piano.hpp"
#include <algorithm>
#include <conio.h>
#include <stdexcept>

// ---------------------------------------------
enum choice {
    PLAY,
    COMPOSE,
    LOAD,
    CLOSE
};

static int state;

const std::vector<char> homeLabel = {
        '1',
        '2',
        '3',
        'x'
};

// ---------------------------------------------




void Piano::run() {
    this->keyboardInit();
    this->home_message();
    this->p_open();
}

void Piano::p_open() {
    this->homeMenu();
}

void Piano::homeMenu() {
    this->displayChoices();
    this->checkMenuEntry();
}

void Piano::p_play(){
    state = PLAY;
    this->playMessage();
    this->callKeyboardPlay();
}

void Piano::p_compose() {
    state = COMPOSE;
    this->composeMessage();
    this->callKeyboardPlay();
    Song s = this->initSong();
    bool save = this->askSaveSong();
    this->saveSong(save);
    //this->addSongInfo(s);
}

void Piano::p_listen() {
    state = LOAD;

}


// CALLS
void Piano::callKeyboardPlay() {
    char note;

    do {
        note = getch();
        if(note == '0'){
            std::cout << std::endl << std::endl;
            if(state == PLAY) {
                this->quitSession();
            }
            else return;
        }
        try {
            k.k_play(note);
        }
        catch(const std::out_of_range&) {
            // ignore
        }
    }
    while(note != '0');
}



// CHECK AND TEST FUNCTIONS ----------------------------------------------
void Piano::keyboardInit() {
    if(this->keyboardLayout() != "0000040C") {
        k.k_initRangeQW();
        this->warnQwerty();
    }
    else k.k_initRange();

    k.k_initNotes();
}

string Piano::keyboardLayout() {
    TCHAR szKeyboard[KL_NAMELENGTH];
    GetKeyboardLayoutName(szKeyboard);
    string kbLayout = szKeyboard;
    return kbLayout;
}

void Piano::checkMenuEntry() {
    char choice;
    // with an iterator
    do {
        choice = getch();
        if(std::find(homeLabel.begin(), homeLabel.end(), choice) == homeLabel.end()) {
            this->wrongMenuEntry();
        }
    }
    while(std::find(homeLabel.begin(), homeLabel.end(), choice) == homeLabel.end());

    switch(choice) {
        case '1':
            this->p_play();
            break;
        case '2':
            this->p_compose();
            break;
        case '3':
            this->p_listen();
            break;
        case 'x':
            return;
        default:
            break;
    }
}


// DISPLAY FUNCTIONS -----------------------------------------------------
void Piano::home_message() {
    std::cout << "==============================================================" << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    this->displayKeyboard();
    std::cout << "------------------- BE THE MOZART OF CODE --------------------" << std::endl << std::endl;



    //std::cout << "            works with AZERTY and QWERTY keyboards         " << std::endl << std::endl;
}

void Piano::displayKeyboard() {
    std::cout << "          |  | | | |  |  | | | | | |  |  | | | |  |" << std::endl;
    std::cout << "          |  | | | |  |  | | | | | |  |  | | | |  |" << std::endl;
    std::cout << "          |  | |                             | |  |" << std::endl;
    std::cout << "          |  | |  C O N S O L E  P I A N O   | |  |" << std::endl;
    std::cout << "          |  | |                             | |  |" << std::endl;
    std::cout << "          |  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |" << std::endl;
    std::cout << "          |   |   |   |   |   |   |   |   |   |   |" << std::endl;
    std::cout << "          |   |   |   |   |   |   |   |   |   |   |" << std::endl;
    std::cout << "          |___|___|___|___|___|___|___|___|___|___|" << std::endl << std::endl;
}

void Piano::displayChoices() {
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "Play freely [" << homeLabel[PLAY] << "]"
            "  |  Compose song [" << homeLabel[COMPOSE] << "]"
                      "  |  Open score file [" << homeLabel[LOAD] << "]"
                      "  |  Close[" << homeLabel[CLOSE] << "]" << std::endl << std::endl;
}

void Piano::wrongMenuEntry() {
    std::cout << "Please, enter a value that exists in the menu" << std::endl;
}

void Piano::playMessage() {
    std::cout << "==============================================================" << std::endl;
    std::cout << "                ~ now \"playing\" the piano ~                 " << std::endl;
    std::cout << "==============================================================" << std::endl;
    std::cout << "                                 Press [0] if you want to stop" << std::endl;

    //k.k_play();
}

void Piano::quitSession() {
    this->whatNow();
    this->p_open();
}

void Piano::whatNow() {
    std::cout << std::endl;
    std::cout << "." << std::endl << "." << std::endl << "." << std::endl << "." << std::endl << "." << std::endl;
    std::cout << "--------------------------------------------------------------" << std::endl;
    std::cout << "- - - - - - - - What do you want to do now ? - - - - - - - - -" << std::endl;
}

void Piano::warnQwerty() {
    std::cout << "| ! | THIS KEYBOARD IS QWERTY | ! |" << std::endl;
}


void Piano::composeMessage() {
    std::cout << std::endl << std::endl;
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    std::cout << "~ - - - - - - - - - MOZART MODE: ACTIVATED - - - - - - - - - ~" << std::endl;
}


// SONG FUNCTIONS

Song Piano::initSong() {
    Song s;
    return s;
}


string Piano::askTitle() {
    string title;
    std::cout << "Choose a title for your song :" << std::endl;
    std::getline(std::cin, title);
    std::cout << "Title : " << title << std::endl;

    return title;
}
string Piano::askComposer() {
    string composer;
    std::cout << "Who composed this song ?" << std::endl;
    std::getline(std::cin, composer);
    std::cout << "Composer : " << composer << std::endl;
    return composer;
}

bool Piano::askSaveSong() {
    std::cout << "Do you want to save your song ? [y/n]" << std::endl;
    char choice;
    while(choice != 'y' && choice != 'n') {
        choice = getch();
    }
    switch(choice) {
        case 'y':
            return 1;
        case 'n':
            return 0;
    }
}

void Piano::saveSong(bool save) {

}

void Piano::addSongInfo(Song s) {
    s.s_setTitle(this->askTitle());
    s.s_setComposer(this->askComposer());
}