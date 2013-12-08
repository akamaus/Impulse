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

class Synapse {
public:
    Synapse(Neuron &n1, Neuron &n2);

private:
    Time delay;

    Temporal<Potential, SynapseConductivityParams> conductivity; // эффективность проведения импульса
    Temporal<double, SynapseActivityParams> activity; // уровень готовности к пластической перестройке
};
