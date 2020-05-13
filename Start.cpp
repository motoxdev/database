#include "Start.h"
using namespace std;

Start::Start(){

}

Start::~Start(){

}

void Start::printHello(){
  cout << "STUDENT/FACULTY DATABASE" << endl;
  showStart();
}

void Start::showStart(){
  cout << "TYPE IN ONE OF THE FOLLOWING NUMBERS TO PERFORM THAT FUNCTION" << endl;
  cout << "1. PRINT ALL STUDENTS WITH INFORMATION" << endl;
  cout << "2. PRINT ALL FACULTY WITH INFORMATION" << endl;
  cout << "3. FIND AND DISPLAY STUDENT INFORMATION GIVEN STUDENT ID" << endl;
  cout << "4. FIND AND DISPLAY FACULTY INFORMATION GIVEN FACULTY ID" << endl;
  cout << "5. GIVEN A STUDENT ID, PRINTS THEIR FACULTY ADVISOR'S INFORMATION" << endl;
  cout << "6. GIVEN A FACULTY ID, PRINTS ALL THEIR ADVISEES" << endl;
  cout << "7. ADD NEW STUDENT" << endl;
  cout << "8. DELETE A STUDENT WITH AN ID #" << endl;
  cout << "10. DELETE FACULTY MEMBER WITH AN ID #" << endl;
  cout << "11. CHANGE STUDENT'S ADVISOR GIVEN STUDENT ID AND NEW FACULTY ID" << endl;
  cout << "12. REMOVE ADVISEE FROM FACULTY MEMBER GIVEN BOTH ID'S" << endl;
  cout << "13. ROLLBACK" << endl;
  cout << "14. EXIT" << endl;
}
