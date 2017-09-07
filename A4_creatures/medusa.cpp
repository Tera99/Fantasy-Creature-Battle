/*********************************************************************
 ** Program Filename: medusa.cpp
 ** Author: Terezie Schaller (Tera)
 ** Date: 5 - 6 - 2016
 ** Description: creature combat game
 ** Input: 2 creatures
 ** Output: outcome of battle between creatures
 *********************************************************************/
#include "medusa.hpp"

/*********************************************************************
 ** Function: attack
 ** Description: generates attack damage and applies attack effects
 ** Parameters: none
 *********************************************************************/

int Medusa::attack(){
    std::cout << "~~~Medusa attacks!~~~" << std::endl;
    int pow = dice(2,6);
    std::cout << "Damage dealt: " << pow << std::endl;
    if (pow == 12){
        std::cout << "Medusa Effect! You are stone!" << std::endl;
        pow = 1000;
    }
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

bool Medusa::defend(int attackPow){
    
    std::cout << "~~~Medusa defends!~~~" << std::endl;
    int defend = dice(1, 6);
    std::cout << "Defense power: " << defend << " Armor: " << armor << std::endl;
    int damage = attackPow - (defend + armor);
    
    if (damage <= 0){
        std::cout << "No damage taken this round!" << std::endl;
    } else {
        strength -= damage;
        std::cout << "Damage taken: " << damage << std::endl;
        std::cout << "Strength: " << strength << std::endl;
        if (strength <= 0){
            alive = false;
            std::cout << "~~~~Medusa has DIED!!!~~~" << std::endl;
        }
    }
    
    return alive;
    
}



