#include "Repository.hpp"

void Repository::add(Averager* sub)
{
    Averager newT = *sub;
    averagers.push_back(newT);
}

void Repository::add(MovingAverager* sub)
{
    MovingAverager newT = *sub;
    movingAveragers.push_back(newT);
}

void Repository::add(PeriodicSampler* sub)
{
    PeriodicSampler newT = *sub;
    periodicSamplers.push_back(newT);
}

Subscriber* Repository::get(std::string id)
{
    for(size_t i=0; i<averagers.size(); i++)
    {
        if( averagers[i].id == id )
        {
            return &(averagers[i]);
        }
    }
    for(size_t i=0; i<movingAveragers.size(); i++)
    {
        if( movingAveragers[i].id == id )
        {
            return &(movingAveragers[i]);
        }
    }
    for(size_t i=0; i<periodicSamplers.size(); i++)
    {
        if( periodicSamplers[i].id == id )
        {
            return &(periodicSamplers[i]);
        }
    }
    return nullptr;   //end case
}
