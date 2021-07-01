/**
* Solution to homework assignment 2
* Object Oriented Programming Course
* Faculty of Mathematics and Informatics of Sofia University
* Summer semester 2020/2021
*
* @author Radoslav Velkov
* @idnumber 62528
* @task 1
* @compiler GCC
*/

#include <iostream>
using namespace std;
#include "materials.cpp"
#include "money.cpp"
#include "armor.cpp"
#include "weapon.cpp"
#include "Equipment.hpp"
#include "Backpack.hpp"
#include "Inventory.hpp"

int main()
{
    Materials m1; //defines a default material ("herbs" with 0 quantity)
    Materials m2(MaterialType::essence, 14); //defines material "essence" with quantity 14
    m1.printMaterial();///herbs 0
    m2.printMaterial();///essence 14
    m1.setType(MaterialType::cloth);
    m1.addQuantity(20);
    m1.addQuantity(40);
    m1.printMaterial();///cloth 60
    cout<<"cloth slots:"<<m1.getSlots()<<endl<<"essence slots:"<<m2.getSlots()<<endl;///3 (20+20+20=60)    2 (10+4=14)
    cout<<endl;

    Money mo1, mo2(55, 75, 30);
    mo1.printMoney();///0 0 0
    mo2.printMoney();///55 75 30
    mo1.addGold(35);
    mo1.addGold(100);
    mo1.addSilver(317);//317 silver = 300 silver + 17 silver = 3 gold + 17 silver
    mo1.addCopper(104);//101 copper = 100 copper + 4 copper = 1 silver + 4 copper
    mo1.printMoney();///138 18 4
    cout<<endl;

    Armor a1;
    cout<<(int)a1.getType()<<" Defense:"<<a1.getDefense()<<endl;///0(cloth) def:0
    Armor a2(ArmorType::mail, 3000);
    cout<<(int)a2.getType()<<" Defense:"<<a2.getDefense()<<endl;///2(mail) def:3000

    a1.addEffect("Fade",500);
    a1.addEffect("Dazzle", 1200.5);
    a1.addEffect("Invisible", 900);
    a1.addEffect("Strengthen",350);
    a1.printAllEffects();
    cout<<"Gear score:"<<a1.getScore()<<endl;///2950.5
    a1.removeEffect("Dazzle", 1200.5); //removes the exact effect named Dazzle with power 1200
    a1.printAllEffects();
    cout<<"Gear score:"<<a1.getScore()<<endl;///1750
    a1.removeEffectByIdx(1); //removes Invisible,500 because its index is currently 1
    a1.changePower(1, 750);  //changes the power of the effect at index 1 to 750 (Strengthen,350 -> Strengthen,750)
    a1.printAllEffects();
    cout<<"Gear score:"<<a1.getScore()<<endl<<endl;///1250

    Weapon w(WeaponType::twoHanded, WeaponKind::sword);
    w.addEffect("Kill", 1000);
    w.addEffect("Hurt", 2500);
    w.addEffect("Wound", 300);
    w.addEffect("Flash",750.25);
    w.addEffect("Stun", 450);
    w.printAllEffects();
    cout<<"Hit damage min:"<<w.getHitDamage().first<<endl;///300
    cout<<"Hit damage max:"<<w.getHitDamage().second<<endl;///2500
    cout<<"Weapon score:"<<w.getScore()<<endl;///9600.375 [(1400+1000+2500+300+750.25+450)*1.5]
    w.removeEffect("Hurt", 2500); //removes exact effect by name and power
    w.removeEffectByIdx(1);      //removes an effect by its position in the set of effects (i.e. Wound,300)
    w.changePower(2, 500);       //updates the power of the effect on position 2 to 500 (i.e. Stun,450 to Stun,500)
    w.printAllEffects();
    cout<<"Hit damage min:"<<w.getHitDamage().first<<endl;///500
    cout<<"Hit damage max:"<<w.getHitDamage().second<<endl;///1000
    cout<<"Weapon score:"<<w.getScore()<<endl<<endl;///4500.375  { [ (500+1000)/2 + 1000 + 750.25 + 500 ] * 1.5 }

    Weapon w1(WeaponType::oneHanded, WeaponKind::mace);
    Weapon w2(WeaponType::twoHanded, WeaponKind::staff);
    cout<<(int)w1.getType()<<" "<<(int)w1.getKind()<<endl;///0 (one-handed)  3 (mace)
    cout<<(int)w2.getType()<<" "<<(int)w2.getKind()<<endl;///1 (two-handed)  4 (staff)
    w1.changeType(WeaponType::twoHanded); //changes first one's type from one-handed to two-handed, therefore mace automatically becomes sword (default two-handed weapon)
    cout<<(int)w1.getType()<<" "<<(int)w1.getKind()<<endl;///1 (two-handed)  1(sword)
    w2.changeKind(WeaponKind::dagger); //changes second one's kind from staff to dagger, therefore its type changes as well (1->0)
    cout<<(int)w2.getType()<<" "<<(int)w2.getKind()<<endl<<endl;///0 (one-handed)  2(dagger)


    Equipment<Armor> e1;
    cout<<e1.isEquipmentEmpty()<<endl;///true
    e1.addEquipment(a1);//adds cloth,0,1250
    e1.addEquipment(a2);//adds mail,3000,0
    e1.printArmorEquipment();///cloth,mail
    cout<<"Slots:"<<e1.getSlots()<<endl;///2
    cout<<"Best equipment:"<<e1.bestEquipment().getScore()<<endl;///1250 - the score of a1
    e1.removeExactArmor(a1);//removes cloth,0,1250
    e1.printArmorEquipment();///mail
    cout<<"Slots:"<<e1.getSlots()<<endl;///1
    cout<<e1.isEquipmentFull()<<endl;///false
    cout<<e1.isEquipmentEmpty()<<endl;///false

    Equipment<Armor> e2;
    Armor aR, aR2, aR3, aR4;
    e2.addEquipment(aR); e2.addEquipment(aR2); e2.addEquipment(aR3); e2.addEquipment(aR4);
    cout<<"Slots:"<<e2.getSlots()<<endl;///4
    e2.clearEquipment();//removes every object from the dynamic array
    e2.printArmorEquipment();///NULL
    cout<<"Slots:"<<e2.getSlots()<<endl<<endl;///0


    Equipment<Weapon> ee1;
    cout<<ee1.isEquipmentEmpty()<<endl;///true
    ee1.addEquipment(w);//inserts sword,4500.375
    ee1.addEquipment(w1);//inserts sword,0
    ee1.addEquipment(w2);//inserts dagger,0
    ee1.printWeaponEquipment();///sword,sword,dagger
    cout<<"Slots:"<<ee1.getSlots()<<endl;///3
    cout<<"Best equipment:"<<ee1.bestEquipment().getScore()<<endl;///4500.375 - first sword's weapon score
    ee1.removeEquipment(1);   //removes sword,0 because its index is 1
    ee1.printWeaponEquipment();///sword,dagger
    cout<<"Slots:"<<ee1.getSlots()<<endl;///2
    ee1.removeExactWeapon(w2);//removes dagger,0
    ee1.printWeaponEquipment();///sword(4500.375)
    cout<<"Slots:"<<ee1.getSlots()<<endl;///1
    cout<<ee1.isEquipmentFull()<<endl;///false
    cout<<ee1.isEquipmentEmpty()<<endl;///false

    Equipment<Weapon> ee2;
    Weapon wR, wR2, wR3, wR4;
    ee2.addEquipment(wR); ee2.addEquipment(wR2); ee2.addEquipment(wR3); ee2.addEquipment(wR4);
    cout<<"Slots:"<<ee2.getSlots()<<endl;///4
    ee2.clearEquipment();//removes every weapon
    ee2.printWeaponEquipment();///NULL
    cout<<"Slots:"<<ee2.getSlots()<<endl<<endl;///0


    Backpack<Materials> b1;
    b1.addMaterialToBackpack(m1);//adds cloth, quantity:60
    b1.addMaterialToBackpack(m2);//adds essence, quantity:14
    b1.printMaterials();///cloth,60  essence,14
    cout<<"Slots:"<<b1.getSlots()<<endl;///2
    b1.removeFromBackpack(1);//deletes the stuff from position #1 (i.e. essence,14)
    b1.printMaterials();///cloth,60
    cout<<"Slots:"<<b1.getSlots()<<endl;///1
    cout<<b1.isBackpackFull()<<endl;///false
    cout<<b1.isBackpackEmpty()<<endl;///false

    Backpack<Money> b2;
    b2.addMoneyToBackpack(mo1);//adds 138 gold, 18 silver and 4 copper
    b2.addMoneyToBackpack(mo2);//adds 55 gold, 75 silver and 30 copper
    b2.printMoney();///193 gold, 93 silver and 34 copper
    Money mm;//declare "mm" object from type Money (0 gold, 0 silver, 0 copper)
    mm.addSilver(13);//adds 13 silver to "mm"
    b2.addMoneyToBackpack(mm);//adds 0 gold, 13 silver and 0 copper (which here makes the total sum of silver 106, which is equal to 1 gold and 6 silver)
    b2.printMoney();///194 gold, 6 silver and 34 copper
    b2.removeMoneyFromBackpack(50,25,0);//removes 50 gold and 25 silver
    b2.printMoney();///143 gold, 81 silver and 34 copper
    b2.removeMoneyFromBackpack(1,83,0);//removes 1 gold and 83 silver
    b2.printMoney();///141 gold, 98 silver and 34 copper
    b2.removeMoneyFromBackpack(40,99,14);//removes 40 gold, 99 silver and 14 copper
    b2.printMoney();///100 gold, 99 silver and 20 copper
    b2.removeMoneyFromBackpack(3,97,27);//removes 3 gold, 97 silver and 27 copper
    b2.printMoney();///97 gold, 1 silver and 93 copper
    b2.removeMoneyFromBackpack(375,1454,4945);//removes 375 gold, 1454 silver and 4945 copper
    b2.printMoney();///0 gold, 0 silver and 0 copper
    cout<<endl;

    Armor aN(ArmorType::leather, 200); //create an armor of type "leather" with defense 200 pts
    aN.addEffect("Shatter", 125);      //add an effect "Shatter" with power 125 pts
    aN.addEffect("Teleport", 225);     //add another effect "Teleport" with power 225 pts
    aN.printAllEffects();              ///Shatter,125 Teleport,225
    cout<<"a1 score:"<<a1.getScore()<<endl<<"aN score:"<<aN.getScore()<<endl;///1250 350
    bool compareScores;  //create a bool variable that will serve as a container for the comparison of two equipments
    compareScores = a1==aN;
    cout<<"Are a1 and aN with equal scores? - "<<compareScores<<endl;///false (1250!=350)
    aN.addEffect("Almighty", 900);//add another effect to the aN armor that will make its total gear score 1250 (equal to the a1 score)
    cout<<"aN score:"<<aN.getScore()<<endl;///1250
    compareScores = a1==aN;
    cout<<"Are a1 and aN with equal scores? - "<<compareScores<<endl;///true (1250==1250)
    compareScores = a1!=aN;
    cout<<"Are a1 and aN with different scores? - "<<compareScores<<endl<<endl;///false (1250==1250)

    Weapon wN;
    wN.addEffect("Equalizer", 1553.25);
    cout<<"w score:"<<w.getScore()<<endl<<"wN score:"<<wN.getScore()<<endl;///4500.38 1164.94
    bool compareDifference;
    compareDifference = w!=wN;
    cout<<"Are w and wN's scores different? - "<<compareDifference<<endl;///true (4500.38!=1164.94)
    compareDifference = w==wN;
    cout<<"Are w and wN's scores the same? - "<<compareDifference<<endl<<endl;///false (4500.38!=1164.94)


    Inventory<Backpack<Materials>> i1; //create a Backpack<Materials>-type object, named "i1"
    i1.setInventory(b1);// sets the inventory to b1 ("cloth,60" with 1 slot(s) taken)
    cout<<"i1 slots:"<<i1.getSlots()<<endl;///1

    Materials mat1, mat2, mat3; //declare three "Materials" objects (with default values, cause we do not need them)
    Backpack<Materials> back2;  //declare one "Backpack<Materials>" object (with default values) - "back2"
    back2.addMaterialToBackpack(mat1); //add the three materials to the backpack
    back2.addMaterialToBackpack(mat2);
    back2.addMaterialToBackpack(mat3);

    Inventory<Backpack<Materials>> i2;  //create a second "Inventory<Backpack>" object
    i2.setInventory(back2);  //set its inventory to "back2"
    cout<<"i2 slots:"<<i2.getSlots()<<endl;///3
    bool comp;
    comp = i1==i2; //compare i1 and i2 (by their taken slots)
    cout<<"Are i1 and i2's taken slots the same quantity? - "<<comp<<endl;///false (1!=3)
    bool compD;
    compD = i1!=i2;
    cout<<"Are i1 and i2's sizes different? - "<<compD<<endl;///true (1!=3)
    back2.removeFromBackpack(2); //remove the second...
    back2.removeFromBackpack(1); //... and the first materials from the backpack
    i2.setInventory(back2);      //again set "back2" as the inventory
    cout<<"i2 slots:"<<i2.getSlots()<<endl;///1
    comp = i1==i2; //compare i1 and i2
    cout<<"Are i1 and i2's taken slots the same quantity? - "<<comp<<endl;///true (1==1)
    compD = i1!=i2;
    cout<<"Are i1 and i2's sizes different? - "<<compD<<endl;///false (1==1)

//    cout << i1;
//    cout << i2;

    return 0;
}

