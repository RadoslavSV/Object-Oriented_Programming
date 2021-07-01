#include "MovingAverager.hpp"

MovingAverager::MovingAverager(std::string id, size_t windowSize)
{
    this->id = id;
    this->windowSize = windowSize;
    vec.clear();
}

int MovingAverager::read() const
{
    if( vec.empty() ) return 0;
    else
    {
        int res = 0;
        int tot = 0;

        if( windowSize >= vec.size() )
        {
            for(size_t i = 0; i<vec.size(); i++)
            {
                tot += vec[i].data;
            }
            res = static_cast<int>(tot) / static_cast<int>(vec.size());
            return static_cast<int>(res);
        }

        for(size_t i = vec.size()-windowSize; i<vec.size(); i++)
        {
            tot += vec[i].data;
        }
        res = static_cast<int>(tot) / static_cast<int>(windowSize);
        return static_cast<int>(res);
    }
}
