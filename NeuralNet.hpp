#pragma once

#include "Neuron.hpp"
#include "Synapse.hpp"
#include "Queue.hpp"

#include <vector>

class NeuralNet {
public:
    Neuron &GetNeuron(Index<Neuron> ni) {
        return *neurons.at(ni.index);
    }
    Synapse &GetSynapse(Index<Synapse> si) {
        return *synapses.at(si.index);
    }

    void CreateNeurons(int k) {
        for (int i=0; i<=k ; i++)
            neurons.push_back(new Neuron());
    }

    void GrowSinapse(Index<Neuron> n1, Index<Neuron> n2) {
        synapses.push_back(new Synapse(GetNeuron(n1), GetNeuron(n2)));
    }

private:
    std::vector<Neuron *> neurons;
    std::vector<Synapse *> synapses;

    Queue<Index<Synapse> > fires;

};
