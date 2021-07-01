/// Radoslav Velkov, 1 group, FN 62528

#include <iostream>
using namespace std;

#include "LeavingRequest.cpp"
#include "PromotionRequest.cpp"
#include "Developer.cpp"
#include "TeamLead.cpp"
#include "Request.cpp"

int main()
{
    Request r1;
    cout<<r1.getCount()<<endl;
    Request r2;
    cout<<r2.getCount()<<endl;
    Request r3("Uff", "Ivan");
    cout<<r3.getCount()<<endl;
    LeavingRequest lr1("Sa6o");
    LeavingRequest lr2("Medi");
    cout<<lr1.getCount()<<endl<<lr2.getCount()<<endl;
    PromotionRequest pr1("Dani", 300);cout<<pr1.getCount()<<endl;
    Request r4;
    cout<<r4.getCount()<<endl;
    PromotionRequest pr2("rrr",24314);
    cout<<pr2.getCount()<<endl;

    return 0;
}
