#include <iostream>
using namespace std;

class GenStack
{
  public:
    //SETUP
    GenStack(); //default constructor
    GenStack(int maxSize);//overload constructor for choice of size
    ~GenStack(); //destructor

    //OPERATIONS
    void push(char data); //push char onto the stack
    char pop(); //returns top elem and removes it
    bool isFull(); //is it full?
    bool isEmpty(); //is it empty?
    char peek(); //returns top value on the stack
    void resize();//automatically makes stack larger once full

    bool check(string filename); //going to check for deliminators, returning true or false

    //VARIABLES
    int mSize; //maximum size of stack
    int top; //variable to keep track of index representing the top of our stack

    char *myArray; // declaring a pointer that will be initialized to a place in memory at run time.
                  //from this we can find any element bc arrays are contiguous
    char t; //temporary variable for check method


};
