#pragma once

typedef float Time;
typedef float Potential;

float eps = 1e-9;

// обертка для обезопашевания индексации
template <typename Obj>
class Index {
public:
    Index(int val): index(val) {};
    int GetIndex() {
        return index;
    }
    int index;
};
