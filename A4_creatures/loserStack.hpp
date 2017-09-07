//
//  loserStack.hpp
//  Assignment4_v2
//
//  Created by Terezie Schaller on 5/18/16.
//  Copyright © 2016 Terezie Schaller. All rights reserved.
//

#ifndef loserStack_hpp
#define loserStack_hpp

#include <stdio.h>

#include "creature.hpp"

class LoserStack{
private:
    class StackNode{
        friend class LoserStack;
        Creature *loser;
        StackNode *next; //pointer to next node
        //Constructor
        StackNode (Creature *loser1, StackNode *next1 = NULL)
        {
            loser = loser1;
            next = next1;
        }
    };
    StackNode *top;
    
public:
    LoserStack() {top = NULL;}
    void push(Creature *ptr);
    void pop();
    Creature * peek();
    bool isEmpty() const;
    
};


#endif /* loserStack_hpp */
