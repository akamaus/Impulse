#pragma once

#include "ImpTypes.hpp"

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}

template <typename V, V eq, V speed>
class Temporal {
public:
    Temporal(): value(eq), time(0) {}
    Temporal(V v0, Time t0): value(v0), time(t0) {}
    V Decay(Time t) {
        V diff = eq - value;
        Time dt = t - time;
        if (dt < eps || diff < eps) {
            return value;
        }
        V dv = speed * dt;
        if (dv > abs(diff)) {
            value = eq;
        } else {
            value += sgn<V>(diff) * dv;
        }
        time = t;
        return value;
    }
    V Add(V v, Time t) {
        Decay(t);
        value += v;
    }
private:
    V value;
    Time time;
};
