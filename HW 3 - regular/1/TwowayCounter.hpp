/// Radoslav Velkov, group 1, FN: 62528

#pragma once
#include "Counter.hpp"

class TwowayCounter: virtual public Counter{
private:
public:
    TwowayCounter();
    TwowayCounter(int);
    TwowayCounter(int, unsigned);
    void decrement();

};
