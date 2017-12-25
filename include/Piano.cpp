#include "Piano.hpp"
#include <algorithm>

// ---------------------------------------------
enum choice {
    PLAY,
    COMPOSE,
    LOAD,
    CLOSE
};

static std::vector<char> homeLabel = {
        '1',
        '2',
        '3',
        'x'
};

/*bool isGoodLabel(char c) {
    for(int i = PLAY; i < CLOSE; i++) {
        if(homeLabel[i] == c) {
            return true;
        }
    }
    return false;
}*/

// ---------------------------------------------




void Piano::run() {

    // test keyboard layout
    this->keyboardInit();
    this->home_message();

    this->p_open();
}

void Piano::home_message() {
    std::cout << "==============================================================" << std::endl;
    std::cout << "------------------ C O N S O L E  P I A N O ------------------" << std::endl;
    std::cout << "==============================================================" << std::endl << std::endl;

    std::cout << "                    BE THE MOZART OF CODE                  " << std::endl;

    this->displayKeyboard();

    //std::cout << "            works with AZERTY and QWERTY keyboards         " << std::endl << std::endl;
}

void Piano::p_open() {
    this->displayChoices();
}

void Piano::displayChoices() {
    std::cout << "Play freely [" << homeLabel[PLAY] << "]"
            "  |  Compose song [" << homeLabel[COMPOSE] << "]"
                      "  |  Open score file [" << homeLabel[LOAD] << "]"
                      "  |  Close[" << homeLabel[CLOSE] << "]" << std::endl << std::endl;
    char choice;

    // working solution
    /*while(!isGoodlabel(choice)) {
        std::cin >> choice;
        std::cin.ignore();
    }*/

    // with an iterator
    do {
        std::cin >> choice;
        std::cin.ignore();
        if(std::find(homeLabel.begin(), homeLabel.end(), choice) == homeLabel.end()) {
            std::cout << "Please, enter a value that exists in the menu" << std::endl;
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
            this->p_close();
            break;
        default:
            break;
    }
}
void Piano::displayKeyboard() {
    std::cout << "          |  | | | |  |  | | | | | |  |  | | | |  |" << std::endl;
    std::cout << "          |  | | | |  |  | | | | | |  |  | | | |  |" << std::endl;
    std::cout << "          |  | | | |  |  | | | | | |  |  | | | |  |" << std::endl;
    std::cout << "          |  |_| |_|  |  |_| |_| |_|  |  |_| |_|  |" << std::endl;
    std::cout << "          |   |   |   |   |   |   |   |   |   |   |" << std::endl;
    std::cout << "          |   |   |   |   |   |   |   |   |   |   |" << std::endl;
    std::cout << "          |___|___|___|___|___|___|___|___|___|___|" << std::endl << std::endl;
}



void Piano::p_play() {
    std::cout << "==============================================================" << std::endl;
    std::cout << "                ~ now \"playing\" the piano ~                 " << std::endl;
    std::cout << "==============================================================" << std::endl;
    std::cout << "                                 Press [0] if you want to stop" << std::endl;

    k.k_play();
}

void Piano::p_compose() {

}

void Piano::p_listen() {

}

void Piano::p_close() {

}



// -----------------------------------------
// if user keyboard is qwerty, then redeclare object k as a KeyboardQW
void Piano::keyboardInit() {
    if(this->keyboardLayout() != "0000040C") {
        k.k_initRangeQW();
        std::cout << "| ! | THIS KEYBOARD IS QWERTY | ! |" << std::endl;
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