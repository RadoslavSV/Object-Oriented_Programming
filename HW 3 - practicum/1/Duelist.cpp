/**
* Solution to homework assignment 3
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Radoslav Velkov
* @idnumber 62528
* @task 1
* @compiler GCC
*/

using namespace std;
#include "Duelist.hpp"

std::string Duelist::getName() const
{
    return this->name;
}

Deck& Duelist::getDeck()
{
    return this->deck;
}

Duelist::Duelist(string name)
{
    this->name = name;
    Deck newD;
    this->deck = newD;
}

void Duelist::setName(std::string name)
{
    this->name = name;
}

void Duelist::setDeck(Deck deck)
{
    this->deck = deck;
}

bool Duelist::saveDeck(const char* filename)
{
    std::ofstream fileOut;
    fileOut.open(filename,ios::out);

    bool isCorrect=false;
    if(fileOut.is_open()) isCorrect=true;

    fileOut<<getDeck().getName()<<"|"<<getDeck().getMonstersCount()<<"|"<<getDeck().getMagicsCount()<<"|"<<getDeck().getPendulumsCount()<<endl;

    for(int i=0; i<getDeck().getMonstersCount(); i++)
    {
        fileOut<<getDeck().monsterCards[i].getName()<<"|"<<getDeck().monsterCards[i].getEffect()<<"|"<<
                 getDeck().monsterCards[i].getAttPts()<<"|"<<getDeck().monsterCards[i].getDefPts()<<endl;
        isCorrect=true;
    }
    isCorrect=false;
    for(int i=0; i<getDeck().getMagicsCount(); i++)
    {
        fileOut<<getDeck().magicCards[i].getName()<<"|"<<getDeck().magicCards[i].getEffect()<<"|";
        if( (int)getDeck().magicCards[i].getType()==0 ) fileOut<<"TRAP";
        else if( (int)getDeck().magicCards[i].getType()==1 ) fileOut<<"BUFF";
        else if( (int)getDeck().magicCards[i].getType()==2 ) fileOut<<"SPELL";
        fileOut<<endl;
        isCorrect=true;
    }
    isCorrect=false;
    for(int i=0; i<getDeck().getPendulumsCount(); i++)
    {
        fileOut<<getDeck().pendulumCards[i].getName()<<"|"<<getDeck().pendulumCards[i].getEffect()<<"|"<<
                 getDeck().pendulumCards[i].getAttPts()<<"|"<<getDeck().pendulumCards[i].getDefPts()<<"|"<<
                 getDeck().pendulumCards[i].getPendulumScale()<<"|";
        if( (int)getDeck().pendulumCards[i].getType()==0 ) fileOut<<"TRAP";
        else if( (int)getDeck().pendulumCards[i].getType()==1 ) fileOut<<"BUFF";
        else if( (int)getDeck().pendulumCards[i].getType()==2 ) fileOut<<"SPELL";
        fileOut<<endl;
        isCorrect=true;
    }

    fileOut.close();
    if (isCorrect) return true;
    else return false;
}

