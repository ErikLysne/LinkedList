//
//  main.cpp
//  LinkedList
//
//  Created by Erik Lysne on 25.09.2017.
//  Copyright © 2017 Erik Lysne. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "LinkedList.h"

int main(int argc, const char * argv[]) {
    
    unsigned int seedRand = static_cast<unsigned int>(time(NULL));
    srand(seedRand);
    
    LinkedList<int> myList;
    for(int i = 0; i < 100; i++)
    {
        int randNum = rand() % 100 + 1;
        myList.pushBack(randNum);
    }
    
    std::cout << "Randomly generated list before sorting:" << std::endl;
    myList.printContent();
    
    myList.sort();
    
    std::cout << "=================================================" << std::endl;
    std::cout << "=================================================" << std::endl;
    std::cout << "=================================================" << std::endl;
    
    std::cout << "Randomly generated list after sorting:" << std::endl;
    myList.printContent();
    
    
    return 0;
}
