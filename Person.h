#include <iostream>
#ifndef included
#define included
using namespace std;

class Person{
  public:
    //variables for person
    string name;
    string level;
    int ID;

    //methods
    Person(); //constructor
    ~Person(); //deconstructor
    //get methods
    string getName(); //returns name
    string getLevel(); //returns level
    int getID();//returns ID
    //set methods
    void setID(int i); //sets ID number
    void setName(string n); //sets name
    void setLevel(string l); //sets level


  //private:
    //no variables here
};
#endif
