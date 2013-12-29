#pragma once

#include <algorithm>
#include <vector>

using namespace std;

template <typename T>
bool cmp(pair<Time, T> &a, pair<Time, T> &b) {
    return a.first > b.first;
}

template <typename T>
class Queue {
public:
    Queue() {}
    void Enqueue(Time t, T &obj) {
        queue.push_back(pair<Time, T>(t, obj));
        std::push_heap (queue.begin(),queue.end(),cmp<T>);
    }
    void Enqueue(Time t, T obj) {
        queue.push_back(pair<Time, T>(t, obj));
        std::push_heap (queue.begin(),queue.end(),cmp<T>);
    }

    pair<Time, T> Dequeue() {
        std::pop_heap (queue.begin(),queue.end(),cmp<T>);
        auto last = queue.back();
        queue.pop_back();
        return last;
    }
private:
    vector<pair<Time, T> > queue;
};
