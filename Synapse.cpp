#include "Synapse.hpp"
#include "Neuron.hpp"

Synapse::Synapse(Neuron &n1, Neuron &n2) {
    n1.AddOutputSynapse(*this);
    n2.AddInputSynapse(*this);
}
