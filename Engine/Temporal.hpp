#pragma once

#include "ImpCommon.hpp"

#include <limits>
#include <cstdlib>

template <typename T> int sgn(T val) {
    return (T(0) < val) - (val < T(0));
}


template <typename V, typename P>
class Temporal {
public:
    Temporal(): value(P::eq()), time(0) {}
    Temporal(V v0, Time t0): value(v0), time(t0) {}
    V Decay(Time t) {
        V diff = P::eq() - value;
        Time dt = t - time;
        if (dt < std::numeric_limits<V>::epsilon() || diff < std::numeric_limits<V>::epsilon()) {
            return value;
        }
        V dv = P::speed() * dt;
        if (dv > abs(diff)) {
            value = P::eq();
        } else {
            value += sgn<V>(diff) * dv;
        }
        time = t;
        return value;
    }
    V Add(V v, Time t) {
        Decay(t);
        value += v;
        return value;
    }
private:
    V value;
    Time time;
};
