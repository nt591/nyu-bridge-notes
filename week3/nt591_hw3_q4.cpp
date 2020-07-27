/*
 * Name: Nikhil Thomas
 * NetID: nt591
 * Problem: Homework 3 Question 4 
 * Compiled with: clang++ --std=c++14 
 */

#include <iostream>
using namespace std;

const int FLOOR_ROUND = 1;
const int CEILING_ROUND = 2;
const int ROUND = 3;

int main() {
  double input;
  int rounding;
  cout << "Please enter a Real number:" << endl;
  cin >> input;
  cout << "Choose your rounding method:" <<endl;
  cout << "1. Floor round" << endl;
  cout << "2. Ceiling round" << endl;
  cout << "3. Round to the nearest whole number" << endl;
  cin >> rounding;

  // first off, if the input is an integer we don't round so lets capture that case
  if (input == (int) input) {
    cout << input << endl;
  } else {
    switch(rounding) {
      case FLOOR_ROUND: {
        // if negative, need to truncate and subtract one
        if (input < 0) {
          int rounded = (int) input - 1;
          cout << rounded << endl;
        } else {
          cout << (int) input << endl;
        }
        break;
      }
      case CEILING_ROUND: {
        // if input is negative, just truncate (ceiling of -3.4 is -3)
        // else truncate and add 1
        if (input < 0) {
          cout << (int) input << endl;
        } else {
          int rounded = (int) input;
          cout << rounded + 1 << endl;
        }
      }
      case ROUND: {
         // two booleans
         // is it negative?
         // is the decimal 0.5 or higher?
         // T, T = round down (-4.7 is closer to -5)
         // T, F = round up (-4.3 is closer to -4)
         // F, T = round up
         // F, F = round down
        int rounded = (int) input;
        double decimals = input - rounded;
        if (input < 0) {
          if (decimals <= -0.5) {
            cout << rounded - 1 << endl;
          } else {
            cout << rounded << endl;
          }
        } else {
          if (decimals >= 0.5) {
            cout << rounded + 1 << endl;
          } else {
            cout << rounded << endl;
          }
        }
        break;
      }
      default: 
        cout << "Invalid input" << endl;
        break;
    }
  }
  
  return 0;
}
