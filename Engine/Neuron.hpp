#pragma once

#include <list>

#include "ImpTypes.hpp"
#include "Temporal.hpp"

class NeuralNet;
class Synapse;

class NeuronTemporalParams {
public:
    static constexpr Potential eq() {
        return -70;
    }
    static constexpr Potential speed() {
        return 0.001;
    }
    static constexpr Potential action_potential() {
        return -50;
    }
};

class Neuron {
public:
    Neuron() {}
    void Exite(NeuralNet &net, Potential imp);

    Potential GetPotential() const;
    void AddInputSynapse(const Index<Synapse> &si) {
        input_synapses.push_back(si);
    }
    void AddOutputSynapse(const Index<Synapse> &si) {
        output_synapses.push_back(si);
    }

private:
    Temporal<Potential, NeuronTemporalParams> level;
    std::list<Index<Synapse>> input_synapses, output_synapses;
};
