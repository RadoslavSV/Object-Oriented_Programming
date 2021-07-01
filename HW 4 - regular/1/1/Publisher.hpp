#pragma once
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "Subscriber.hpp"
#include <vector>

class Publisher{
public:
    std::vector<Subscriber*> subs;
    std::vector<Message> mess;
    Publisher() { subs.clear(); }
    virtual ~Publisher() {}

    // unsubscribe removes a Subscriber from the Publisher
    // Subscribers are removed based on their `id`
    // id's will always be unique
    template<typename Subscriber>
    void unsubscribe(Subscriber*);

    // signal receives a message from an external source
    // and replays that message to all the current subscribers
    void signal(Message);
};

template<typename Subscriber>
void Publisher::unsubscribe(Subscriber* sub)
{
    for(size_t i=0; i<subs.size(); i++)
    {
        if( subs[i]->id == sub->id )
        {
            subs.erase( subs.begin() + i );
            break;
        }
    }
}

