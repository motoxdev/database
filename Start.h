#include <iostream>
using namespace std;

class Start{
  public:
    //constructors
    Start(); //constructor
    ~Start(); //deconstructor

    void printHello(); //what the user will see when it starts up
    void showStart(); //shows the possible selections
  private:
    int r; //gives them a way to select paths

};
