#pragma once

#include "ImpTypes.hpp"
#include "Temporal.hpp"

class Neuron;

// Параметры пластичности синапса
class SynapseActivityParams {
public:
    static Potential starting() {
        return 0;
    }
    static Potential eq() {
        return 0;
    }
    static Potential speed() {
        return 0.1;
    }
};

// Параметры проводимости синапса
class SynapseConductivityParams {
public:
    static Potential starting() {
        return 4;
    }
    static Potential eq() {
        return 0;
    }
    static Potential speed() {
        return 0.1;
    }
};

class SynapseParams {
public:
    static Time default_synaptic_delay() { // Задержка на синапсе
        return 0.001;
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
    const Index<Neuron> &source, &target;
    Time delay;

    Temporal<Potential, SynapseConductivityParams> conductivity; // эффективность проведения импульса
    Temporal<double, SynapseActivityParams> activity; // уровень готовности к пластической перестройке
};
