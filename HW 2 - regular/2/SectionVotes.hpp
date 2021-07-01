/// Radoslav Velkov, fn 62528, group 1

#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
using namespace std;

enum Party
{
    PARTY1 = 0,
    PARTY2 = 1,
    PARTY3 = 2,
};

class SectionVotes{
    int party1Votes=0, party2Votes=0, party3Votes=0;

public:
    SectionVotes();
    SectionVotes(int party1Votes, int party2Votes, int party3Votes);
    int votesForParty(Party) const;

    int getParty1Votes() const;
    int getParty2Votes() const;
    int getParty3Votes() const;

    friend std::istream& operator>>(std::istream& in, SectionVotes& s);
    friend std::ostream& operator<<(std::ostream& out, const SectionVotes& s);

};

inline std::istream& operator>>(std::istream& in, SectionVotes& s)
{
    int input1, input2, input3;
    in>>input1>>input2>>input3;
    s.party1Votes=input1;
    s.party2Votes=input2;
    s.party3Votes=input3;
    return in;
}

inline std::ostream& operator<<(std::ostream& out, const SectionVotes& s)
{
    out<<s.getParty1Votes()<<" "<<s.getParty2Votes()<<" "<<s.getParty3Votes()<<std::endl;
    return out;
}



