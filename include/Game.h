#pragma once
#include "Level.h"
#include <iostream>
#include <vector>
#include <string>// <--- NECESAR PENTRU VECTOR

class Game {
private:
    std::string numeJucator;
    std::vector<Level> nivele;
    int scor;

public:

    explicit Game(std::string  numeJucator);
    void start();
    void adaugaNivel(const Level& nivel);
    void afiseazaScorFinal() const;

    friend std::ostream& operator<<(std::ostream& os, const Game& game);
};