#include "Message.hpp"
#include "Averager.hpp"
#include "MovingAverager.hpp"
#include "BacklogPublisher.hpp"
#include "SimplePublisher.hpp"
#include "PeriodicSampler.hpp"
#include "Repository.hpp"
#include "Subscriber.hpp"
#include <assert.h>
#include <iostream>
using namespace std;

// Here's some sample usage of the Subscribers,
// Publishers and the Repository

void testSimplePublisher() {
  Repository repo;

  Averager avg1("avg1");
  repo.add(&avg1);

  Averager avg2("avg2");
  repo.add(&avg2);

  SimplePublisher sp;
  sp.subscribe(static_cast<Averager*>(repo.get("avg1")));
  sp.signal({10});
  sp.subscribe((Averager*)repo.get("avg2"));
  sp.signal({0});

  assert(static_cast<Averager*>(repo.get("avg1"))->read() == 5);
  assert(static_cast<Averager*>(repo.get("avg2"))->read() == 0);
  assert(avg1.read() == 0); //5
}

void testBacklogPublisher() {
  Repository repo;
  Averager avg1("avg1");
  repo.add(&avg1);

  BacklogPublisher bp;
  bp.signal({10});
  bp.signal({0});

  bp.subscribe(static_cast<Averager*>(repo.get("avg1")));
  assert(static_cast<Averager*>(repo.get("avg1"))->read() == 5);
}

void testMovingAverager() {
  Repository repo;
  MovingAverager mavg1("mavg1", 2);
  repo.add(&mavg1);

  SimplePublisher sp;
  sp.subscribe(static_cast<MovingAverager*>(repo.get("mavg1")));
  sp.signal({10});
  sp.signal({0});
  assert(static_cast<MovingAverager*>(repo.get("mavg1"))->read() == 5);

  sp.signal({4});
  assert(static_cast<MovingAverager*>(repo.get("mavg1"))->read() == 2);
}

void testPeriodicSampler() {
  Repository repo;
  PeriodicSampler ps2("ps2", 2);
  repo.add(&ps2);

  SimplePublisher sp;
  sp.subscribe(static_cast<PeriodicSampler*>(repo.get("ps2")));
  sp.signal({10});
  assert(static_cast<PeriodicSampler*>(repo.get("ps2"))->read() == 10);

  sp.signal({0});
  assert(static_cast<PeriodicSampler*>(repo.get("ps2"))->read() == 10);

  sp.signal({4});
  assert(static_cast<PeriodicSampler*>(repo.get("ps2"))->read() == 4);
}

int main() {
    testSimplePublisher();
    testBacklogPublisher();
    testMovingAverager();
    testPeriodicSampler();


    Averager* avg = new Averager("id1");
    MovingAverager* movAvg = new MovingAverager("id2", 5);
    PeriodicSampler* perSam = new PeriodicSampler("id3", 3);

    SimplePublisher pub;
    pub.subscribe(avg);
    pub.subscribe(movAvg);
    pub.subscribe(perSam);

    pub.signal(1);
    pub.signal(2);
    pub.signal(3);
    pub.signal(4);
    pub.signal(5);
    pub.signal(6);
    pub.signal(7);
    pub.signal(8);
    pub.signal(9);

    std::cout<<avg->read()<<std::endl;
    std::cout<<movAvg->read()<<std::endl;
    std::cout<<perSam->read()<<std::endl<<std::endl;


    Averager* avg2 = new Averager("ID1");
    MovingAverager* movAvg2 = new MovingAverager("id2", 1);
    BacklogPublisher bpub;
    bpub.subscribe(avg2);
    bpub.signal(1);
    bpub.signal(2);
    bpub.signal(3);
    bpub.subscribe(movAvg2);
    bpub.signal(4);
    std::cout<<avg2->read()<<std::endl;
    std::cout<<movAvg2->read()<<std::endl;

    delete avg;
    delete movAvg;
    delete perSam;
    delete avg2;
    delete movAvg2;
    std::cout<<std::endl<<std::endl;

    return 0;
}
