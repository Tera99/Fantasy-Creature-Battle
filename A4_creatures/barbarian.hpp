/*********************************************************************
 ** Program Filename: barbarian.hpp
 ** Author: Terezie Schaller (Tera)
 ** Date: 5 - 6 - 2016
 ** Description: creature combat game
 ** Input: 2 creatures
 ** Output: outcome of battle between creatures
 *********************************************************************/

#ifndef barbarian_hpp
#define barbarian_hpp

#include <stdio.h>

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "creature.hpp"

class Barbarian : public Creature{
private:
    
public:
    int attack();
    bool defend(int attackPow);
};

#endif /* barbarian_hpp */
