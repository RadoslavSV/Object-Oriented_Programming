/// Radoslav Velkov, group 1, FN: 62528

#include "Semaphore.hpp"

Semaphore::Semaphore()
{
    setInitial(0);
}

Semaphore::Semaphore(bool value)
{
    if(value) setInitial(1);
    else setInitial(0);
}

bool Semaphore::isAvailable()
{
    if( getTotal()>0 ) return true;
    else return false;
}

void Semaphore::wait()
{
    int updated = getTotal() - getStep();
    if( updated>=getMin() )
    {
        setTotal(updated);
    }
}

void Semaphore::signal()
{
    int updated = getTotal() + getStep();
    if( updated<=getMax() )
    {
        setTotal(updated);
    }
}







