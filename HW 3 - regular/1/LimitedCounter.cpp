/// Radoslav Velkov, group 1, FN: 62528

#include <iostream>
#include "LimitedCounter.hpp"

int LimitedCounter::getMax() const
{
    return this->maximum;
}

void LimitedCounter::setMax(int maximum)
{
    this->maximum = maximum;
}

LimitedCounter::LimitedCounter(int maximum)
{
    this->maximum = maximum;
    setInitial(0);
    setStep(1);
    setTotal(0);
}

LimitedCounter::LimitedCounter(int maximum, int initial)
{
    this->maximum = maximum;
    setInitial(initial);
    setStep(1);
    setTotal(initial);
}

LimitedCounter::LimitedCounter(int maximum, int initial, unsigned step)
{
    this->maximum = maximum;
    setInitial(initial);
    setStep(step);
    setTotal(initial);
}

void LimitedCounter::increment()
{
    int updated = getTotal() + getStep();
    if( updated<=getMax() )
    {
        setTotal(updated);
    }
}

void LimitedCounter::printCounter()
{
    std::cout<<"Max:"<<getMax()<<", Initial:"<<getInitial()<<", Step:"<<getStep()<<", Total:"<<getTotal()<<std::endl;
}












