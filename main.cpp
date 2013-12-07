#include <iostream>

#include "NeuralNet.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "creating network";

    NeuralNet net;
    const int N=100;
    cout << "creating " << N << " neurons";
    net.CreateNeurons(N);
    cout << "linking them with sinapses";
    for (int i=0;i < 100; i++) {
        net.GrowSinapse(Index<Neuron>(i%N), Index<Neuron>((i+1) % N));
    }
    return 0;
}
