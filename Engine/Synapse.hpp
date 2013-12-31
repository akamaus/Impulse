#pragma once

#include "ImpTypes.hpp"
#include "Temporal.hpp"

class Neuron;

class SynapseActivityParams {
public:
    static Potential eq() {
        return 0;
    }
    static Potential speed() {
        return 0.1;
    }
};

class SynapseConductivityParams {
public:
    static Potential eq() {
        return 0;
    }
    static Potential speed() {
        return 0.1;
    }
};

class NeuralNet;
class Synapse {
public:
    Synapse(NeuralNet &net, const Index<Synapse> &s, const Index<Neuron> &n1, const Index<Neuron> &n2);
    Time GetDelay() const {
        return delay;
    }
    void Fire(NeuralNet &net);
private:
    Time delay;
    const Index<Neuron> &source, &target;

    Temporal<Potential, SynapseConductivityParams> conductivity; // эффективность проведения импульса
    Temporal<double, SynapseActivityParams> activity; // уровень готовности к пластической перестройке
};
