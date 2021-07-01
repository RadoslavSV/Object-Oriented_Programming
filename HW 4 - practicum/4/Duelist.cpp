/**
* Solution to homework assignment 4
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Radoslav Velkov
* @idnumber 62528
* @task 4
* @compiler GCC
*/

#include <iostream>
#include <fstream>
#include <ostream>
#include <string>
#include <vector>
using namespace std;
#include "Duelist.hpp"

std::string Duelist::getName() const
{
    return this->name;
}

void Duelist::setName(std::string name)
{
    this->name = name;
}

Deck& Duelist::getDeck()
{
    return this->deck;
}

void Duelist::setDeck(Deck deck)
{
    this->deck = deck;
}

Duelist::Duelist(std::string name)
{
    setName(name);
    Deck newDeck;
    setDeck(newDeck);
}

void Duelist::display()
{
    std::cout<<"Duelist name: "<<getName()<<std::endl;
    getDeck().printDeck();
    std::cout<<std::endl;
}


bool Duelist::saveDeck(const char* filename)
{
    std::ofstream fileOut;
    fileOut.open(filename,ios::out);

    bool isCorrect=false;
    if(fileOut.is_open()) isCorrect=true;

    fileOut<<getDeck().getDeckname()<<"|"<<getDeck().getCardsCount()<<"|"<<getDeck().getMonstersCount()<<"|"
           <<getDeck().getMagicsCount()<<"|"<<getDeck().getPendulumsCount()<<endl;

    int i=0;
    for(; i<getDeck().getMonstersCount(); i++)
    {
        MonsterCard* monsterPtr = dynamic_cast<MonsterCard*>(getDeck().cards[i]);
        fileOut<<monsterPtr->getName()<<"|"<<monsterPtr->getEffect()<<"|"<<monsterPtr->getRarity()<<"|"<<
                 monsterPtr->getAttPts()<<"|"<<monsterPtr->getDefPts()<<endl;
        isCorrect=true;
    }
    isCorrect=false;
    for(; i<getDeck().getMagicsCount()+getDeck().getMonstersCount(); i++)
    {
        MagicCard* magicPtr = dynamic_cast<MagicCard*>(getDeck().cards[i]);
        fileOut<<magicPtr->getName()<<"|"<<magicPtr->getEffect()<<"|"<<magicPtr->getRarity()<<"|";
        if( (int)magicPtr->getType()==0 ) fileOut<<"TRAP";
        else if( (int)magicPtr->getType()==1 ) fileOut<<"BUFF";
        else if( (int)magicPtr->getType()==2 ) fileOut<<"SPELL";
        fileOut<<endl;
        isCorrect=true;
    }
    isCorrect=false;
    for(; i<getDeck().getPendulumsCount()+getDeck().getMagicsCount()+getDeck().getMonstersCount(); i++)
    {
        PendulumCard* pendulumPtr = dynamic_cast<PendulumCard*>(getDeck().cards[i]);
        fileOut<<pendulumPtr->getName()<<"|"<<pendulumPtr->getEffect()<<"|"<<pendulumPtr->getRarity()<<"|"<<
                 pendulumPtr->getAttPts()<<"|"<<pendulumPtr->getDefPts()<<"|"<<
                 pendulumPtr->getPendulumScale()<<"|";
        if( (int)pendulumPtr->getType()==0 ) fileOut<<"TRAP";
        else if( (int)pendulumPtr->getType()==1 ) fileOut<<"BUFF";
        else if( (int)pendulumPtr->getType()==2 ) fileOut<<"SPELL";
        fileOut<<endl;
        isCorrect=true;
    }

    fileOut.close();
    if (isCorrect) return true;
    else return false;
}

bool Duelist::loadDeck(const char* filename)
{
    getDeck().clearDeck();
    std::vector<Card*> newCards;

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
            i+=3;
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
/// //////////////
        int endOfMonsters=numberOfMonsters+1;
        for(int l=2;l<=endOfMonsters;l++)
        {
            if(k==l)
            {
                string name;
                string effect;
                unsigned int rarity = 0;
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
                    rarity = totalNumber;
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

                MonsterCard m(name, effect, rarity, attPts, defPts);
                getDeck().addCard(&m);

            }
        }

        int endOfMagics=endOfMonsters+numberOfMagics;
        for(int l=endOfMonsters+1;l<=endOfMagics;l++)
        {
            if(k==l)
            {
                string name;
                string effect;
                unsigned int rarity = 0;
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
                    rarity = totalNumber;
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

                MagicCard m(name, effect, rarity, type);
                getDeck().addCard(&m);
            }
        }

        int endOfPendulums=endOfMagics+numberOfPendulums;
        for(int l=endOfMagics+1;l<=endOfPendulums;l++)
        {
            if(k==l)
            {
                string name;
                string effect;
                unsigned int rarity = 0;
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
                    rarity = totalNumber;
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

                PendulumCard p(name, effect, rarity, attPts, defPts, pendulumScale, type);
                getDeck().addCard(&p);

            }
        }

        k++;
    }

    fileIn.close();
    if (isCorrect) return true;
    else return false;
}

void Duelist::duel(Duelist& duelist2)
{
    std::cout<<"Duel between "<<getName()<<" and "<<duelist2.getName()<<" :"<<std::endl;
    std::cout<<"---------------------------------------------"<<std::endl;

    bool isGoingToHappen = false;
    if( getDeck().getCardsCount() == duelist2.getDeck().getCardsCount() ) isGoingToHappen = true;
    if(isGoingToHappen)
    {
        int scoreDuelist1 = 0, scoreDuelist2 = 0;
        getDeck().shuffle();
        duelist2.getDeck().shuffle();
///        getDeck().printDeck();          -> good to know what is the exact order after the shuffling
///        duelist2.getDeck().printDeck();
        for(int i=0; i<getDeck().getCardsCount(); i++)
        {
            if( *getDeck().cards[i] > *duelist2.getDeck().cards[i] )
            {
                scoreDuelist1++;
            }
            else if( *duelist2.getDeck().cards[i] > *getDeck().cards[i] )
            {
                scoreDuelist2++;
            }
        }
        if( scoreDuelist1 > scoreDuelist2 )
        {
            std::cout<<getName()<<" WINS WITH SCORE "<<scoreDuelist1<<":"<<scoreDuelist2<<" !"<<std::endl;
        }
        else if( scoreDuelist2 > scoreDuelist1 )
        {
            std::cout<<duelist2.getName()<<" WINS WITH SCORE "<<scoreDuelist2<<":"<<scoreDuelist1<<" !"<<std::endl;
        }
        else if( scoreDuelist1 == scoreDuelist2 )
        {
            std::cout<<"DUEL ENDS IN A DRAW WITH SCORE "<<scoreDuelist1<<":"<<scoreDuelist2<<" !"<<std::endl;
        }
    }
    else std::cout<<"The duel cannot occur!"<<std::endl;
}






