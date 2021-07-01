#include "PeriodicSampler.hpp"

PeriodicSampler::PeriodicSampler(std::string id, size_t period)
{
    this->id = id;
    this->period = period;
    vec.clear();
}

int PeriodicSampler::read() const
{
    if( vec.empty() ) return 0;
    else
    {
        auto currLast = vec[0];
        for(size_t i=0; i<vec.size(); i+=period)
        {
            currLast = vec[i];
        }
        return currLast.data;
    }
}

