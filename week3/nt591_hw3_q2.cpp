/*
 * Name: Nikhil Thomas
 * NetID: nt591
 * Problem: Homework 3 Question 2
 * Compiled with: clang++ --std=c++14 
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
  string name;
  int graduationYear, currentYear;
 
  cout << "Please enter your name: ";
  cin >> name;
  cout <<  "Please enter your graduation year: ";
  cin >> graduationYear;
  cout << "Please enter current year: ";
  cin >> currentYear;

  int yearsLeft = graduationYear - currentYear;

  if (yearsLeft <= 0) {
    cout << name << ", you have graduated " << endl;
  } else {
    switch (yearsLeft) {
      case 1: 
        cout << name << ", you are a Senior" << endl;
        break;
      case 2:
        cout << name << ", you are a Junior" << endl;
        break;
      case 3:
        cout << name << ", you are a Sophomore" << endl;
        break;
      case 4:
        cout << name << ", you are a Freshman" << endl;
        break;
      default:
        cout << name << ", you are not in college yet" << endl;
        break;
    }
  }

  
  
  return 0;
}
