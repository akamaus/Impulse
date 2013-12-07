#pragma once

#include "Neuron.hpp"
#include "Sinapse.hpp"

class NeuralNet {
public:
    Neuron &GetNeuron(Index<Neuron> ni) {
        return *neurons.at(ni.index);
    }
    Synapse &GetSynapse(Index<Synapse> si) {
        return *synapses.at(si.index);
    }

    void CreateNeurons(int k) {
        for (i=0; i<=k ; i++)
            neurons.push_back(new Neuron());
    }

    void CreateSinapse(Index<Neuron> n1, Index<Neuron> n2) {
        sinapses.push_back(GetNeuron(n1), GetNeuron n2);
    }

private:
    std::vector<Neuron *> neurons;
    std::vector<Sinapse *> sinapses;

    Queue<SinapseIndex> fires;

}
