#include "Synapse.hpp"
#include "NeuralNet.hpp"
#include "Neuron.hpp"

Synapse::Synapse(NeuralNet &net, const Index<Synapse> &s, const Index<Neuron> &n1, const Index<Neuron> &n2) {
    net.GetNeuron(n1).AddOutputSynapse(s);
    net.GetNeuron(n2).AddInputSynapse(s);
}
