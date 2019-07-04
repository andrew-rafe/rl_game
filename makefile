CXX = g++
CXXFLAGS = -g
main: main.o gridworld.o actionSpace.o network.o neuron.o
	$(CXX) $(CXXFLAGS) -o main main.o gridworld.o actionSpace.o network.o neuron.o
main.o: main.cpp gridworld.h ../snn/network.h
	$(CXX) $(CXXFLAGS) -c main.cpp
gridworld.o: gridworld.h actionSpace.hpp
actionSpace.o: actionSpace.hpp
network.o: ../snn/network.h ../snn/neuron.h ../snn/hyperparams_neuron.hpp
neuron.o: ../snn/neuron.o ../snn/hyperparams_neuron.hpp
hyperparams_neuron.o: ../snn/hyperparams_neuron.hpp
