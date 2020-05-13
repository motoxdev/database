#include "Person.h"
#include "DoublyLinkedList.h"
#include <iostream>
using namespace std;

class Faculty:public Person{
  public:
    //variables
    string department;
    unsigned int adviseeID;//advisee ID
    //in directions it says that the advisee number
    //must correspond to a list of ints
    unsigned int maxSize;//digit of num for arr
    int *adviseeArr; //keeps track of all advisee ID's/people

    //methods
    Faculty(); //constructor
    ~Faculty(); //deconstructor
    //using person class & this class to create a faculty member
    Faculty(int ID, string name, string level, string department);
    //get methods
    int getAdviseeID(); //returns id
    string getDepartment(); //returns department
    int getArrSize(); //returns arr size
    //add methods
    void addAdvisee(int ID); //just providing ID to add whole faculty Person
    //bool methods
    bool removeAdvisee(int ID); //removes advisee by ID
    //print methods
    void printFaculty(); //prints everyone
    void printAdvisee();//prints one person



  //private:
  //no private vars/methods
};
