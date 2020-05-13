#include "Simulation.h"
#include <fstream> //files
#include <string>
#include <iostream>
using namespace std;

Simulation::Simulation(){

}

Simulation::~Simulation(){

}

TreeNode<Student>* Simulation::getTreeStudentRoot(){
  return treeStudent.getRoot();
}

TreeNode<Faculty>* Simulation::getTreeFacultyRoot(){
    return treeFaculty.getRoot();
}

void Simulation::printTreeStudent(TreeNode<Student> *st){
  if(st != NULL){
    //left side of the tree
    if (st->left != NULL){
      printTreeStudent(st->left);
    }
    st->data->printStudent(); //printing that student at that node
    //right side of the tree
    if(st->right != NULL){
      printTreeStudent(st->right);
    }
  }
  else{
    cout << "STUDENT TREE IS EMPTY" << endl;
  }
}

void Simulation::outputTreeStudent(TreeNode<Student> *st, string file){
  ofstream f;
  //f.open(file,true);
  if(st != NULL){
    cout << "FILE NAME: " << file << endl;
    //now we are going to create the so-called table within the file they gave us to write to
    f << "__________" << endl;
    f << st->data->getID() << endl;
    f << st->data->getName() << endl;
    f << st->data->getLevel() << endl;
    f << st->data->getMajor() << endl;
    f << st->data->getAdvisor() << endl;

    //going to reuse above for the left side of tree
    if(st->left != NULL){
      outputTreeStudent(st->left, file);
    }
    //goingto reuse above for the right side of the tree
    if(st->right != NULL){
      outputTreeStudent(st->right, file);
    }
  }
  f.close(); //closes the file
}

void Simulation::showStudentInfo(int i){
  if(treeStudent.search(i)){
    treeStudent.search(i)->printStudent();
  }
  else{
    cout << "STUDENT NOT FOUND." << endl;
  }
}

void Simulation::addStudent(){
  //dummy variables for student vars
  int i;
  string n;
  string l;
  double a;
  string m;
  int aid;
  //answer formats
  string answer = "";
  double answerDouble = 0.0;
  int answerInt = 0;
  while(true){
    cout << "INPUT ID OF STUDENT YOU WISH TO ADD" << endl;
    answerInt = 0;
    answer = "";
    cin >> answer;
    try{
      i = stoi(answer);
      if(i > 0){
        if(!treeStudent.search(i)){
          break; //checking to see if id is valid
        }
        else{
          cout << "ID TAKEN, INPUT ANOTHER ID  FOR STUDENT" << endl;
        }
      }
      else{
        cout << "INVALID, PLEASE TYPE ANOTHER" << endl;
      }
    }
    catch(exception i){
      cout << "INVALID, PLEASE TRY AGAIN" << endl;
    }
  }
cout << "TYPE IN THE FOLLOWING FOR NEW STUDENT" << endl;
cout << "NAME: " << endl;
cin.ignore();
getline(cin, n);
cout << "GRADE LEVEL: " << endl;
getline(cin, l);
while(true){
  cout << "GPA: " << endl;
  answerDouble = 0;
  answer = "";
  cin >> answer;
  try{
    a = stod(answer);
    if((a > 0) &&(a < 5)){ //limiting gpa answer between 0 and 5
      break;
    }
    else{
      cout <<  "INVALID GPA. PLEASE TRY AGAIN." << endl;
    }
  }
  catch(exception i){
    cout << "INVALID INPUT. PLEASE TRY AGAIN." << endl;
  }
}
cout << "MAJOR: " << endl;
cin.ignore(); //using for all string answers
getline(cin, m);

if(!treeFaculty.isEmpty()){
  cout << "DOES NEW STUDENT HAVE AN ADVISOR" << endl;
  cout << "TYPE 1 FOR YES, OR 2 FOR NO" << endl;
  while(true){
    //making everything default as these are my dummy variables
    answerInt = 0;
    answer = "";
    cin >> answer;
    try{
      answerInt = stoi(answer);
      if((answerInt == 1) || (answerInt == 2)){
        break; //valid responded
      }
    }
    catch (exception i){
      cout << "INVALID INPUT. PLEASE TRY AGAIN." << endl;
    }
  }

//now going to perform depending on their correct numerical response
if(answerInt == 1){
  cout << "INPUT THE FOLLOWING INFORMATION FOR THIS STUDENT'S ADVISOR" << endl;
  cout << "ADVISOR ID: " << endl;
  while(true){
    //defaulting dummy variables
    answerInt = 0;
    answer = "";
    cin >> answer;
    try{
      a = stoi(answer);
      //checking to see if this advisor search in the faculty tree
      if(treeFaculty.search(a)){
        Faculty *f = treeFaculty.search(a); //searching for this faculty member and making them f
        f->addAdvisee(i); //adding the student to that faculty's list
        break;
      }
      else{
        cout << "INVALID FACULTY ID. PLEASE TRY AGAIN" << endl;
      }
    }
    catch (exception i){
      cout << "PLEASE ENTER AN ID IN THE FORM OF AN INTEGER" << endl;
    }
  }
}
  else{
    a = 0; //defaulting the spot
  }
}
else{
  a = 0;
}
//creating the new student
Student *ns = new Student(i,n,l,a,m,a);
//TreeNode<Student> *sn = new TreeNode<Student>(sn, i);
//treeStudent.insert(sn);
}

