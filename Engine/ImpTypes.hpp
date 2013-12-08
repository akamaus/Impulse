#pragma once

typedef float Time;
typedef float Potential;

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
