#include <iostream>

#include "NeuralNet.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "creating network" << endl;

    NeuralNet net;
    const int N=1000000;
    cout << "creating " << N << " neurons" << endl;
    net.CreateNeurons(N);
    cout << "linking them with sinapses"  << endl;
    for (int i=0;i < 100; i++) {
        net.GrowSinapse(Index<Neuron>(i%N), Index<Neuron>((i+1) % N));
    }
    return 0;
}
