#include "BST.h"
#include "GenStack.h"
#include "Start.h"
using namespace std;

class Simulation{
  public:
    //bst's
    BST<Student> treeStudent; //making a bst of students
    BST<Faculty> treeFaculty; //making a bst of faculty
    //nodes
    TreeNode<Student>* getTreeStudentRoot(); //gets the root node of students
    TreeNode<Faculty>* getTreeFacultyRoot(); //gets root node of faculty
    //constructors
    Simulation();
    ~Simulation();
    //student methods
    void printTreeStudent(TreeNode<Student> *st);//printing treenode of specific student s
    void outputTreeStudent(TreeNode<Student> *st, string s);
    void showStudentInfo(int i);
    void addStudent();
    //faculty methods
    void printTreeFaculty(TreeNode<Faculty> *f); //printing specific tree node of faculty
    void outputTreeFaculty(TreeNode<Faculty> *f, string s);
    void showFacultyInfo(int i);
    void addFaculty();
    //file methods
    void readFile(string file1, string file2); //reading in from the file
    void writeFile(string file1, string file2); //writing to the file
    void addFileStudent(int i, string n, string l, double a, string m, int aid);
    void addFileFaculty(int i, string n, string l, string d);
    //method function
    int check(int x, int y, string z);
    void run();

  //private:
  //no private vars/methods
};
