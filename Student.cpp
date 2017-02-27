/*

  Tanner Gower
  12/05/2016
  Project 10: Binary Search Trees

*/

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include "Student.h"

using namespace std;

Student::Student()
{
  id = rand() % 9000 + 1000;
  name = "John Doe";
  int addNum = rand() % 9000 + 1000;
  stringstream ss;
  address = " Error Lane, San Marcos, TX 78666";
  ss << addNum << address;
  address = ss.str();

  // Generate random grades, nobody gets below a 60
  grades = new int[10];
  double total = 0.0;
  for (int i = 0; i < 10; i++) {
    grades[i] = (rand() % 40) + 60;
    total += grades[i];
  }

  gpa = (total / 10) / 25.0;
}

Student::~Student()
{
  //delete [] grades;
  // caused errors?
}

bool Student::operator!=(const Student &rhs)
{
  return id != rhs.id || name != rhs.name || address != rhs.address ||
          grades != rhs.grades || gpa != rhs.gpa;
}

void Student::setId(int newId) { id = newId; }
void Student::setName(string newName) { name = newName; }
void Student::setAddress(string newAddress) { address = newAddress; }
void Student::setGpa(double newGpa) { gpa = newGpa; }

int Student::getId() { return id; }
string Student::getName() { return name; }
string Student::getAddress() { return address; }
double Student::getGpa() { return gpa; }
string Student::toString() {
  stringstream ss;
  ss << id << "|" << name << "|" << address << "|";
  for (int i = 0; i < 10; i++) {
    ss << grades[i];
    if (i < 9) ss << ", ";
  }
  ss << "|" << gpa;
  return ss.str();
}
