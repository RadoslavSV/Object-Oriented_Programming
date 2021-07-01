/// Radoslav Velkov, group 1, FN: 62528

#pragma once

class Counter{
private:
    int initial = 0;
    unsigned step = 1;
    int total = 0;

public:
    int getInitial() const;
    unsigned getStep() const;
    int getTotal() const;
    void setInitial(int);
    void setStep(unsigned );
    void setTotal(int);
    Counter();
    Counter(int);
    Counter(int, unsigned);
    void increment();

    void printCounter();
};
