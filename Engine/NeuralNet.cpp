#include "NeuralNet.hpp"

bool NeuralNet::Tick() {
    if (fires.empty()) {
        return false;
    }

    auto event = fires.Dequeue();
    time = event.first;
    Synapse &syn = GetSynapse(event.second);
    syn.Fire(*this);

    return true;
}
