#pragma once

#include <list>

#include "ImpTypes.hpp"

#include "Temporal.hpp"

class Sinapse;

class Neuron {
public:
    Neuron();
    void Exite(Potential imp);

    Potential GetPotential() const;
    void AddInputSinapse(Sinapse &s) {
        input_sinapses.push_back(&s);
    }
    void AddOutputSinapse(Sinapse &s) {
        output_sinapses.push_back(&s);
    }

private:
    Temporal<Potential, -70.0, 100.0> level;
    std::list<Sinapse *> input_sinapses, output_sinapses;
};
