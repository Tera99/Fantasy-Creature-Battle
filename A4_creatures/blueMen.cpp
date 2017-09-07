/*********************************************************************
 ** Program Filename: bluemen.cpp
 ** Author: Terezie Schaller (Tera)
 ** Date: 5 - 6 - 2016
 ** Description: creature combat game
 ** Input: 2 creatures
 ** Output: outcome of battle between creatures
 *********************************************************************/

#include "blueMen.hpp"

/*********************************************************************
 ** Function: attack
 ** Description: generates attack damage and applies attack effects
 ** Parameters: none
 *********************************************************************/

int BlueMen::attack(){
    std::cout << "~~~Blue Men attack!~~~" << std::endl;
    int pow = dice(2, 10);
    std::cout << "Damage dealt: " << pow << std::endl;
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

bool BlueMen::defend(int attackPow){
    
    std::cout << "~~~Blue Men defend!~~~" << std::endl;
    int defend = dice(((strength + 3) / 4), 6);
    std::cout << "Current strength: " << strength << std::endl;
    std::cout << "Blue Man defense effect: " <<  (strength + 3)/4 << std::endl;
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
            std::cout << "~~~~Blue Men Have all DIED!!!~~~" << std::endl;
        }
    }
    
    //std::cout << "alive?: " << alive << std::endl;
    
    return alive;
}