void Simulation::printTreeFaculty(TreeNode<Faculty>*f){
  if(f != NULL)
  {
    if(f->left != NULL){
      printTreeFaculty(f->left);
    }
    f->data->printFaculty();
    if(f->right != NULL){
      printTreeFaculty(f->right);
    }
  }
  else{
    cout << "FACULTY TREE EMPTY." << endl;
  }
}

void Simulation::outputTreeFaculty(TreeNode<Faculty> *fac, string s){
  ofstream f;
  //f.open(s,true);
  if(fac != NULL){
    //outputting to file
    f << "__________" << endl;
    f << fac->data->getID() << endl;
    f << fac->data->getName() << endl;
    f << fac->data->getLevel() << endl;
    f << fac->data->getDepartment() << endl;
    f << fac->data->getAdviseeID() << endl;

    if(fac->data->getAdviseeID() > 0){
      //filtering through array
      for(int i = 0; i < fac->data->maxSize; ++i){
        if(fac->data->adviseeArr[i] != 0){
          //checking to see if this is a valid advisor
          f << fac->data->adviseeArr[i] << endl;
        }
      }
    }
    //now resuming to output like we did with students
    if(fac->left != NULL){
      outputTreeFaculty(fac->left, s);
    }
    if(fac->right != NULL){
      outputTreeFaculty(fac->right,s);
    }
  }
  else{
    cout << "FACULTY TREE IS EMPTY." << endl;
  }
  f.close(); //closing the file
}

void Simulation::showFacultyInfo(int i){
  //if this faculty person search in tree
  if(treeFaculty.search(i)){
    //search of this person and then print their information out
    treeFaculty.search(i)->printFaculty();
  }
  else{
    //they are not in the tree and outputting to the user
    cout << "FACULTY PERSON NOT IN THE FACULTY TREE" << endl;
  }
}

