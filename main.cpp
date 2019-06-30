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
    std::vector<int> state;
    bool done = false;
    int total_reward, curr_reward = 0;
    while (!done) {
        state = game->step(game->action_space.sample(), curr_reward, done);
        total_reward += curr_reward;
        game->print_game_board();
    }

    std::cout << "Total Reward: " << std::endl;

    delete game;

    return EXIT_SUCCESS;
} 

