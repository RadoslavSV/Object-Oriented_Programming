#pragma once

class Comparable{
public:
    virtual bool operator==(const Comparable* rhs) = 0;
    virtual bool operator!=(const Comparable* rhs) = 0;
};
