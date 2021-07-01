#include "Averager.hpp"

Averager::Averager(std::string id)
{
    this->id = id;
    vec.clear();
}

int Averager::read() const
{
    if( vec.empty() ) return 0;
    else
    {
        int av = 0;
        for( auto x : vec )
        {
            av += x.data;
        }
        av /= vec.size();
        return static_cast<int>(av);
    }
}



