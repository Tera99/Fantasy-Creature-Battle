/*********************************************************************
 ** Program Filename: harrypotter.hpp
 ** Author: Terezie Schaller (Tera)
 ** Date: 5 - 6 - 2016
 ** Description: creature combat game
 ** Input: 2 creatures
 ** Output: outcome of battle between creatures
 *********************************************************************/

#ifndef harryPotter_hpp
#define harryPotter_hpp

#include <stdio.h>

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "creature.hpp"

class HarryPotter : public Creature{
private:
    int oneUp = 1;
    int strength = 10;
    
public:
    int attack();
    bool defend(int attackPow);
    
};

#endif /* harryPotter_hpp */