bool Duelist::loadDeck(const char* filename)
{
    const int MAX_SIZE=100000;
    char str1[MAX_SIZE];
    ifstream fileIn;
    fileIn.open(filename,ios::in);
    bool isCorrect=false;
    if(fileIn.is_open()) isCorrect=true;

    int k=0;
    int numberOfMonsters=0, numberOfMagics=0, numberOfPendulums=0;

    while( fileIn.getline(str1,10000,'\n') )
    {
        for( ; k<1; k++)
        {
            int i=0;
            string name;
            for( ; str1[i]!='|'; i++)
            {
                name.push_back(str1[i]);
            }
            getDeck().setDeckname(name);
            i++;
            for( ; str1[i]!='|'; i++)
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
                }
                else {
                totalNumber+=(int)(str1[i]-'0');
                }
                numberOfMonsters = totalNumber;
            }
            i++;
            for( ; str1[i]!='|'; i++)
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
                }
                else {
                totalNumber+=(int)(str1[i]-'0');
                }
                numberOfMagics = totalNumber;
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
                }
                else {
                totalNumber+=(int)(str1[i]-'0');
                }
                numberOfPendulums = totalNumber;
            }
        }

        int endOfMonsters=numberOfMonsters+1;
        for(int l=2;l<=endOfMonsters;l++)
        {
            if(k==l)
            {
                string name;
                string effect;
                unsigned int attPts = 0;
                unsigned int defPts = 0;
                int i=0;
                for(; str1[i]!='|'; i++)
                {
                    name.push_back(str1[i]);
                }
                i++;
                for(; str1[i]!='|'; i++)
                {
                    effect.push_back(str1[i]);
                }
                i++;
                for(; str1[i]!='|'; i++)
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
                    }
                    else {
                    totalNumber+=(int)(str1[i]-'0');
                    }
                    attPts = totalNumber;
                }
                i++;
                for(; str1[i]!='\0'; i++)
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
                    }
                    else {
                    totalNumber+=(int)(str1[i]-'0');
                    }
                    defPts = totalNumber;
                }

                MonsterCard m(name, effect, attPts, defPts);
                getDeck().addMonsterCard(m);

            }
        }

        int endOfMagics=endOfMonsters+numberOfMagics;
        for(int l=endOfMonsters+1;l<=endOfMagics;l++)
        {
            if(k==l)
            {
                string name;
                string effect;
                CardType type;
                int i=0;
                for(; str1[i]!='|'; i++)
                {
                    name.push_back(str1[i]);
                }
                i++;
                for(; str1[i]!='|'; i++)
                {
                    effect.push_back(str1[i]);
                }
                i++;
                for(; str1[i]!='\0'; i++)
                {
                    char firstLetter;
                    firstLetter = str1[i];
                    if(firstLetter=='S') type = CardType::SPELL;
                    if(firstLetter=='T') type = CardType::TRAP;
                    if(firstLetter=='B') type = CardType::BUFF;
                    break;
                }

                MagicCard m(name, effect, type);
                getDeck().addMagicCard(m);
            }
        }

        int endOfPendulums=endOfMagics+numberOfPendulums;
        for(int l=endOfMagics+1;l<=endOfPendulums;l++)
        {
            if(k==l)
            {
                string name;
                string effect;
                unsigned int attPts = 0;
                unsigned int defPts = 0;
                int pendulumScale = 0;
                CardType type;
                int i=0;
                for(; str1[i]!='|'; i++)
                {
                    name.push_back(str1[i]);
                }
                i++;
                for(; str1[i]!='|'; i++)
                {
                    effect.push_back(str1[i]);
                }
                i++;
                for(; str1[i]!='|'; i++)
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
                    }
                    else {
                    totalNumber+=(int)(str1[i]-'0');
                    }
                    attPts = totalNumber;
                }
                i++;
                for(; str1[i]!='|'; i++)
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
                    }
                    else {
                    totalNumber+=(int)(str1[i]-'0');
                    }
                    defPts = totalNumber;
                }
                i++;
                for(; str1[i]!='|'; i++)
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
                    }
                    else {
                    totalNumber+=(int)(str1[i]-'0');
                    }
                    pendulumScale = totalNumber;
                }
                i++;
                for(; str1[i]!='\0'; i++)
                {
                    char firstLetter;
                    firstLetter = str1[i];
                    if(firstLetter=='S') type = CardType::SPELL;
                    if(firstLetter=='T') type = CardType::TRAP;
                    if(firstLetter=='B') type = CardType::BUFF;
                    break;
                }

                PendulumCard p(name, effect, attPts, defPts, pendulumScale, type);
                getDeck().addPendulumCard(p);

            }
        }

        k++;
    }

    fileIn.close();
    if (isCorrect) return true;
    else return false;
}

void Duelist::display()
{
    std::cout<<"Duelist name: "<<getName()<<std::endl;
    getDeck().printDeck();
//    std::cout<<std::endl;
}
















