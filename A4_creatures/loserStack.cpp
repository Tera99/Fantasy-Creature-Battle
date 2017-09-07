//
//  loserStack.cpp
//  Assignment4_v2
//
//  Created by Terezie Schaller on 5/18/16.
//  Copyright © 2016 Terezie Schaller. All rights reserved.
//

#include "loserStack.hpp"

#include <iostream>

/*******************************************
 ** Function: push
 ** Description: pushes the argument onto the staxk
 ** Parameters: an int
 *******************************************/

void LoserStack::push(Creature * myLoser){
    top = new StackNode(myLoser, top);
}

/*******************************************
 ** Function: pop
 ** Descrption: removes the value at the top
 ** of the stack and copies it into the variable
 ** passes as an argument
 ** Paramters: none
 ******************************************/

void LoserStack::pop(){
    
    StackNode *temp;
    
    if (isEmpty()){
        std::cout << "The stack is empty." << std::endl;
        exit(1);
    } else {
        
        temp = top;
        top = top->next;
        delete temp;
    }
    
}

/********************************************
 **Function: isEmpty
 **Description: returns true if the stack is empty
 **otherwise returns false
 **Paramters: none
 *******************************************/

bool LoserStack::isEmpty() const {
    if (!top)
        return true;
    else
        return false;
}

/*********************************************
 **Function: peek
 **Description: returns the top value on
 **the stack
 **Paramters: none
 **********************************************/

Creature * LoserStack::peek(){
    return top->loser;
}
