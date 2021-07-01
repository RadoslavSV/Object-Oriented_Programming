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


#pragma once

class MonsterCard{
public:
    char name[26];
    unsigned int attPts;
    unsigned int defPts;

    MonsterCard();  //default constructor that gives default values of a newly-declared card
    MonsterCard(char[], unsigned int, unsigned int); //constructor that creates a monster card by given name, attack pts and defense pts

    void printMonsterCard();  //method that prints said card

};

class MagicCard{
public:
    char name[26];
    char effect[101];
    char type[6];     //since the only possible types are trap, buff and spell/longest/, 6 letters are enough (including '\0')

    MagicCard();
    MagicCard(char[], char[], char[]);

    void printMagicCard();

};

class Deck{
public:
    MonsterCard monsters[20];
    MagicCard magics[20];

    Deck(); //create a default constructor that gives default values
    int getMonstersCount();
    int getMagicsCount();
    void addMonsterCard(char[], unsigned int, unsigned int);
    void addMagicCard(char[], char[], char[]);
    void changeMonsterCard(int, char[], unsigned int, unsigned int);
    void changeMagicCard(int, char[], char[], char[]);

    void printMonsterCard(unsigned int); //create method that prints said monster card from a deck
    void printMagicCard(unsigned int);   //create method that prints said magic card from a deck


};

class Duelist{
public:
    char name[250];  //250 is a long enough number for a name
    Deck deck;      //object "deck" from type "Deck"

    //no need to create a default constructor, because there is no point in initializing a new duelist without inputting their name
    Duelist(char[]);  //create a constructor that uses a name as a parameter

    void addMonsterCardInDeck(MonsterCard);   //method that adds a new monster card in the first empty slot
    void addMagicCardInDeck(MagicCard);

    void changeMonsterCardInDeck(int, MonsterCard);  //method that changes said card in the deck
    void changeMagicCardInDeck(int, MagicCard);

    void printMonsterCardInDeck(int);  //method that prints said card from the duelist's deck
    void printMagicCardInDeck(int);

};





