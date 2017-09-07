/*********************************************************************
 ** Program Filename: lineup.hpp (Assignment 4)
 ** Author: Terezie Schaller (Tera)
 ** Date: 5 - 17 - 2016
 ** Description: lineup creature combat game
 ** Input: creatures
 ** Output: outcome of battle between creatures
 *********************************************************************/
#ifndef lineup_hpp
#define lineup_hpp

#include <stdio.h>
#include "creature.hpp"

class CreatureQ{
private:
    class CreatureNode{
        friend class CreatureQ;
        Creature *fighter;
        CreatureNode *next;
        CreatureNode *prev;
        CreatureNode (Creature *fighter1, CreatureNode *next1 = NULL, CreatureNode *prev1 = NULL){
            fighter = fighter1;
            next = next1;
            prev = prev1;
        }
    };
    
    //track the front and rear of que
    CreatureNode *front;
    CreatureNode *rear;
    
public:
    //constructor and destructor
    CreatureQ();
    ~CreatureQ();
    
    //member functions
    void add(Creature *);
    //void remove(Creature &);
    void remove();
    bool isEmpty() const;
    void clear();
    int length(); //returns length of lineup
    int attack();
    bool defend(int);
    Creature * peek();
    
};



#endif /* lineup_hpp */
