#include "Person.h"
#include <iostream>
using namespace std;

class Student: public Person{
  public:
    //variables
    string major; //stores major
    int advisorID; //assigns to advisor
    double gpa; //grade point average
    //constructors
    Student();
    ~Student();
    Student(int i, string n, string l, double gpa, string m, int aid);
    //get methods
    string getMajor(); //gets major
    double getGPA(); //returns gpa
    int getAdvisor(); //returns which advisor they have
    //set methods
    string setMajor(string m);
    double setGPA(double a);
    int setAdvisor(int aid);
    //print methods
    void printStudent();

  //private:
  //no private vars/methods
};
