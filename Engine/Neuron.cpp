#include "Neuron.hpp"
#include "NeuralNet.hpp"

#include <iostream>

void Neuron::Exite(NeuralNet &net, Potential imp) {
    Time t = net.GetTime();
    Potential p = level.Add(imp, t);

    std::cerr << "Neuron " << this << " exited at time " << t << std::endl;
    if ( p >=  NeuronTemporalParams :: action_potential()) {
        std::cerr << "Impulse on neuron " << this << " at time " << t << std::endl;
        for (auto s : output_synapses) {
            net.FireSynapse(s);
        }
    }
}
