#include <iostream>
#include "ListNode.h" //inputting my list nodes
using namespace std;

#ifndef DoublyLinkedList_H_
#define DoublyLinkedList_H_

//going touse another template class to create my doubly linked list

template <class T>
class DoublyLinkedList{
  public:
  DoublyLinkedList(); //constructor
  ~DoublyLinkedList(); //deconstructor

  void insertFront(T data); //insert at the top of the dll
  void insertBack(T data); //insert at the back of the dll
  T removeFront(); //removing first spot of dll
  T removeBack(); //removing last spot of dll
  T remove(T key); //removing a node at a certain spot in the dll
  T deletePos(int pos); //deleting at a certain key value

  int getSize(); //returns the size of the dll
  bool isEmpty(); //returns true or false if the dll is empty
  void print(); //prints the whole dll
  T find(T data); //searches for a particular element in dll
  T getFront(); //returns first value in dll
  bool contains (T d); //wondering if a certain value is in queue

  ListNode<T>* getFrontNode(); //returns the front dll
private:
  ListNode<T> *front; //pointer to the front node
  ListNode<T> *back; //pointer to the back node
  int size; //variable to hold the total size of the dll
};

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  front = NULL;
  back = NULL;
  size = 0;
}

template<class T>
DoublyLinkedList<T>::~DoublyLinkedList(){
  if (front != NULL){
    //if the first element isn't empty make it empty
    delete front;
  }
}

template<class T>
void DoublyLinkedList<T>::insertFront(T data){
  ListNode<T> *node = new ListNode<T>(data);
  //starting case for dll
  if(isEmpty() == true){
    back = node;
  }
  else{
    //readjusts the front of the dll if it isn't already empty
    front->prev = node;
    node->next = front;
  }

  front = node; //new front
  ++size; //adds another node to the size since we added to the front
}

template<class T>
void DoublyLinkedList<T>::insertBack(T data){
  ListNode<T> *node = new ListNode<T>(data);
  //beginning case for when dll is empty already
  if(isEmpty() == true){
    front = node;
  }
  //all other cases when the dll isn't empty
  else{
    back->next = node;
    node->prev = back;
  }
  back = node; //new back node
  ++size; //we added another node to the dll
}

template<class T>
T DoublyLinkedList<T>::removeFront(){
  ListNode<T> *node = front;
  //nothing after front, then the back = front, or is null
  if(front->next == NULL){
    back = NULL;
  }
  else{
    front->next->prev = NULL;
  }
  T deletedNode = front->data;
  front = front->next;
  node->next = NULL;

  delete node; //remove the node officially
  --size; //make size smaller bc deleted
  return deletedNode; //shows what we deleted
}

template<class T>
T DoublyLinkedList<T>::removeBack(){
  T deletedNode = back->data; //getting back element data
  ListNode<T> *bk = back; //placeholder
  back = back->prev; //readjusting the new back
  bk->prev = NULL; // detaching the old back node
  delete bk; //removing it officially
  --size; //making size smaller due to deletion
  return bk; //returns deleted back element
}