void Simulation::addFaculty(){
  int i;
  string n;
  string l;
  string d;
  //default dummy variables for responses like in the student method
  string answer = "";
  int answerInt = 0;
  int numEntries = 0;
  while(true){
    cout << "PLEASE FILL OUT FOLLOWING INFORMATION ABOUT NEW FACULTY MEMBER" << endl;
    cout << "FACULTY MEMBER ID: " << endl;
    answerInt = 0;
    answer = "";
    cin >> answer;
    try{
      i = stoi(answer);
      if(i>0){
        break; //valid answer and search
      }
    }
    catch(exception i){
      cout << "INVALID FACULTY MEMBER ID. PLEASE TRY AGAIN." << endl;
    }
  }
  cout << "NAME: " << endl;
  cin.ignore();
  getline(cin, n);
  cout << "LEVEL: " << endl;
  getline(cin, l);
  cout << "DEPARTMENT: " << endl;
  getline(cin, d);
  //now using overloaded constructor to make new faculty member
  Faculty *f = new Faculty(i,n,l,d);
  //filling out the students they advise if they have any
  if(!treeFaculty.isEmpty()){
    cout << "DOES FACULTY MEMBER HAVE ADVISEES" << endl;
    cout << "TYPE 1 FOR YES, 2 FOR NO" << endl;
    while(true){
      //defaulting dummy responses
      answerInt = 0;
      answer = "";
      cin >> answer;
      try{
        answerInt = stoi(answer); //converting to int
        if((answerInt == 1) || (answerInt==2)){
          break; //has a valid answer
        }
      }
      catch (exception i){
        cout << "INVALID ANSWER. PLEASE TRY AGAIN" << endl;
      }
    }
    if((answerInt == 1) && !treeStudent.isEmpty()){
      cout << "# OF STUDENTS THIS FACULTY MEMBER ADVISES: " << endl;
      while(true){
        cout << "PLEASE ENTER ONLY INTEGERS" << endl;
        //clearing default dummies
        answerInt = 0;
        answer = "";
        cin >> answer;
        try{
          answerInt = stoi(answer); //converting
          if((answerInt > 0) && (answerInt <= treeStudent.getSize())){
            numEntries = answerInt; //setting the correct size
            break; //satisfies
          }
          else{
            cout << "PLEASE ENTER INTEGER <= " << treeStudent.getSize() << endl;
          }
        }
        catch(exception i){
          cout << "INVALID INPUT. PLEASE ENTER ANOTHER INTEGER" << endl;
        }
      }

      for(int j = 0; j < numEntries; ++j){
        while(true){
          cout << "PLEASE ENTER THE STUDENT ID # OF ADVISEE" << endl;
          //defaulting dummy variables
          answerInt = 0;
          answer = "";
          cin >> answer;
          try{
            answerInt = stoi(answer);
            if(treeStudent.search(answerInt)){
              f->addAdvisee(answerInt);//adding that student to the faculty's advisee list
              treeStudent.search(answerInt)->setAdvisor(i);
              break; //satisfies and completed
            }
            else{
              cout << "STUDENT NOT IN SYSTEM." << endl;
            }
          }
          catch(exception i){
            cout << "INVALID. PLEASE ENTER ANOTHER INTEGER" << endl;
          }
        }
      }
    }
  }
  //officially adding the student to the faculty member within the faculty BST
  TreeNode<Faculty> *fc = new TreeNode<Faculty>(f,i);
  treeFaculty.insert(fc);
}

