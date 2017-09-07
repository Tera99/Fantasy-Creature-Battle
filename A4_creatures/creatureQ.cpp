/*********************************************************************
 ** Program Filename: lineup.cpp (Assignment 4)
 ** Author: Terezie Schaller (Tera)
 ** Date: 5 - 17 - 2016
 ** Description: lineup creature combat game
 ** Input: creatures
 ** Output: outcome of battle between creatures
 *********************************************************************/

#include "creatureQ.hpp"
#include <iostream>

/******************************
 **constructor
 *****************************/

CreatureQ::CreatureQ(){
    front = NULL;
    rear = NULL;
    
}

/*******************************
 **destructor
 ******************************/

CreatureQ::~CreatureQ(){
    std::cout << "this is the destructor" << std::endl;
    clear();
}

/***********************************************************
 **Function: add
 **Description: inserts the creature pointer
 **at the REAR of the queue
 **Parameters: creature pointer
 ************************************************************/

void CreatureQ::add(Creature *user){
    if (isEmpty()){
        std::cout << "Adding first creature: " << user->getName() <<std::endl;
        front = new CreatureNode(user);
        rear = front;
    } else {
        std::cout << "Adding creature to queue: " << user->getName() <<std::endl;
        rear->next = new CreatureNode(user);
        rear->prev = rear;
        rear = rear->next;
    }
}

/**********************************************************
 **Function: remove
 **description: removes the value at the FRONT of the q
 **Parameters: none
 **********************************************************/
void CreatureQ::remove(){
    CreatureNode *temp;
    if (isEmpty()){
        std::cout << "The queue is empty." << std::endl;
        exit(1);
    } else {
        temp = front; //assign front to temp
        front = front->next; //move front to next in queue
        delete temp; //delete the old front node stored at temp
    }
    
}


/*********************************************************
 **Function: isEmpty
 **Description: returns true if queue is empty
 **Parameters: none
 *********************************************************/

bool CreatureQ::isEmpty() const{
    if (front==NULL)
        return true;
    else
        return false;
}

/*********************************************************
 **Function: clear
 **Description: removes all elements in the queue
 ********************************************************/

void CreatureQ::clear(){
    //Creature *dummy;
    
    while (!isEmpty())
        remove();
}

/************************************************************
 **Function: length
 **Description: returns the number of elements in lineup
 **Parameters: none
 *************************************************************/

int CreatureQ::length(){
    int n;
    if (isEmpty()){
        n = 0;
    } else {
        n = 1;
        CreatureNode *curr = front;
        
        while (curr != rear){
            n++;
            curr = curr -> next;
        }
        
    }
    
    return n;
}

/******************************************************************
 **Function: attack
 **Descrition: calls attack function of first creature in the queue
 **Parameters: none
 ******************************************************************/

int CreatureQ::attack(){
    int x;
    x = front->fighter->attack();
    return x;
}

/*********************************************************************
 **Function: defend
 **Description: first creature in queue takes damage
 **Paramters: integer representing attack damage absorbed
 *******************************************************************/

bool CreatureQ::defend(int pow){
    
    front->fighter->defend(pow);
    
    return front->fighter->getAlive();
}

/*********************************************************************
 **Function: peek
 **Description: returns first creature in the queue
 **Paramters: none
 *********************************************************************/

Creature * CreatureQ::peek(){
    
    if (isEmpty()){
        return NULL;
    } else {
        return front->fighter;
    }
    
}





