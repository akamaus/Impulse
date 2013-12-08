#pragma once

#include <list>

#include "ImpTypes.hpp"

#include "Temporal.hpp"

class Synapse;

class NeuronTemporalParams {
public:
    static Potential eq() {
        return -70;
    }
    static Potential speed() {
        return 0.001;
    }
};

class Neuron {
public:
    Neuron() {}
    void Exite(Potential imp);

    Potential GetPotential() const;
    void AddInputSynapse(Synapse &s) {
        input_synapses.push_back(&s);
    }
    void AddOutputSynapse(Synapse &s) {
        output_synapses.push_back(&s);
    }

private:
    Temporal<Potential, NeuronTemporalParams> level;
    std::list<Synapse *> input_synapses, output_synapses;
};
