/// Radoslav Velkov, fn 62528, group 1

#include "ElectionResultsDatabase.hpp"

void ElectionResultsDatabase::addResultsFromFile(const char* filename)
{
    const int MAX_SIZE=10000;
    char str1[MAX_SIZE];
    ifstream fileIn;
    fileIn.open(filename,ios::in);
    while( fileIn.getline(str1,100,'\n') )
    {
        sectionsNumber++;
        int i=0;
        for( ; str1[i]!=' '; i++)
        {
            int totalNumber=0;
            int m=i;
            int number=0;
            if(str1[m+1]>='0' && str1[m+1]<='9')
            {
                for(m=m+1; str1[m]>='0' && str1[m]<='9'; m++);
                m--;
                i=m;
                int multiplier=1;

                while( str1[m]>='0' && str1[m]<='9' )
                {
                    number += ((int)(str1[m]-'0')*multiplier);
                    multiplier*=10;
                    m--;
                }
                totalNumber += number;
                this->party1TotalVotes += totalNumber;
            }
            else {
            totalNumber+=(int)(str1[i]-'0');
            this->party1TotalVotes += totalNumber; }
        }
        i++;
        for( ; str1[i]!=' '; i++)
        {
            int totalNumber=0;
            int m=i;
            int number=0;
            if(str1[m+1]>='0' && str1[m+1]<='9')
            {
                for(m=m+1; str1[m]>='0' && str1[m]<='9'; m++);
                m--;
                i=m;
                int multiplier=1;

                while( str1[m]>='0' && str1[m]<='9' )
                {
                    number += ((int)(str1[m]-'0')*multiplier);
                    multiplier*=10;
                    m--;
                }
                totalNumber += number;
                this->party2TotalVotes += totalNumber;
            }
            else {
            totalNumber+=(int)(str1[i]-'0');
            this->party2TotalVotes += totalNumber; }
        }
        i++;
        for( ; str1[i]!='\0'; i++)
        {
            int totalNumber=0;
            int m=i;
            int number=0;
            if(str1[m+1]>='0' && str1[m+1]<='9')
            {
                for(m=m+1; str1[m]>='0' && str1[m]<='9'; m++);
                m--;
                i=m;
                int multiplier=1;

                while( str1[m]>='0' && str1[m]<='9' )
                {
                    number += ((int)(str1[m]-'0')*multiplier);
                    multiplier*=10;
                    m--;
                }
                totalNumber += number;
                this->party3TotalVotes += totalNumber;
            }
            else {
            totalNumber+=(int)(str1[i]-'0');
            this->party3TotalVotes += totalNumber; }
        }
    }
    fileIn.close();
}

int ElectionResultsDatabase::numberOfSections() const
{
    return this->sectionsNumber;
}

int ElectionResultsDatabase::votesForParty(Party party) const
{
    if( (int)party == 0 ) return getParty1TotalVotes();
    if( (int)party == 1 ) return getParty2TotalVotes();
    if( (int)party == 2 ) return getParty3TotalVotes();
}

Party ElectionResultsDatabase::winningParty() const
{
    if( getParty1TotalVotes()>=getParty2TotalVotes() && getParty1TotalVotes()>=getParty3TotalVotes() ) return Party::PARTY1;
    if( getParty2TotalVotes()>getParty1TotalVotes() && getParty2TotalVotes()>=getParty3TotalVotes() ) return Party::PARTY2;
    if( getParty3TotalVotes()>getParty1TotalVotes() && getParty3TotalVotes()>getParty2TotalVotes() ) return Party::PARTY3;
}

int ElectionResultsDatabase::getParty1TotalVotes() const
{
    return this->party1TotalVotes;
}

int ElectionResultsDatabase::getParty2TotalVotes() const
{
    return this->party2TotalVotes;
}

int ElectionResultsDatabase::getParty3TotalVotes() const
{
    return this->party3TotalVotes;
}
