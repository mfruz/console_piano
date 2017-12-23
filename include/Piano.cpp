//
// Created by Pc on 12/12/2017.
//

#include "Piano.hpp"

void Piano::run() {
    static Keyboard k;
    std::cout << "==============================================================" << std::endl;
    std::cout << "------------------ C O N S O L E  P I A N O ------------------" << std::endl;
    std::cout << "==============================================================" << std::endl << std::endl;

    std::cout << "                    BE THE MOZART OF CODE                  " << std::endl;

    this->displayKeyboard();

    this->p_open();
}

void Piano::p_open() {
    this->displayChoices();
}

void Piano::displayChoices() {
    std::cout << "Play freely [1]  |  Compose song [2]  |  Open score file [3]  |  Close[x]" << std::endl << std::endl;
    int choice;
    std::cin >> choice;
    std::cin.ignore();

    switch(choice) {
        case 1:
            this->p_play();
            break;
        case 2:
            this->p_compose();
            break;
        case 3:
            this->p_listen();
            break;
        case 'x':
            this->p_close();
            break;
        default: 1;
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
    std::cout << " white keys go from 'q' to 'm', black keys go from 'z' to 'o' " << std::endl;
    std::cout << "==============================================================" << std::endl;
    std::cout << "                                 Press [0] if you want to stop" << std::endl;
}

void Piano::p_compose() {

}

void Piano::p_listen() {

}

void Piano::p_close() {

}