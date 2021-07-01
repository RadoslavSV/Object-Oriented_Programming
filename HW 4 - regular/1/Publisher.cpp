#include "Publisher.hpp"

void Publisher::signal(Message message)
{
    for( auto x : subs )
    {
        x->signal(message);
    }
    mess.push_back(message);
}

