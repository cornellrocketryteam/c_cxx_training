//-------------------------------------------------------------------------
// Chapter 18 Practice: Atomic Operations
//-------------------------------------------------------------------------

#include "spend_money.h"

#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

void spend_money( int amount, int* budget )
{
    //=============================================================
    // PRACTICE TASK:
    //
    // Have this function execute correctly with concurrency
    //=============================================================

    //=============================================================
    // DO NOT EDIT BELOW THIS LINE

    int new_budget = *budget;
    std::cout << "Current Budget: " << new_budget << std::endl;

    // Insert delay to simulate transaction verification
    std::this_thread::sleep_for( std::chrono::milliseconds( 200 ) );
    
    new_budget -= amount;
    std::cout << " - Spent " << amount << " -> New Budget: " << new_budget << std::endl;

    *budget = new_budget;

    // DO NOT EDIT ABOVE THIS LINE    
    //=============================================================

}