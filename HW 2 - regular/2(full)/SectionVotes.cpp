/// Radoslav Velkov, fn 62528, group 1

#include "SectionVotes.hpp"

inline SectionVotes::SectionVotes()
{
    this->party1Votes = 0;
    this->party2Votes = 0;
    this->party3Votes = 0;
}

inline SectionVotes::SectionVotes(int party1Votes, int party2Votes, int party3Votes)
{
    this->party1Votes = party1Votes;
    this->party2Votes = party2Votes;
    this->party3Votes = party3Votes;
}

inline int SectionVotes::getParty1Votes() const
{
    return this->party1Votes;
}

inline int SectionVotes::getParty2Votes() const
{
    return this->party2Votes;
}

inline int SectionVotes::getParty3Votes() const
{
    return this->party3Votes;
}

inline int SectionVotes::votesForParty(Party party) const
{
    if( (int)party == 0 ) return getParty1Votes();
    if( (int)party == 1 ) return getParty2Votes();
    if( (int)party == 2 ) return getParty3Votes();
}






