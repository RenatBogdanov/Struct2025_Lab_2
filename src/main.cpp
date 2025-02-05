#include <iostream>
#include <fstream>
#include <vector>
#include <cstdint>
#include <string>

#include "game.h"

int main() {
    game::Game game;
    game::ReadFile read(game);
    game::RenderGame render(game);
    system("dot -Tpng -O graph.dot");

    std::cout << "Shutdown" << std::endl;

    return 0;
}