#include <iostream>
using namespace std;

//going to use the code within the =textbook to create the template class
//creating invidual nodes to put into my doubly-linked list class

#ifndef LISTNODE_H
#define LISTNODE_H

template <class T>
class ListNode{
  public:
    T data;
    ListNode<T> *prev;
    ListNode<T> *next;
    //constructor
    ListNode(){
      //nothing
    };
    //defining overloaded contructorr in template
    ListNode(T d){
      data = d;
      next = NULL;
      prev = NULL;
    }
    //defining destructor in tmeplate class
    ~ListNode(){
      if(next != NULL){
        next = NULL;
        prev = NULL;
      }
      delete next;
      delete prev;
    }
  //private:
    //nothing is going to be private as we want them to be
    //accessed everywhere
};
#endif 
