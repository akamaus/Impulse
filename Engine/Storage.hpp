#pragma once

#include <unordered_map>

#include "ImpTypes.hpp"

namespace std {
    template<typename T>
    struct hash<Index<T> > {
        size_t operator()(const Index<T> &i) const {
            return hash<int>()(i.GetIndex());
        }
    };

    template<typename T>
    struct equal_to<Index<T> > {
        size_t operator()(const Index<T> &i1, const Index<T> &i2) const {
            return i1.GetIndex() == i2.GetIndex();
        }
    };
};

template <typename T, typename Creator>
class Storage {
public:
    Storage() {}
;
    Index<T> Insert(T *obj) {
        auto i = fresh;
        storage[i] = obj;
        fresh = fresh.Next();
        return i;
    }
    Index<T> Create(const Creator &creator) {
        auto i = fresh;
        storage[i] = creator(i);
        return i;
    }
    T &operator[] (Index<T> ind) {
        return *storage.at(ind);
    }
private:
    std::unordered_map<Index<T>, T *> storage;
    Index<T> fresh;
};
