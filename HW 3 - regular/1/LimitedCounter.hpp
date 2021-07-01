/// Radoslav Velkov, group 1, FN: 62528

#pragma once
#include "Counter.hpp"

class LimitedCounter: virtual public Counter{
private:
    int maximum = 0;
public:
    int getMax() const;
    void setMax(int);
    LimitedCounter(){};
    LimitedCounter(int);
    LimitedCounter(int, int);
    LimitedCounter(int, int, unsigned);
    void increment();

    void printCounter();
};
