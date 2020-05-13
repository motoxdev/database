#include "Faculty.h"
using namespace std;

Faculty::Faculty(){

}

Faculty::~Faculty(){
  delete []adviseeArr; //gets rid of the entire
  //faculty since we keep track of them in the arr
}

Faculty::Faculty(int m, string n, string l, string d){
  //initializing all inputs to be the right vars
  ID = m;
  name = n;
  level = l;
  department = d;

  //create an arr to add them to
  adviseeArr = new int[10];
  adviseeID = 0;
  maxSize = 10;

  //going to make all values in arr the same
  for(int i = 0; i < 10; ++i){
    adviseeArr[i] = 0;
  }
}

int Faculty::getAdviseeID(){
  return adviseeID;
}

string Faculty::getDepartment(){
  return department;
}

int Faculty::getArrSize(){
  return maxSize;
}

void Faculty::addAdvisee(int ID){
  //the ID corresponds to the list of ints
  if(adviseeID != maxSize){
    int var = 0;
    //the case for when this is the firt faculty being added
    for(int i = 0; i < maxSize; ++i){
      if(adviseeArr[i] == ID){
        var = maxSize;
      }
    }
    //makes spot and ID same
    while(var < maxSize){
      if(adviseeArr[var] == 0){
        adviseeArr[var] = ID;
        ++adviseeID;
        break;
      }
      ++var; //adding to next spot
    }
  }
  else{
    if(adviseeID == maxSize){
      int *tempArr = new int[adviseeID];
      //transferring stuff from temp arr to adviseeArr
      for(int i = 0; i < adviseeID; ++i){
        tempArr[i] = adviseeArr[i];
      }
      //moving over one int the array
      adviseeArr = new int [adviseeID + 1];
      maxSize = adviseeID + 1;
      //moving over
      for(int i = 0; i < adviseeID; ++i){
        adviseeArr[i] = tempArr[i];
      }
      //making sure the rest of it is at default
      for(int i = adviseeID; i < adviseeID + 1; ++i){
        adviseeArr[i] = 0;
      }
      adviseeArr[++adviseeID] = ID;
    }
  }
}

bool Faculty::removeAdvisee(int aid){
  //has not been removed yet so making false default
    bool removed = false;
    //filtering through
    for(int i = 0; i < maxSize; ++i){
      //if this spot is equal to what is inputted
      if(adviseeArr[i] == aid){
        //zeroing it out
        adviseeArr[i] = 0;
        //making the amount smaller
        --adviseeID;
        removed = true;
      }
      if(removed == true){
        cout << "ADVISEE REMOVED" << endl;
      }
      return removed;
    }
}

void Faculty::printFaculty(){
  cout << "FACULTY ID: " << ID << endl;
  cout << "FACULTY NAME: " << name << endl;
  cout << "FACULTY LEVEL: " << level << endl;
  cout << "FACULTY DEPARTMENT: " << department << endl;
  cout << "ADVISEE ID'S FOR THIS FACULTY MEMBER: " << endl;
  //lists all their students
  printAdvisee();
}

void Faculty::printAdvisee(){
  //situation for first
  if(adviseeID == 0){
    cout << "NO ADVISEES TO PRINT." << endl;
  }
  else{
    for(int i = 0; i < maxSize; ++i){
      if(adviseeArr[i] != 0){
        cout << adviseeArr[i] << endl;
      }
    }
  }
}
