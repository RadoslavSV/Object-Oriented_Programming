/// Radoslav Velkov, group 1, FN: 62528

#include <iostream>
#include "Counter.hpp"
using namespace std;

int Counter::getInitial() const
{
    return this->initial;
}

unsigned Counter::getStep() const
{
    return this->step;
}

int Counter::getTotal() const
{
    return this->total;
}

void Counter::setInitial(int initial)
{
    this->initial = initial;
}

void Counter::setStep(unsigned step)
{
    this->step = step;
}

void Counter::setTotal(int total)
{
    this->total = total;
}

Counter::Counter()
{
    setInitial(0);
    this->step = 1;
    setTotal(0);
}

Counter::Counter(int initial)
{
    setInitial(initial);
    this->step = 1;
    setTotal(initial);
}

Counter::Counter(int initial, unsigned step)
{
    setInitial(initial);
    this->step = step;
    setTotal(initial);
}

void Counter::increment()
{
    int updated = total + step;
    setTotal(updated);
}

void Counter::printCounter()
{
    std::cout<<"Initial:"<<getInitial()<<", Step:"<<getStep()<<", Total:"<<getTotal()<<std::endl;
}