void Simulation::readFile(string importedFile1, string importedFile2){
  ifstream treeStudentFile;
  ifstream treeFacultyFile;
  //student file
  int i;
  string n;
  string l;
  double a;
  string m;
  int aid;
  string line;
  int numS = 0;
  int lineCount = 1;

  treeStudentFile.open(importedFile1);
  if(treeStudentFile.is_open()){
    try{
      getline(treeStudentFile,line); //just like in the DNA sequence assignment
      if(line != ""){
        //if line isn't empty
        numS = stoi(line);
      }
    }
    catch(exception i){
      cout << "INCORRECT LAYOUT OF TEXT FILE" << endl;
    }
    //7 for completing a file input of one student
    for(int j = 0; j < (7*numS);++j){
      getline(treeStudentFile, line); //same as DNA sequence of getting from text file
      //USE THE SWITCH STATEMENT HERE***********************************************************
      switch(lineCount){
        case 1:{
          if(line != "__________"){
            cout << "FORMAT FROM FILE IS INCORRECT" << endl;
          }
          break;
        }
        case 2:{
          try{
            i = stoi(line);
          }
          catch(exception i){
            cout << "FORMAT FROM FILE IS INCORRECT" << endl;
          }
          break;
        }
        case 3:{
          n = line; //should get the name if set up right
          break;
        }
        case 4:{
          l = line;
          break;
        }
        case 5:{
          try{
            a = stod(line);
          }
          catch(exception i){
            cout << "FORMAT FROM FILE IS INCORRECT" << endl;
          }
          break;
        }
        case 6:{
          m = line; //major should be on this line of th text file
          break;
        }
        case 7:{
          try{
            aid = stoi(line); //advisor id
            //creating the new student
            Student *s = new Student(i,n,l,a,m,aid);
            TreeNode<Student> *sn = new TreeNode<Student>(s,i);
            //student officially apart of the student BST tree
            treeStudent.insert(sn);
          }
          catch(exception i){
            cout << "FORMAT FROM FILE IS INCORRECT" << endl;
          }
          break; //ends
        }
        default:break;
      }
      ++lineCount;
      if(lineCount > 7){
        lineCount = 1;
      }
    }
  }
  else{
    cout << "FILE INCORRECT. STARTING SIMULATION WITHOUT ANY STUDENTS IN SYSTEM." << endl;
  }
  treeStudentFile.close(); //FINALLY CLOSING THIS DUMB FILE

  //faculty file
  int numF = 0;
  int fi;
  string fn;
  string fl;
  string fd;
  int fAid;
  lineCount = 1;
  int count;
  int na;
  treeFacultyFile.open(importedFile2);
  //already have default dummies
  if(treeFacultyFile.is_open()){
    try{
      getline(treeFacultyFile, line);
      if(line != ""){
        numF = stoi(line); //this is when the number of faculty is on the first line
      }
    }
    catch(exception i){
      cout << "FORMAT FROM FILE IS INCORRECT" << endl;
    }
    while(getline(treeFacultyFile,line)){
        //USE SWITCH METHOD HERE**************************************************
      switch(lineCount){
        case 1:{
          if(line != ("__________")){
            cout << "FORMAT FROM FILE IS INCORRECT" << endl;
          }
          break;
        }
        case 2:{
          try{
            fi = stoi(line); //faculty ID
          }
          catch(exception i){
            cout << "FORMAT FROM FILE IS INCORRECT" << endl;
          }
          break;
        }
        case 3:{
          fn = line; //faculty name
          break;
        }
        case 4:{
          fl = line;
          break;
        }
        case 5:{
          fd = line;
          break;
        }
        case 6:{
          try{
            na = stoi(line);
          }
          catch(exception i){
            cout << "FORMAT FROM FILE IS INCORRECT" << endl;
          }
          //creating the new faculty person
          Faculty *f = new Faculty(fi,fn,fl,fd);
          count++;
          for(int j = 0; j< na; ++j){
            getline(treeFacultyFile,line);
            try{
              fAid = stoi(line);
            }
            catch(exception i){
              cout << "FORMAT FROM FILE IS INCORRECT" << endl;
            }
            f->addAdvisee(fAid);
            break;
          }
        }
          default:break;
        }
        ++lineCount;
        if(count == numF){
          break; //the same size so we good
        }
        if(lineCount > 6){
          lineCount = 1; ///readjusting
        }
      }
    }
    else{
      cout << "FILE INCORRECT. STARTING SIMULATION WITHOUT ANY FACULTY IN SYSTEM" << endl;
    }
    treeFacultyFile.close(); //closing the file
}

void Simulation::writeFile(string file1, string file2){
  //files
  ofstream treeStudentFile;
  ofstream treeFacultyFile;
  //student first
  treeStudentFile.open(file1);
  if(treeStudentFile.is_open()){ //opening the file
    treeStudentFile << treeStudent.getSize() << endl;
    TreeNode<Student> *stud = treeStudent.getRoot(); //creating the note
    outputTreeStudent(stud, file1); //outputting that node/student person to file
  }
  treeStudentFile.close(); //close student file
  //faculty
  treeFacultyFile.open(file2);
  if(treeFacultyFile.is_open()){ //opening the file
    treeFacultyFile << treeFaculty.getSize() << endl;
    TreeNode<Faculty> *fact = treeFaculty.getRoot(); //creating the note
    outputTreeFaculty(fact, file2); //outputting that node/faculty person to file
  }
  treeFacultyFile.close(); //closing file
  cout << "IMPORTED SUCCESSFULLY TO FILES." << endl;
}

void Simulation::addFileStudent(int i, string n, string l, double a, string m, int aid){
  //creating the student
  Student *stud = new Student(i, n, l, a, m, aid);
  //created student as the node
  TreeNode<Student> *sn = new TreeNode<Student>(stud,i);
  //inserting the student into the tree
  treeStudent.insert(sn);
}

void Simulation::addFileFaculty(int i, string n , string l, string d){
  Faculty *fact = new Faculty(i,n,l,d);
  TreeNode<Faculty> *fn = new TreeNode<Faculty>(fact, i);
  treeFaculty.insert(fn);
  //repeated the same steps as the method above for students
}
//I needed to make a method in order to see if each response in the start screen was valid
int Simulation::check(int x, int y, string z){
  string asnwer;
  int answerInt;
  while(true){
    cout << " " << z;
    //variables for dummies
    int answerInt = 0;
    string answer = "";
    cin >> answer;
    try{
      answerInt = stoi(answer);//checking to see if it is valid
      if((answerInt < y) && (answerInt > 1)){
        return answerInt;
      }
      else{
        cout << "INVALID. PLEASE TRY AGAIN." << endl;
      }
    }
    catch(exception i){
      cout << "INVALID. PLEASE ENTER AN INTEGER." << endl;
    }

  }
}

