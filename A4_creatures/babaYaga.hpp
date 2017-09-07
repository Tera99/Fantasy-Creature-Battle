/*********************************************************************
 ** Program Filename: babayaga.hpp
 ** Author: Terezie Schaller (Tera)
 ** Date: 5 - 6 - 2016
 ** Description: creature combat game
 ** Input: 2 creatures
 ** Output: outcome of battle between creatures
 *********************************************************************/


#ifndef babaYaga_hpp
#define babaYaga_hpp

#include <stdio.h>

#include <iostream>
#include <ctime>
#include <cstdlib>

#include "creature.hpp"

class BabaYaga : public Creature{
private:
    int armor = 3;
    int soulCount = 10;
    
public:
    int attack();
    bool defend(int attackPow);
};

#endif /* babaYaga_hpp */
