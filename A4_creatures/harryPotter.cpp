/*********************************************************************
 ** Program Filename: harrypotter.cpp
 ** Author: Terezie Schaller (Tera)
 ** Date: 5 - 6 - 2016
 ** Description: creature combat game
 ** Input: 2 creatures
 ** Output: outcome of battle between creatures
 *********************************************************************/

#include "harryPotter.hpp"

/*********************************************************************
 ** Function: attack
 ** Description: generates attack damage and applies attack effects
 ** Parameters: none
 *********************************************************************/

int HarryPotter::attack(){
    std::cout << "~~~Harry Potter attacks!~~~" << std::endl;
    int pow = dice(2,6);
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

bool HarryPotter::defend(int attackPow){
    
    std::cout << "~~~Harry Potter defends!~~~" << std::endl;
    
    int defend = dice(2, 6);
    std::cout << "Defense power: " << defend << " Armor: " << armor << std::endl;
    int damage = attackPow - (defend + armor);
    
    if (damage <= 0){
        std::cout << "No damage taken this round!" << std::endl;
    } else {
        strength -= damage;
        std::cout << "Damage taken: " << damage << std::endl;
        std::cout << "Strength: " << strength << std::endl;
        if (strength <= 0){
            if (oneUp>=1){
                strength = 20;
                oneUp--;
                std::cout << "Harry Potter Hogwarts effect! Strength now: " << strength << std::endl;
            } else {
                alive = false;
                
                std::cout << "~~~~Harry Potter has DIED!!!~~~" << std::endl;
            }
        }
    }
    
    //std::cout << "still alive?: " << alive << std::endl;
    return alive;
}


