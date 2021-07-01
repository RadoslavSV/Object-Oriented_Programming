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


#include <iostream>
using namespace std;

#include "zad2code.cpp"

int main()
{   //examples illustrating the working of the program:

    MonsterCard DarkMagician("Dark Magician", 2500, 1300);   //init. a monster card - Dark Magician with attack:2500 and defense:1300
    MonsterCard WhiteMagician("White Magician", 1500, 3500);
    MagicCard Reflection("Reflection", "Reflects last played spell", "trap");  //init. a magic card - Reflection that reflects last pl. spell and is a trap
    MagicCard Invisibility("Invisibility", "Makes you invisible", "spell");
    DarkMagician.printMonsterCard();  //print said monster card
    Reflection.printMagicCard();  //print said magic card
    cout<<endl;

    Deck d1;   //initialize a deck - d1

    d1.addMonsterCard("Rex", 350, 450);   //add a monster card to it
    d1.addMagicCard("Wiz", "amaze", "buff");  //- || - magic card

    d1.changeMonsterCard(7, "Truth", 345, 1000);  //change monster card on a particular position
    d1.changeMagicCard(3, "Bizarre", "clone", "spell");  //- || - magic card
    d1.changeMagicCard(10, "Dust", "daze", "trap");

    d1.printMonsterCard(0);  //print said cards:
    d1.printMonsterCard(7);
    d1.printMagicCard(0);
    d1.printMagicCard(3);
    d1.printMagicCard(10);

    cout<<endl<<"Count of Monster cards in deck: "<<d1.getMonstersCount()<<endl;  //use function that counts how many monster cards are there in the said deck
    cout<<"Count of Magic cards in deck: "<<d1.getMagicsCount()<<endl;            // - || - with magic cards
    cout<<endl;

    Duelist p1("Yugi Muto");      //initialize a new duelist - p1 with name "Yugi Muto"
    cout<<"Duelist name: "<<p1.name<<endl<<endl;

    p1.addMonsterCardInDeck(WhiteMagician);  //adds a new monster card in the first empty slot (i.e. 0 position)
    p1.printMonsterCardInDeck(0);

    p1.addMagicCardInDeck(Invisibility);   //adds a new magic card in the first empty slot (i.e. 0 position)
    p1.printMagicCardInDeck(0);

    p1.changeMonsterCardInDeck(0, DarkMagician);  //changes the current monster card with a new one in the said slot (again 0)
    p1.printMonsterCardInDeck(0);

    p1.changeMagicCardInDeck(3, Reflection);  //changes the current magic card with a new one in the said slot (3)
    p1.printMagicCardInDeck(0);
    p1.printMagicCardInDeck(3);


    return 0;
}


