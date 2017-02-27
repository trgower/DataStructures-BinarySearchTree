/*

  Tanner Gower
  12/05/2016
  Project 10: Binary Search Trees

*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include "StudentTree.h"

using namespace std;

void resolveDuplicateId(Student*);
string* loadNames(string);

const int kNumStudents = 20;

int main ()
{
  srand(time(0));

  for (int i = 0; i < 3; i++) {
    cout << endl;
    cout << "--------Student Set " << (i + 1) << "--------" << endl;
    vector<Student> list;

    Student students[kNumStudents];
    resolveDuplicateId(students);
    string *firstNames = loadNames("firstnames");
    string *lastNames = loadNames("lastnames");
    for (int j = 0; j < kNumStudents; j++) {
      students[j].setName(firstNames[j] + " " + lastNames[j]);
      list.push_back(students[j]);
    }

    cout << "UNSORTED VECTOR" << endl;
    for (int p = 0; p < list.size(); p++)
      cout << list[p].toString() << endl;
    cout << endl;

    StudentTree tree;
    for (int p = 0; p < list.size(); p++)
      tree.insert(students[p]);

    cout << "BINARY SEARCH TREE USING IN-ORDER TRAVERSAL" << endl;
    tree.displayInOrder();

    // search for two records in the middle of the binary search tree and
    // display the search result
    cout << endl;
    cout << "Searching for id = " << students[0].getId() << endl;
    cout << "Result (nullptr = not found): " << endl
         << tree.search(students[0].getId())->toString() << endl << endl;

    cout << "Searching for id = " << students[1].getId() << endl;
    cout << "Result (nullptr = not found): " << endl
         << tree.search(students[1].getId())->toString() << endl << endl;

    // delete two nodes in the middle of the binary search tree.
    // display the binary search tree by using in-order traversal
    cout << "Removing student id = " << students[0].getId()
         << " and " << students[1].getId() << endl;
    tree.remove(students[0]);
    tree.remove(students[1]);

    cout << "BINARY SEARCH TREE AFTER DELETION" << endl;
    tree.displayInOrder();
  }

  return 0;
}

string* loadNames(string filename)
{
  ifstream firstNamesFile;
  vector<string> list;
  firstNamesFile.open(filename.c_str());

  string name = "";
  while(firstNamesFile >> name)
    list.push_back(name);

  vector<string> shuffled;
  int randNum = 0;
  while (list.size() > 0) {
    randNum = rand() % list.size();
    shuffled.push_back(list[randNum]);
    list.erase(list.begin() + randNum);
  }

  string *rlist = new string[shuffled.size()];
  for (int i = 0; i < shuffled.size(); i++)
    rlist[i] = shuffled[i];

  return rlist;
}

void resolveDuplicateId(Student* list)
{
  for (int i = 0; i < kNumStudents; i++) {
    for (int j = i+1; j < kNumStudents; j++) {
      while (list[i].getId() == list[j].getId()) {
        list[i].setId(rand() % 9000 + 1000);
      }
    }
  }
}
