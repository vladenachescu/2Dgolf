#include "Game.h"
#include <iostream>
#include <string>

int main() {
    std::cout << "Nume jucator: ";
    std::string nume;
    std::cin >> nume;
    Game joc(nume);
    joc.start();
    std::cout << joc;
    return 0;
}
