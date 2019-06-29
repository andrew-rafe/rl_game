#include <iostream>
#include <ctime>
#include <string>
#include <vector>

#include "gridworld.h"

int main(int argc, char* argv[]) {
    //Seed randomness
    srand(time(0));

    //Create a new game
    rl_game::Gridworld* game = new rl_game::Gridworld(10,10);
    game->print_game_board();

    delete game;

    return EXIT_SUCCESS;
} 

