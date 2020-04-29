#include "BST.h"
#include <iostream>
using namespace std;
BST::BST(){
  root = NULL;
}

BST::~BST(){
  //DO THIS ON MY OWN
}

void BST::insert(int value){

  TreeNode *node = new TreeNode(value); //value is also the key

  if(root == NULL){
    //we have an empty TreeNode
    root = node;
  }
  else{
    //tree is not empty, we need to find the location
    TreeNode *curr = root;
    TreeNode *parent; //empty node

    while(true){
        //let's find the insertion point
        parent = curr;

        if(value < curr->key){
          //go left
          curr = curr->left;
          if(curr == NULL){
            parent->left = node;
            break;
          }
        else{
          //go right
          curr = curr->right;
          if(curr == NULL){
            //we found the node's home
            parent->right = node;
            break;
          }
        }
        }
    }
  }
}

bool BST::search(int value){
  //search
}

bool BST::deleteNode(int k){
  //delete here
}

bool BST::isEmpty(){
  //returns it is empty
}

TreeNode* BST::getMin(){
  TreeNode *curr = root;
  if(root == NULL){
    return NULL; //the tree is empty
  }
  while(curr->left != NULL){
    curr = curr->left;
  }
  return curr;
}

TreeNode* BST::getMax(){
  TreeNode *curr = root; //start at the root
  if(root == NULL){
    return NULL; //tree is empty
  }
  while(curr->right != NULL){
    curr = curr->right;
  }
  return curr; // if tree consisted of a numeric type curr->key or curr->value
}

TreeNode* getSuccessor(TreeNode *d){
  //returns previous node
}

void BST::printTree(TreeNode *node){
  if(node == NULL){
    return;
  }

  printTree(node->left);
  cout << node->key << endl;
  printTree(node-> right);
}
