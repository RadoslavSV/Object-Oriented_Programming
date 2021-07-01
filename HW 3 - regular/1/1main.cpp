/// Radoslav Velkov, group 1, FN: 62528

#include <iostream>
using namespace std;

#include "Counter.hpp"
#include "LimitedCounter.hpp"
#include "TwowayCounter.hpp"
#include "LimitedTwowayCounter.hpp"
#include "Semaphore.hpp"

int main()
{
    Counter c0, c1(4), c2(-5, 3);
    c0.increment();
    c1.increment();
    c2.increment();
    c2.increment();
    c0.printCounter();
    c1.printCounter();
    c2.printCounter();

    TwowayCounter tc1, tc2(-7), tc3(19, 5);
    tc1.decrement();
    tc2.increment();
    tc3.decrement();
    tc3.decrement();
    tc1.printCounter();
    tc2.printCounter();
    tc3.printCounter();

    LimitedCounter lc1(4), lc2(15, -4, 6);
    lc2.increment();
    lc2.increment();
    lc2.increment();
    lc2.increment();
    lc2.increment();
    lc1.printCounter();
    lc2.printCounter();

    LimitedTwowayCounter ltc1(4, 9, 6, 1), ltc2(1, 15, 3, 6);
    ltc1.decrement();
    ltc1.decrement();
    ltc1.decrement();
    ltc2.increment();
    ltc2.increment();
    ltc2.increment();
    ltc2.increment();
    ltc1.printCounter();
    ltc2.printCounter();

    Semaphore s1(true);
    cout<<s1.getInitial()<<s1.getTotal()<<s1.isAvailable();




    return 0;
}
