#include <iostream>
#include <ctime>
#include <string>
#include <vector>

#include "gridworld.h"
#include "../snn/network.h"

int main(int argc, char* argv[]) {
    //Seed randomness
    srand(time(0));

    //Create a new game
    int width = 3;
    int height = 3;
    rl_game::Gridworld* game = new rl_game::Gridworld(width, height);

    //Create a new network
    std::cout << "Generating Network" << std::endl;
    std::vector<int> neurons_per_layer = {width * height, int(game->action_space.size())};
    SNN::Network* network = new SNN::Network(neurons_per_layer.size(), neurons_per_layer);
    std::cout << "Network Generated!" << std::endl;


    for (int i = 0; i < 10; i++) {
        game->print_game_board();
        std::vector<float> state = game->get_state();
        bool done = false;
        int total_reward = 0;
        int curr_reward = 0;
        long long timestep = 0;
        while (!done && timestep < 30) {
            //process the inputs in the network
            //For the first iteration it needs to populate the network so will run
            //for multiple timesteps before taking its first action
            if (timestep == 0) {
                for (int i = 0; i < 20; i++) {
                    network->process_inputs(state, timestep, state.size());
                    timestep++;
                }
            } else {
                network->process_inputs(state, timestep, state.size());
            }
            
            int action = network->get_action();
            std::cout << "Action: " << action << std::endl;
            state = game->step(action, curr_reward, done);
            total_reward += curr_reward;
            game->print_game_board();
            timestep++;

            
        }
        std::cout << "Total Reward: " << total_reward << std::endl;
        //Process all the learning based off of this one trial
        std::cout << "LEARNING" << std::endl;
        network->process_training(total_reward);
        std::cout << "LEARNING FINISHED" << std::endl;
        //Start a new game
        std::cout << "STARTING NEW GAME ---------------------" << std::endl;
        game->new_game();
    }
    
    delete game;
    delete network;

    return EXIT_SUCCESS;
} 

