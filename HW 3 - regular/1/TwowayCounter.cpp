/// Radoslav Velkov, group 1, FN: 62528

#include "TwowayCounter.hpp"

TwowayCounter::TwowayCounter()
{
    setInitial(0);
    setStep(1);
    setTotal(0);
}

TwowayCounter::TwowayCounter(int initial)
{
    setInitial(initial);
    setStep(1);
    setTotal(initial);
}

TwowayCounter::TwowayCounter(int initial, unsigned step)
{
    setInitial(initial);
    setStep(step);
    setTotal(initial);
}

void TwowayCounter::decrement()
{
    int updated = getTotal() - getStep();
    setTotal(updated);
}






