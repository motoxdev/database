#include "Student.h"
using namespace std;

Student::Student(){

}

Student::~Student(){

}

Student::Student(int i, string n, string l, string m, double a, int aid){
  ID = i;
  name = n;
  level = l;
  major = m;
  gpa = a;
  advisorID = aid;
}

string Student::getMajor(){
  return major;
}

double Student::getGPA(){
  return gpa;
}

int Student::getAdvisor(){
  return advisorID;
}

string Student::setMajor(string m){
  major = m;
}

double Student::setGPA(double a){
  gpa = a;
}

int Student::setAdvisor(int aid){
  advisorID = aid;
}

void Student::printStudent(){
  cout << "STUDENT ID: " << ID << endl;
  cout << "STUDENT NAME: " << name << endl;
  cout << "STUDENT GRADE: " << level << endl;
  cout << "STUDENT MAJOR: " << major << endl;
  cout << "STUDENT GPA: " << gpa << endl;
  cout << "STUDENT'S ADVISOR ID:" << advisorID << endl;
}