template<class T>
T DoublyLinkedList<T>::remove(T key){
  ListNode<T> *curr = front; //making the front the current node to start searching for key
  while(curr->data != key){
    curr = curr->next; //readjusts the filtering node
  }
    if(curr == NULL){
      return "there is nothing to filter through";
    }
    //hasn't found the proper key yet
    if(curr == front){
      front = curr->next;
    }
    if(curr != front){
      curr->prev->next = curr->next;
    }
    if(curr == back){
      back = curr->prev;
    }
    if(curr != back){
      curr->next->prev = curr->prev;
    }
    //have finally found the desired key with associated node
    curr->next = NULL; //isolating the key node
    curr->prev = NULL; //isolating the key node
     --size; //making the total size smaller
     T temp = curr->data;
     delete curr; //finally deleting the current node
     return temp; //returns the data we just deleted
  }

  template<class T>
  T DoublyLinkedList<T>::deletePos(int pos){
    int index = 0;
    ListNode<T> *curr = front;
    ListNode<T> *prev = front; //making both values the one a tthe front to then filter throughf
    //while the index doesn't match the address going to filter through dll
    while(index != pos){
      prev = curr;
      curr= curr->next;
      ++index;
    }
    //once we have found the desired node
    prev->next = curr->next;
     curr->next = NULL;
     T deletedNode = curr->data; //placeholder for deleted information
     delete curr; //delete key node
     --size; //makes size one smaller due to deletion
     return deletedNode; //returns information just deleted
  }

  template<class T>
  int DoublyLinkedList<T>::getSize(){
    return size;
  }

  template<class T>
  bool DoublyLinkedList<T>::isEmpty(){
    if(size == 0){
      return true;
    }
    else{
      return false; //if size isn't zero, then it isn't empty
    }
  }

  template<class T>
  void DoublyLinkedList<T>::print(){
    ListNode<T> *curr = front;
    while(curr != NULL){
      if(curr->next != NULL){
        cout << curr->data << " ";
      }
      //case for when there is only one element
      if(curr->next == NULL){
        cout<< curr->data;
      }
      curr = curr->next; //filters through dll
    }
  }

  template<class T>
  T DoublyLinkedList<T>::find(T d){
    int index = -1; //starting at the first possible spot
    ListNode<T> *curr = front;
    while(curr != NULL){
      ++index; //increading the spot index
      if(curr->data == d){
        break; //key found
      }
      //key isn't found yet still increment
      else{
        curr = curr->next;
      }
    }
    //still ahs a alue of none
    if(curr == NULL){
      index = -1;
    }
    return index; //found the vlaue and am returning the index you can find it at
  }


template<class T>
T DoublyLinkedList<T>::getFront(){
  ListNode<T> *curr = front;
  //making current node the front
  return curr->data;
  //then pointing the the data within the front node to return it
}

template<class T>
bool DoublyLinkedList<T>::contains(T d){
  int index = -1;
  ListNode<T> *curr = front;
  while(curr != NULL){
    ++index; //incremendting the value of the index
    if(curr->data == d){
      return true; //found that it does contain value d
    }
    else{
      curr = curr->next; //continuting to filter through dll
    }
  }
  if(curr == NULL){
    return false; //does not contain the valuee d
  }
}

template<class T>
ListNode<T>* DoublyLinkedList<T>::getFrontNode(){
  return front; //returns the front node of the dll
}


#endif
















  /*
  public:
    //defining constructor
    DoublyLinkedList(){
      size = 0;
      back =  NULL;
      front = NULL;
    }
    //defining the deconstructor in the template
    ~DoublyLinkedList(){
      if (front != NULL){
        back = NULL;
        front = NULL;
      }
      delete front;
      delete back;
    }

  private:
    //no private variables
    //filling out methods in template


    //checking if the list is empty
    bool isEmpty(){
      if(size == 0){
        return true;
      }
      if(size != 0){
        return false;
      }
    }

    //deleteing the front node in the doubly linked ListNode
    T removeFront(){
      if(isEmpty() == false){
        ListNode<T> *front = front;
        T frontOne = front->data;
      }
    }

    //to delete a node at a speific spot
    void removeNode(int spot){
      int index = 0;
      ListNode *curr = front;
      ListNode *prev = front;
      //filtering through the nodes ot find wanted value
      while (index != spot){
        prev = curr;
        curr = curr->next;
        ++index;
      }
      //now to delete the desired node
      prev->next = cur->next; //grabbing node around nodetobeDeleted
      curr->next->prev = prev; //resetting nodes around nodetobeDeleted
      curr->next = NULL; //isolating the nodetobeDeleted in next lines
      curr->prev = NULL;
      curr->data = NULL;
      size--; //making the doubly linked list one node smaller bc deletion
      delete current; //finally deleting the desired node from list
    }

    //delteing a node at the very top of the doubly linked list

}*/
