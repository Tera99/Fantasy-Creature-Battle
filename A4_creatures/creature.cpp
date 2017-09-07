/*********************************************************************
 ** Program Filename: creature.cpp
 ** Author: Terezie Schaller (Tera)
 ** Date: 5 - 6 - 2016
 ** Description: creature combat game
 ** Input: 2 creatures
 ** Output: outcome of battle between creatures
 *********************************************************************/
#include "creature.hpp"

/*********************************************************************
 ** Function: attack
 ** Description: generates attack damage and applies attack effects
 ** Parameters: none
 *********************************************************************/

int Creature::attack(){
    std::cout << "Creature attacks" << std::endl;
    int pow = 0;
    return pow;
}

/*********************************************************************
 ** Function: defend
 ** Description: takes an integer representing attack power and calculates
 ** damage taken, applies defense effects, updates strength and returns
 ** a bool alive
 ** Parameters: integer attackPow
 ** Pre-Conditions: none
 ** Post-Conditions: strength updated
 *********************************************************************/

bool Creature::defend(int attackPower){
    bool alive = true;
    std::cout << "Creature defends" << std::endl;
    return alive;
}

/*********************************************************************
 ** Function: dice
 ** Description: simulates the roll of dice of various side
 ** Parameters: number of dice rolled, sides of die
 ** Pre-Conditions: none
 ** Post-Conditions: returns an integer
 *********************************************************************/

int Creature::dice(int roll, int side){
    
    int myNum = rand() % side + 1;
    //std::cout << "dice: " << myNum << std::endl;
    
    myNum = (roll * myNum);
    
    return myNum;
}

/*********************************************************************
 ** Function: getAlive
 ** Description: reuturns the value of the avlive variable
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: returns a bool
 *********************************************************************/

bool Creature::getAlive(){
    return alive;
}

/*********************************************************************
 ** Function: heal
 ** Description: increases the healed creatures strength by a random
 ** amount between 1 and 20.
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: creature's strength is increased
 *********************************************************************/


void Creature::heal(){
    int exp = rand() % 20 + 1;
    strength += exp;
    std::cout << "Heal effect: +" << exp << " to " << name << "'s strength." << std::endl;
    
}

/*********************************************************************
 ** Function: getStrength
 ** Description: returns the creature's current strength
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: returns an integer
 *********************************************************************/

int Creature::getStrength(){
    return strength;
}

/*********************************************************************
 ** Function: setName
 ** Description: sets the character's name
 ** Parameters: string
 ** Pre-Conditions: a creature
 ** Post-Conditions: gives the creatures a custom name
 *********************************************************************/

void Creature::setName(std::string str){
    name = str;
}

/*********************************************************************
 ** Function: getName
 ** Description: returns the creature's name
 ** Parameters: none
 ** Pre-Conditions: a named creature
 ** Post-Conditions: returns a string
 *********************************************************************/

std::string Creature::getName(){
    return name;
}


