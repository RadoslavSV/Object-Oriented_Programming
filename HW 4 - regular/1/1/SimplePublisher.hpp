#pragma once
#include "Averager.hpp"
#include "Message.hpp"
#include "MovingAverager.hpp"
#include "PeriodicSampler.hpp"
#include "Subscriber.hpp"
#include "Publisher.hpp"
#include <vector>

// You are not allowed to make breaking changes to the class interface,
// but you are allowed to add additional methods/fields, as
// well as MODIFY the existing interface so as to make it
// "more correct" and more compact if possible

// SimplePublisher is a Publisher, which can have one
// or more subscribers and upon receiving a message
// via `signal()`, it replays that message to all the
// subscribers
class SimplePublisher : public Publisher {
public:
    SimplePublisher() { subs.clear(); }

    // subscribe registers a Subscriber to start receiving messages
    template<typename Subscriber>
    void subscribe(Subscriber*);
};

template<typename Subscriber>
void SimplePublisher::subscribe(Subscriber* sub)
{
    subs.push_back(sub);
}
