#pragma once

#include "Neuron.hpp"
#include "Storage.hpp"
#include "Synapse.hpp"
#include "TimeQueue.hpp"

#include <vector>

class NeuralNet {
public:
    NeuralNet() {}

    Neuron &GetNeuron(Index<Neuron> ni) {
        return neurons[ni.GetIndex()];
    }
    Synapse &GetSynapse(Index<Synapse> si) {
        return synapses[si.GetIndex()];
    }

    void CreateNeurons(int k) {
        for (int i=0; i<=k ; i++)
            neurons.Insert(new Neuron());
    }

    void GrowSinapse(Index<Neuron> n1, Index<Neuron> n2) {
        synapses.Create(SynapseCreator{*this, n1,n2});
    }

    void FireSynapse(Index<Synapse> si, Time delta_t) {
        fires.Enqueue(time + delta_t, si);
    }

private:

    class NeuronCreator {
    public:
        Neuron * operator()(Index<Neuron> ni) const {
            return new Neuron;
        };
    };
    class SynapseCreator {
    public:
        SynapseCreator(NeuralNet _net, const Index<Neuron> &_n1, const Index<Neuron> &_n2):
            net(_net), n1(_n1), n2(_n2) {}
        Synapse * operator()(Index<Synapse> si) const {
            return new Synapse(net, si, n1, n2);
        };
        NeuralNet &net;
        const Index<Neuron> &n1, &n2;
    };


    Storage<Neuron, NeuronCreator> neurons;
    Storage<Synapse, SynapseCreator> synapses;

    TimeQueue<Index<Synapse> > fires;
    Time time;
};
