/*

  Tanner Gower
  12/05/2016
  Project 10: Binary Search Trees

*/

#ifndef STUDENTTREE_H
#define STUDENTTREE_H

#include "Student.h"

class StudentTree
{

  private:
    struct TreeNode {
      Student student;
      TreeNode *left;
      TreeNode *right;
    };

    TreeNode *root;

    void insertNode(TreeNode *&, TreeNode *&);
    void deleteNode(TreeNode *&, int);
    void makeDeletion(TreeNode *&);
    void displayInOrder(TreeNode *&);

  public:
    StudentTree();
    ~StudentTree();

    void insert(Student);
    void remove(Student);
    Student* search(int);

    void displayInOrder();

};

#endif
