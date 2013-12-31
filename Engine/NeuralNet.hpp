#pragma once

#include "Neuron.hpp"
#include "Storage.hpp"
#include "Synapse.hpp"
#include "TimeQueue.hpp"

#include <vector>

class NeuralNet {
public:
    NeuralNet() {}

    // Получение нейронов по индексу
    Neuron &GetNeuron(Index<Neuron> ni) {
        return neurons[ni.GetIndex()];
    }
    // Получение синапса по индексу
    Synapse &GetSynapse(Index<Synapse> si) {
        return synapses[si.GetIndex()];
    }

    // Создать заданное количество нейронов
    void CreateNeurons(int k) {
        for (int i=0; i<=k ; i++)
            neurons.Insert(new Neuron());
    }

    // Соединить нейроны синапсом
    void GrowSinapse(Index<Neuron> n1, Index<Neuron> n2) {
        synapses.Create(SynapseCreator{*this, n1,n2});
    }

    // Активировать синапс с учётом его задержки срабатывания
    void FireSynapse(Index<Synapse> si) {
        Synapse &syn = GetSynapse(si);
        fires.Enqueue(time + syn.GetDelay(), si);
    }

    // Активировать синапс через заданное время
    void FireSynapse(Index<Synapse> si, Time delta) {
        fires.Enqueue(time + delta, si);
    }

    // Получить текущее время
    Time GetTime() const {
        return time;
    }

    // Выполнить один шаг симулиции (обработать ближайшую по времени активацию нейрона
    bool Tick();

private:

    class NeuronCreator {
    public:
        Neuron * operator()(Index<Neuron> ni) const {
            return new Neuron;
        };
    };
    class SynapseCreator {
    public:
        SynapseCreator(NeuralNet &_net, const Index<Neuron> &_n1, const Index<Neuron> &_n2):
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
