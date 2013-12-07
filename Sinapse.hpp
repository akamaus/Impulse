#pragma once

#include "ImpTypes.hpp"
class Neuron;

class Sinapse {
public:
    Sinapse(Neuron &n1, Neuron &n2) {
        n1.AddOutputSinapse(this);
        n2.AddInputSinapse(this);
    }

private:
    Time delay;

    Temporal<Potential, 0, 0.001> conductivity; // эффективность проведения импульса
    Temporal<Double, 0, 0.1> activity; // уровень готовности к пластической перестройке
}
