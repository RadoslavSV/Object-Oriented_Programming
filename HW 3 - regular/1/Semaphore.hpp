/// Radoslav Velkov, group 1, FN: 62528

#pragma once
#include "LimitedTwowayCounter.hpp"

class Semaphore: public LimitedTwowayCounter{
private:
    const int MIN = 0;
    const int MAX = 1;
    const unsigned STEP = 1;
public:
    const int getMin()
    { return this->MIN; };
    const int getMax()
    { return this->MAX; };
    const int getStep()
    { return this->STEP; };
    Semaphore();
    Semaphore(bool);
    bool isAvailable();
    void wait();
    void signal();

};
