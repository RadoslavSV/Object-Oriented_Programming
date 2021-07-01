/// Radoslav Velkov, group 1, FN: 62528

#pragma once
#include "TwowayCounter.hpp"
#include "LimitedCounter.hpp"

class LimitedTwowayCounter: public TwowayCounter, public LimitedCounter{
private:
    int minimum = 0;
public:
    int getMin() const;
    void setMin(int);
    LimitedTwowayCounter(){};
    LimitedTwowayCounter(int, int);
    LimitedTwowayCounter(int, int, int);
    LimitedTwowayCounter(int, int, int, unsigned);
    void decrement();

    void printCounter();
};
