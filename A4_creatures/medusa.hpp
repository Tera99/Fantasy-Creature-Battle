/*********************************************************************
 ** Program Filename: medusa.hpp
 ** Author: Terezie Schaller (Tera)
 ** Date: 5 - 6 - 2016
 ** Description: creature combat game
 ** Input: 2 creatures
 ** Output: outcome of battle between creatures
 *********************************************************************/

#ifndef medusa_hpp
#define medusa_hpp

#include <stdio.h>

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "creature.hpp"

class Medusa : public Creature{
    
private:
    int armor = 3;
    int strength = 8;
    
public:
    int attack();
    bool defend(int attackPow);
};

#endif /* medusa_hpp */
