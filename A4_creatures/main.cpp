/*********************************************************************
 ** Program Filename: main.cpp (Assignment 4)
 ** Author: Terezie Schaller (Tera)
 ** Date: 5 - 17 - 2016
 ** Description: lineup creature combat game
 ** Input: creatures
 ** Output: outcome of battle between a lineup of creatures
 *********************************************************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <string>

#include "creature.hpp"
#include "barbarian.hpp"
#include "harryPotter.hpp"
#include "medusa.hpp"
#include "babaYaga.hpp"
#include "blueMen.hpp"
#include "creatureQ.hpp"
#include "loserStack.hpp"

bool battle(Creature * a, Creature * b);
void menu();
Creature * selectPlayer(int choice);
CreatureQ loadQ(int numChoices);

Barbarian conan;
HarryPotter harry;
Medusa jan;
BabaYaga greta;
BlueMen bob;
Barbarian barbie;

CreatureQ lineupA;
CreatureQ lineupB;
LoserStack losers;

int main() {
    
    //seed random generator ONCE
    unsigned seed;
    seed = time(0);
    srand(seed);
    
    //Get number of combatants from user
    int userNum;
    std::cout << "How many combatants in the lineup? " << std::endl;
    
    //validate input
    while (true)
    {
        std::cin >> userNum;
        
        if (std::cin && userNum > 0)
            break;
        
        std::cin.clear();
        std::cin.ignore( 1000, '\n' );
        std::cout << "Try again. Please enter a positive integer." << std::endl;
    }

    
    //Make Player A's lineup
    std::cout << std::endl;
    std::cout << "Player A: enter your combatants." << std::endl;
    std::cout << std::endl;
    menu();
    
    //load Q
    for (int i = 0; i < userNum; i++){
        int choice;
        std::cout << "Choose a creature type. Int + ENTER: " << std::endl;
        
        //validate input
        while (true)
        {
            std::cin >> choice;
            
            if (std::cin && choice > 0 && choice <=5)
                break;
            
            std::cin.clear();
            std::cin.ignore( 1000, '\n' );
            std::cout << "Try again. Please enter a number between 1 and 5." << std::endl;
        }

        
        Creature * cPtr;
        cPtr = selectPlayer(choice);
        std::string name;
        std::cout << "Enter name with no spaces, please: " << std::endl;
        std::cin >> name;
        cPtr->setName(name);
        lineupA.add(cPtr);
        std::cout << "====================================================" << std::endl;
    }
    
    
    //Make Player B's lineup
    std::cout << std::endl;
    std::cout << "Player B: enter your combatants." << std::endl;
    std::cout << std::endl;
    
    menu();
    
    //loadQ
    for (int i = 0; i < userNum; i++){
        int choice;
        std::cout << "Choose a creature type. Int + ENTER: " << std::endl;
        
        //validate input
        while (true)
        {
            std::cin >> choice;
            
            if (std::cin && choice > 0 && choice <= 5)
                break;
            
            std::cin.clear();
            std::cin.ignore( 1000, '\n' );
            std::cout << "Try again. Please enter a number between 1 and 5." << std::endl;
        }

        
        Creature * cPtr;
        cPtr = selectPlayer(choice);
        std::string name;
        std::cout << "Enter name with no spaces, please: " << std::endl;
        std::cin >> name;
        cPtr->setName(name);
        lineupB.add(cPtr);
        std::cout << "====================================================" << std::endl;
    }
    
    std::cout << "Creatures in lineup A: " << lineupA.length() << std::endl;
    std::cout << "Creatures in lineup B: " << lineupB.length() <<std::endl;
    
    //battle top creatures in each lineup
    do{
        //get top creatures from lineup
        Creature *a = lineupA.peek();
        lineupA.remove();
        
        Creature *b = lineupB.peek();
        lineupB.remove();
    
        bool myGame;
        
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        std::cout << "Let the battle BEGIN!!" << std::endl;
        std::cout << a->getName() << " VS " << b->getName() << std::endl;
        std::cout << "~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
        
        do{
            
            //battle top creatures
            myGame = battle(a, b);
            
            
        } while (myGame == true);
        
        
        //print score
        std::cout <<std::endl;
        std::cout << "SCORE" << std::endl;
        std::cout << "lineup A: " << lineupA.length() << std::endl;
        std::cout << "lineup B: " << lineupB.length() << std::endl;
        std::cout << std::endl;
        
    } while (lineupA.isEmpty()==false && lineupB.isEmpty()==false);
    //continue as long as both lineups have creatures
    
    std::cout << std::endl;
    std::cout << "*****************************" << std::endl;
    std::cout << "*****************************" << std::endl;
    std::cout << "**                         **" << std::endl;
    std::cout << "**        RESULTS          **" << std::endl;
    std::cout << "**                         **" << std::endl;
    std::cout << "*****************************" << std::endl;
    std::cout << "*****************************" << std::endl;
    std::cout <<std::endl;
    
    //print final score
    
    std::cout << std::endl;
    std::cout << "FINAL SCORE" << std::endl;
    std::cout << "lineup A: " << lineupA.length() << std::endl;
    std::cout << "lineup B: " << lineupB.length() << std::endl;
    std::cout << std::endl;
    
    //determine winning team & top players
    
    int scoreA = lineupA.length();
    int scoreB = lineupB.length();
    
    if (scoreA > scoreB && userNum > 1){
        std::cout << "Team A is the winner!" << std::endl;
        std::cout << std::endl;
        std::cout << "The top players are: " <<std::endl;
        
        int winners = 0;
        while (winners<3){
            if (lineupA.isEmpty()==true){
                std::cout << losers.peek()->getName() << std::endl;
                losers.pop();
            } else {
                std::cout << lineupA.peek()->getName() <<std::endl;
                lineupA.remove();
            }
            winners++;
        }
        
    } else if (scoreB > scoreA && userNum > 1) {
        std::cout << "Team B is the winner!" <<std::endl;
        std::cout << std::endl;
        std::cout << "The top players are: " << std::endl;
        
        int winners = 0;
        while (winners<3){
           
            if (lineupB.isEmpty()==true){
                std::cout << losers.peek()->getName() << std::endl;
                losers.pop();
            } else {
                std::cout << lineupB.peek()->getName() <<std::endl;
                lineupB.remove();
            }
            winners++;
        }
        
        
    } else if (scoreB > scoreA && userNum == 1){
        std::cout << "Team B is the winner." << std::endl;
        std::cout << "Top player: " << lineupB.peek()->getName() <<std::endl;
        lineupB.remove();
    } else if (scoreA > scoreB && userNum == 1){
        std::cout << "Team A is the winner." << std::endl;
        std::cout << "Top player: " << lineupA.peek()->getName() <<std::endl;
        lineupA.remove();
    } else {
        std::cout << "Error. No winner." << std::endl;
    }
  
    //show the remaining players if user desires
    
    char seeList;
    std::cout << std::endl;
    std::cout << "Do you want to see the rest of the list? Y/N" <<std::endl;
    std::cin >> seeList;
    
    if (seeList == 'Y' || seeList == 'y'){
        while(!lineupA.isEmpty()){
            std::cout << lineupA.peek()->getName() << std::endl;
            lineupA.remove();
        }
        
        while (!lineupB.isEmpty()){
            std::cout << lineupB.peek()->getName() << std::endl;
            lineupB.remove();
        }
        
        while (!losers.isEmpty()){
            std::cout << losers.peek()->getName() << std::endl;
            losers.pop();
        }
    }
    
    return 0;
}

/*********************************************************************
 ** Function: battle
 ** Description: runs battle between two creature
 ** Parameters: 2 creature pointer
 ** Pre-Conditions: at least 2 creature objects
 ** Post-Conditions: 2 creatures have battled
 *********************************************************************/