void Simulation::run(){
  //method for the main method mainly
  bool running = true; //checks to see if my program is running
  while(running){
    int r;
    r = check(0, 15, "CHOOSE ONE OF THE FOLLOWING"); //spitting output to user
    switch(r){ //using a switch statement for each of their responses
      case 1: {
        if(treeStudent.isEmpty()){ //if the tree is empty
          cout << "STUDENT NOT FOUND" << endl; //printing there is nothing
          break;
        }
        cout << endl;
        printTreeStudent(treeStudent.getRoot());
        break;
      }
      case 2: {
        if(treeFaculty.isEmpty()){ //doing the same as we did for the student above
          cout << "FACULTY MEMBER NOT FOUND" << endl;
          break;
        }
        cout << endl;
        printTreeFaculty(treeFaculty.getRoot());
        break;
      }
      case 3:{
        if(treeStudent.isEmpty()){
          cout << "NO STUDENTS IN TREE" << endl;
          break;
        }
        int t;

        while(true){
          t = check(0,10000, "ENTER STUDENT ID");
          if(treeStudent.search(t)){
            showStudentInfo(t);//shows the information of student typed in
            break;
          }
          else{
            cout << "STUDENT NOT IN SYSTEM. PLEASE ENTER VALID STUDENT ID" << endl;
          }
        }
        break;
      }
      case 4:{
        if(treeFaculty.isEmpty()){
          cout << "FACULTY TREE IS EMPTY" << endl;
          break;
        }
        int t;
        while(true){
          t = check(0,10000, "ENTER FACULTY ID");
          if(treeFaculty.search(t)){
            showFacultyInfo(t);
            break;
          }
        }
        break;
      }
      case 5:{
        if(treeStudent.isEmpty()){
          cout << "STUDENT TREE IS EMPTY" << endl;
          break;
        }
        int t;
        cout << "STUDENTS IN SYSTEM: " << endl;
        printTreeStudent(treeStudent.getRoot());
        while(true){
          t = check(0,1000,"ENTER STUDENT ID");
          if(treeStudent.search(t)){
            showFacultyInfo(treeStudent.search(t)->getAdvisor());
            break;
          }
          else{
            cout << "STUDENT NOT IN SYSTEM. ENTER VALID ID" << endl;
          }
        }
        break;
      }
      case 6:{
        if(treeFaculty.isEmpty()){
          cout << "NO FACULTY IN SYSTEM" << endl;
          break;
        }
        int t;
        while(true){
          t = check(0,1000,"INPUT FACULTY ID");
          if(treeFaculty.search(t)){
            Faculty *fact = treeFaculty.search(t);
            for(int i = 0; i < fact->maxSize(); ++i){
              if(fact->adviseeArr[i] != -1){
                showStudentInfo(fact->adviseeArr[i]);
              }
            }
            break;
          }
          else{
            cout << "FACULTY MEMBER IS NOT IN SYSTEM. ENTER VALID ID." >> endl;
          }
        }
        break;
      }
      case 7:{
        addStudent();
        cout << "STUDENT ADDED." << endl;
        break;
      }
      case 8:{
        int t;
        if(treeStudent.isEmpty()){
          cout<< "NO STUDENTS IN SYSTEM." << endl;
          break;
        }
        cout << "CURRENT STUDENTS IN SYSTEM: " << endl;
        printTreeStudent(treeStudent.getRoot());
        while(true){
          t = check(0,1000,"ENTER STUDENT ID");
          if(treeStudent.search(t)){
            if(treeStudent.search(t)->getAdvisor() != 0){
              treeFaculty.search(treeStudent.search(t)->getAdvisor();//->//remove the advisee
            }
            treeStudent.deleteNode(t);
            cout << "STUDENT DELETED" << endl;
            break;
          }
          else{
            cout << "STUDENT NOT FOUND. ENTER VALID STUDENT ID." << endl;
          }
        }
        break;
      }
      case 9: 
    }
  }
}
