#include "Person.h"
#include <iostream>
using namespace std;

Person::Person(){
  //constructor
}

Person::~Person(){
  //deconstructor
}

string Person::getName(){
  return name;
}

string Person::getLevel(){
  return level;
}

int Person::getID(){
  return ID;
}

void Person::setID(int i){
  ID = i;
}

void Person::setName(string n){
  name = n;
}

void Person::setLevel(string l){
  level = l;
}
