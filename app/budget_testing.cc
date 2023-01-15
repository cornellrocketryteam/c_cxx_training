//-------------------------------------------------------------------------
// Chapter 18 Practice: Atomic Operations
//-------------------------------------------------------------------------

#include "spend_money.h"

#include <iostream>
#include <thread>
#include <mutex>

int main( void )
{
    int starting_budget = 1000000;

    // Various expenses
    std::thread payroll  ( &spend_money, 100000, &starting_budget );
    std::thread supplies ( &spend_money,  50000, &starting_budget );
    std::thread rent     ( &spend_money,  75000, &starting_budget );
    std::thread utilities( &spend_money, 200000, &starting_budget );

    // Wait for threads to finish
    payroll.join();
    supplies.join();
    rent.join();
    utilities.join();

    // Print final amount
    std::cout << "Remaining Amount: " << starting_budget << std::endl;
}