bool battle(Creature * a, Creature * b){
    bool game = true;
    
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    
    
    if(a->getAlive()==true && b->getAlive()==true){
        
        int attackPow1 = a->attack();
        b->defend(attackPow1);
        
        if (b->getAlive()==true){
            int attackPow2 = b->attack();
            a->defend(attackPow2);
        }
        
    } else if(a->getAlive()==false) {
        game = false;
        std::cout << "Game Over!!" << std::endl;
        std::cout << a->getName() << " has died!" << std::endl;
        losers.push(a);
        b->heal();
        lineupB.add(b);
        
    } else if(b->getAlive()==false) {
        game = false;
        std::cout << "Game Over!!" << std::endl;
        std::cout << b->getName() << " has died!" << std::endl;
        losers.push(b);
        a->heal();
        lineupA.add(a);
    }
    
    std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
    
    return game;
}

/*********************************************************************
 ** Function: menu
 ** Description: displays the creature menu
 ** Parameters: none
 ** Pre-Conditions: none
 ** Post-Conditions: none
 *********************************************************************/

void menu(){
    std::cout << "====================================================" << std::endl;
    std::cout << "Enter an integer + ENTER to choose your combatants: " << std::endl;
    std::cout << "1 - Barbarian" << std::endl;
    std::cout << "2 - Harry Potter" << std::endl;
    std::cout << "3 - Medusa" << std::endl;
    std::cout << "4 - Baba Yaga" << std::endl;
    std::cout << "5 - Blue Men" << std::endl;
    std::cout << "====================================================" << std::endl;
}

/*********************************************************************
 ** Function: selectPlayer
 ** Description: takes an integer representing a user choice and returns
 ** the appropriate creature pointer
 ** Parameters: integer
 ** Pre-Conditions: works with menu()
 ** Post-Conditions: returns a creature pointer
 *********************************************************************/

Creature * selectPlayer(int choice){
    
    switch (choice) {
            
        case 1 :
            //Barbarian
            Creature *conan;
            conan = new Barbarian;
            return conan;
            break;
            
        case 2 :
            //Harry Potter
            Creature *harry;
            harry = new HarryPotter;
            return harry;
            break;
            
        case 3 :
            //Medusa
            Creature *jan;
            jan = new Medusa;
            return jan;
            break;
            
        case 4 :
            //Baba Yaga
            Creature *greta;
            greta = new BabaYaga;
            return greta;
            break;
            
        case 5 :
            //Blue Men
            Creature *bob;
            bob = new BlueMen;
            return bob;
            break;
            
        default :
            // Process for all other cases.
            std::cout << "Error. You get a Barbarian" << std::endl;
            Creature *barbie;
            barbie = new Barbarian;
            return barbie;
            break;
            
    }
    
}



