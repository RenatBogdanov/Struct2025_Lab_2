#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <string>

#include <graphviz/cgraph.h>
#include <graphviz/gvc.h>
#include "game.h"

int main() {
    game::RenderGame renderGame; // Создание объекта RenderGame
    game::Game game; // Создание объекта Game
    game::Node node; // Создание объекта Node
    game::ReadFile read(game);
    std::cout << "End game" << std::endl;

    


    return 0;
}