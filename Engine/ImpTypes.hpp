#pragma once

typedef float Time;
typedef float Potential;

// обертка для обезопашевания индексации
template <typename Obj>
class Index {
public:
    Index(): index{0} {}
    Index(int val): index{val} {};
    int GetIndex() const {
        return index;
    }
    Index<Obj> Next() const {
        Index<Obj> next(GetIndex() + 1);
        return next;
    }
private:
    int index;
};
