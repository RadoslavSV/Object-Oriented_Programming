/// Radoslav Velkov, group 1, FN: 62528

#include <iostream>
#include "LimitedTwowayCounter.hpp"

int LimitedTwowayCounter::getMin() const
{
    return this->minimum;
}

void LimitedTwowayCounter::setMin(int minimum)
{
    this->minimum = minimum;
}

LimitedTwowayCounter::LimitedTwowayCounter(int minimum, int maximum)
{
    setMin(minimum);
    setMax(maximum);
    setInitial(0);
    setStep(1);
    setTotal(0);
}

LimitedTwowayCounter::LimitedTwowayCounter(int minimum, int maximum, int initial)
{
    setMin(minimum);
    setMax(maximum);
    setInitial(initial);
    setStep(1);
    setTotal(initial);
}

LimitedTwowayCounter::LimitedTwowayCounter(int minimum, int maximum, int initial, unsigned step)
{
    setMin(minimum);
    setMax(maximum);
    setInitial(initial);
    setStep(step);
    setTotal(initial);
}

void LimitedTwowayCounter::decrement()
{
    int updated = getTotal() - getStep();
    if( updated>=getMin() )
    {
        setTotal(updated);
    }
}

void LimitedTwowayCounter::printCounter()
{
    std::cout<<"Min:"<<getMin()<<", Max:"<<getMax()<<", Initial:"<<getInitial()<<", Step:"<<getStep()<<", Total:"<<getTotal()<<std::endl;
}



