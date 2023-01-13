//-------------------------------------------------------------------------
// Chapter 14 Practice: Static Polymorphism
//-------------------------------------------------------------------------

#ifndef SRC_CALCULATOR
#define SRC_CALCULATOR

class Calculator
{
  public:
    Calculator( int src1, int src2 );

    int add();
    int subtract();
    int multiply();
    int divide();

    void display_results();

  private:
    int op1;
    int op2;
};

// Include definitions
#include "calculator.inl"

#endif // SRC_CALCULATOR