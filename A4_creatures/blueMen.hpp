/*********************************************************************
 ** Program Filename: bluemen.hpp
 ** Author: Terezie Schaller (Tera)
 ** Date: 5 - 6 - 2016
 ** Description: creature combat game
 ** Input: 2 creatures
 ** Output: outcome of battle between creatures
 *********************************************************************/

#ifndef blueMen_hpp
#define blueMen_hpp

#include <stdio.h>

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "creature.hpp"

class BlueMen : public Creature {
private:
    int armor = 3;
    
public:
    int attack();
    bool defend(int attackPow);
};

#endif /* blueMen_hpp */
