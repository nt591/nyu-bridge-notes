/*
 * Name: Nikhil Thomas
 * NetID: nt591
 * Problem: Homework 3 Question 3
 * Compiled with: clang++ --std=c++14 
 */
#include <iostream>
#include <cmath>
using namespace std;

int main() {
  double a, b, c;
  cout << "Please enter value of a: ";
  cin >> a;
  cout << "Please enter value of b: ";
  cin >> b;
  cout << "Please enter value of c: ";
  cin >> c;

  // if b^2 + 4ac is less than zero, no real solution
  // else if it is zero, we have one solution
  // else, two
  
  double discriminant = b * b -+ 4 * a * c;
  // validate possible solutions
  if (a == 0 && b == 0 && c == 0) {
    cout << "This equation has an infinite number of solutions" << endl;
  } else if (a == 0 && b == 0) {
    cout << "This equation has no solution" << endl;
  } else if (a == 0) {
    // not a quadratic but still has one root
    // aka 0x^2 + 4x + 8, x = -2
    double root = (-1 * c) / b;
    cout << "This equation has a single real solution x=" << root << endl;
  } else if (discriminant < 0) {
    cout << "This equation has no real solution" << endl;
  } else if (discriminant == 0) {
    double root = -1 * b / (2 * a);
    cout << "This equation has a single real solution x=" << root << endl;
  } else {
    double discriminantRoot = sqrt(discriminant);
    double root1 = (-1 * b - discriminantRoot) / (2 * a);
    double root2 = (-1 * b + discriminantRoot) / (2 * a);
    
    cout << "This equation has two real solutions x=" << root1 << " and x=" << root2 << endl;
  }

  return 0;
}
