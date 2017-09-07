/*********************************************************************
 ** Program Filename: creature.hpp
 ** Author: Terezie Schaller (Tera)
 ** Date: 5 - 6 - 2016
 ** Description: creature combat game
 ** Input: 2 creatures
 ** Output: outcome of battle between creatures
 *********************************************************************/

#ifndef creature_hpp
#define creature_hpp

#include <stdio.h>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

class Creature{
protected:
    bool alive = true;
    int armor = 0;
    int strength = 12;
    std::string name = "";
    
public:
    virtual int attack();
    virtual bool defend(int attackPower);
    int dice(int roll, int side);
    bool getAlive();
    void heal();
    int getStrength();
    void setName(std::string str);
    std::string getName();
    
};

#endif /* creature_hpp */
