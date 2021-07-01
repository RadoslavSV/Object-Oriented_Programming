/**
* Solution to homework assignment 1
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Radoslav Velkov
* @idnumber 62528
* @task 2
* @compiler GCC
*/


#include "zad2class.hpp"
#include <string.h>
using namespace std;

MonsterCard::MonsterCard()
{
    strncpy(name, "empty", 26);
    attPts = 0;
    defPts = 0;
}

MonsterCard::MonsterCard(char n[], unsigned int a, unsigned int d)   //n -> name, a -> attack, d -> defense
{
    strncpy(name, n, 26);
    attPts = a;
    defPts = d;
}

MagicCard::MagicCard()
{
    strncpy(name, "empty", 26);
    strncpy(effect, "empty", 101);
    strncpy(type, "empty", 6);
}

MagicCard::MagicCard(char n[], char e[], char t[])
{
    strncpy(name, n, 26);
    strncpy(effect, e, 101);
    strncpy(type, t, 6);
}

void MonsterCard::printMonsterCard()
{
    cout<<"Name: "<<name<<"  ATK:"<<attPts<<"  DEF:"<<defPts<<endl;
}

void MagicCard::printMagicCard()
{
    cout<<"Name: "<<name<<"  Effect:"<<effect<<"  Type:"<<type<<endl;
}



Deck::Deck()
{   //the default constructor gives all 20 possible spaces for cards the name "empty" and makes the attack and defense points equal to 0
    for(int i=0;i<20;i++)
    {
        strncpy(monsters[i].name,"empty",26);
        monsters[i].attPts=0;
        monsters[i].defPts=0;

        strncpy(magics[i].name,"empty",26);
        strncpy(magics[i].effect,"empty",101);
        strncpy(magics[i].type,"empty",6);
    }
}

int Deck::getMonstersCount()
{
    int cnt=0;
    for(int i=0;i<20;i++)
    {
        if(monsters[i].attPts!=0) cnt++;    //if the attack points are something different from 0, then there is a card
    }
    return cnt;
}

int Deck::getMagicsCount()
{
    int cnt=0;
    for(int i=0;i<20;i++)
    {
        if(magics[i].type[0]!='e') cnt++;
    }   //type can only be one of these three: "trap", "spell" or "buff", so if its first letter is 'e', then the word is "empty"
    return cnt;
}

void Deck::addMonsterCard(char n[], unsigned int a, unsigned int d)   //n -> name, a -> attack, d -> defense
{
    int i=0;
    while(monsters[i].attPts!=0)    //finds the first possible index
    {
        i++;
    }
    strncpy(monsters[i].name, n, 26);
    monsters[i].attPts = a;
    monsters[i].defPts = d;
}

void Deck::addMagicCard(char n[], char e[], char t[])   //n -> name, e -> effect, t -> type
{
    int i=0;
    while(magics[i].type[0]!='e')  //again - finds the earliest empty slot
    {
        i++;
    }
    strncpy(magics[i].name, n, 26);
    strncpy(magics[i].effect, e, 101);
    strncpy(magics[i].type, t, 6);
}

void Deck::changeMonsterCard(int i, char n[], unsigned int a, unsigned int d)
{
    strncpy(monsters[i].name, n, 26);
    monsters[i].attPts = a;
    monsters[i].defPts = d;

}

void Deck::changeMagicCard(int i, char n[], char e[], char t[])
{
    strncpy(magics[i].name, n, 26);
    strncpy(magics[i].effect, e, 101);
    strncpy(magics[i].type, t, 6);
}

void Deck::printMonsterCard(unsigned int i)
{
    cout<<"Name: "<<monsters[i].name<<"  ATK:"<<monsters[i].attPts<<"  DEF:"<<monsters[i].defPts<<endl;
}

void Deck::printMagicCard(unsigned int i)
{
    cout<<"Name: "<<magics[i].name<<"  Effect:"<<magics[i].effect<<"  Type:"<<magics[i].type<<endl;
}



Duelist::Duelist(char n[])
{
    strncpy(name, n, 250);
}

void Duelist::addMonsterCardInDeck(MonsterCard m)
{
    int i=0;
    while(deck.monsters[i].attPts!=0)    //finds the first possible index to add the card there
    {
        i++;
    }
    strncpy(deck.monsters[i].name, m.name, 26);
    deck.monsters[i].attPts = m.attPts;
    deck.monsters[i].defPts = m.defPts;
}

void Duelist::addMagicCardInDeck(MagicCard m)
{
    int i=0;
    while(deck.magics[i].type[0]!='e')              //   - || -
    {
        i++;
    }
    strncpy(deck.magics[i].name, m.name, 26);
    strncpy(deck.magics[i].effect, m.effect, 101);
    strncpy(deck.magics[i].type, m.type, 6);
}

void Duelist::changeMonsterCardInDeck(int i, MonsterCard m)
{
    strncpy(deck.monsters[i].name, m.name, 26);
    deck.monsters[i].attPts = m.attPts;
    deck.monsters[i].defPts = m.defPts;
}

void Duelist::changeMagicCardInDeck(int i, MagicCard m)
{
    strncpy(deck.magics[i].name, m.name, 26);
    strncpy(deck.magics[i].effect, m.effect, 101);
    strncpy(deck.magics[i].type, m.type, 6);
}

void Duelist::printMonsterCardInDeck(int i)
{
    cout<<"Name: "<<deck.monsters[i].name<<"  ATK:"<<deck.monsters[i].attPts<<"  DEF:"<<deck.monsters[i].defPts<<endl;
}

void Duelist::printMagicCardInDeck(int i)
{
    cout<<"Name: "<<deck.magics[i].name<<" Effect:"<<deck.magics[i].effect<<" Type:"<<deck.magics[i].type<<endl;
}




