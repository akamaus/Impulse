#include <iostream>

#include "NeuralNet.hpp"

using namespace std;

int main(int argc, char *argv[]) {
    cout << "creating network" << endl;

    NeuralNet net;
    const int N=1000000;
    cout << "creating " << N << " neurons" << endl;
    net.CreateNeurons(N);
    cout << "linking them with synapses"  << endl;
    for (int i=0;i < N; i++) {
        net.GrowSinapse(Index<Neuron>(i%N), Index<Neuron>((i+1) % N));
//        cerr << i << " ";
    }

    TimeQueue<int> q_test;
    q_test.Enqueue(10.0f, 10);
    q_test.Enqueue(30.0f, 30);
    q_test.Enqueue(50.0f, 50);
    q_test.Enqueue(20.0f, 20);

    for (int i=0; i<4; i++) {
        auto p = q_test.Dequeue();
        cout << p.second << endl;
    }

//    cout << q_test.Dequeue().second() << endl;
//    cout << q_test.Dequeue().second() << endl;

    return 0;
}
