/*
 * Name: Nikhil Thomas
 * NetID: nt591
 * Question: Homework 2 Problem 4
 * Compiled with: clang++ --std=c++11 
 */

#include <iostream> 
using namespace std;

int main() {
  int x, y;
  cout.setf(ios::fixed);
  cout.setf(ios::showpoint);
  cout.precision(1);

  cout << "Please enter two positive intergers, separated by a space: " << endl;
  cin >> x >> y;

  cout << x << " + " << y << " = " << x + y << endl;
  cout << x << " - " << y << " = " << x - y << endl;
  cout << x << " * " << y << " = " << x * y << endl;
  cout << x << " / " << y << " = " << (float) x / y << endl;
  cout << x << " div " << y << " = " << x / y << endl;
  cout << x << " mod " << y << " = " << x % y << endl;
  return 0;
}
