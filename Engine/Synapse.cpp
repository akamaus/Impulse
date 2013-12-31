#include "Synapse.hpp"
#include "NeuralNet.hpp"
#include "Neuron.hpp"

Synapse::Synapse(NeuralNet &net, const Index<Synapse> &s, const Index<Neuron> &n1, const Index<Neuron> &n2): source(n1), target(n2), delay(SynapseParams::default_synaptic_delay()) {
    net.GetNeuron(n1).AddOutputSynapse(s);
    net.GetNeuron(n2).AddInputSynapse(s);
}

void Synapse::Fire(NeuralNet &net) {
//    auto &s = net.GetNeuron(source);
    auto &t = net.GetNeuron(target);
    t.Exite(net, conductivity.Decay(net.GetTime()));
}
