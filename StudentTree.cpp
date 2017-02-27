/*

  Tanner Gower
  12/05/2016
  Project 10: Binary Search Trees

*/

#include <iostream>
#include <cstdlib>
#include "StudentTree.h"

using namespace std;

StudentTree::StudentTree()
{
  root = NULL;
}

StudentTree::~StudentTree()
{
  //deleteSubtree(root);
}

void StudentTree::insert(Student newStudent)
{
  TreeNode *newNode = new TreeNode;

  newNode->student = newStudent;
  newNode->left = newNode->right = NULL;

  insertNode(root, newNode);
}

void StudentTree::remove(Student delStudent)
{
  deleteNode(root, delStudent.getId());
}

Student* StudentTree::search(int id)
{
  TreeNode *nodePtr = root;
  Student *result = NULL;

  while (nodePtr) {
    if (nodePtr->student.getId() == id) {
      result = &(nodePtr->student);
      return result;
    } else if (id < nodePtr->student.getId())
      nodePtr = nodePtr->left;
    else
      nodePtr = nodePtr->right;
  }
  return result;
}

void StudentTree::displayInOrder()
{
  displayInOrder(root);
}

void StudentTree::insertNode(TreeNode *&nodePtr, TreeNode *&newNode)
{
  if (nodePtr == NULL)
    nodePtr = newNode;
  else if (newNode->student.getId() < nodePtr->student.getId())
    insertNode(nodePtr->left, newNode);
  else
    insertNode(nodePtr->right, newNode);
}

void StudentTree::deleteNode(TreeNode *&nodePtr, int id)
{
  if (id < nodePtr->student.getId())
    deleteNode(nodePtr->left, id);
  else if (id > nodePtr->student.getId())
    deleteNode(nodePtr->right, id);
  else
    makeDeletion(nodePtr);
}

void StudentTree::makeDeletion(TreeNode *&nodePtr)
{
  TreeNode *auxPtr; // helper/temp pointer
  if (nodePtr == NULL) {
    cout << "Cannot delete an empty(null) node." << endl;
  } else if (nodePtr->left == NULL) {
    //attach parent to right
    auxPtr = nodePtr;
    nodePtr = nodePtr->right;
    delete auxPtr;
  } else if (nodePtr->right == NULL) {
    //attach parent to left
    auxPtr = nodePtr;
    nodePtr = nodePtr->left;
    delete auxPtr;
  } else {
    auxPtr = nodePtr->right;
    while (auxPtr->left)
      auxPtr = auxPtr->left;
    auxPtr->left = nodePtr->left;
    auxPtr = nodePtr;
    nodePtr = nodePtr->right;
    delete auxPtr;
  }
}

void StudentTree::displayInOrder(TreeNode *&nodePtr)
{
  if (nodePtr) {
    displayInOrder(nodePtr->left);
    cout << nodePtr->student.toString() << endl;
    displayInOrder(nodePtr->right);
  }
}
