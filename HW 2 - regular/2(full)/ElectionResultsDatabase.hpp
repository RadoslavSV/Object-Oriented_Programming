/// Radoslav Velkov, fn 62528, group 1

#pragma once
#include <iostream>
#include <fstream>
#include <ostream>
#include "SectionVotes.cpp"
using namespace std;

class ElectionResultsDatabase{
    int party1TotalVotes=0, party2TotalVotes=0, party3TotalVotes=0;
    int sectionsNumber=0;

public:
    ElectionResultsDatabase(): party1TotalVotes(0), party2TotalVotes(0), party3TotalVotes(0) {};

    void addResultsFromFile(const char* filename);
    int numberOfSections() const;
    int votesForParty(Party) const;
    Party winningParty() const;

    int getParty1TotalVotes() const;
    int getParty2TotalVotes() const;
    int getParty3TotalVotes() const;

    friend std::istream& operator>>(std::istream& in, ElectionResultsDatabase& s);
    friend std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& s);

};

inline std::istream& operator>>(std::istream& in, ElectionResultsDatabase& s)
{
    char discard;
    in>>s.party1TotalVotes>>discard>>s.party2TotalVotes>>discard>>s.party3TotalVotes;
    return in;
}

inline std::ostream& operator<<(std::ostream& out, const ElectionResultsDatabase& s)
{
    out<<s.getParty1TotalVotes()<<" "<<s.getParty2TotalVotes()<<" "<<s.getParty3TotalVotes()<<std::endl;
    return out;
}



