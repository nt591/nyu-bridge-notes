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
const int NEGATIVE_FLOOR_ROUND = -1;
const int NEGATIVE_CEILING_ROUND = -2;
const int NEGATIVE_ROUND = -3;
const int INTEGER_ROUND = 0;
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

  int castedToInt = (int) input;
  bool isInteger = input == castedToInt;
  float decimals = input - castedToInt;
  
  /*
   * TA note: This exists due to Piazza comments about trying to avoid if/statements
   * since we're potentially allowed to use nested if statements
   * BUT cannot wrap the switch in an if/else (where if checks if an integer, else does the switching on rounding input)
   * then I chose to make some adjustments on the input to allow me one top-level switch
   */

  int roundedWithSign = rounding;
  if (isInteger) {
    roundedWithSign = 0;
  } else if (input < 0) {
    roundedWithSign *= -1;
  }
  
  // I could choose to make more changes to the rounding method based on decimals but that seems too far
  // eg
  // if ROUND and decimals >= 0.5, adjust to ceiling
  // if ROUND and decimals < -0.5, adjust to floor
  // if NEGATIVE_ROUND and < -0.5, negative floor
  // if NEGATIVE round and >= -0.5, negative ceiling 
 
  cout << "Your input was: " << input << " and after rounding it is "; 
  switch(roundedWithSign) {
    case INTEGER_ROUND: {
      cout << input << endl;
      break;
    } 
    case FLOOR_ROUND: {
      cout << castedToInt << endl;
      break;
    }
    case CEILING_ROUND: {
      cout << castedToInt + 1 << endl;
      break;
    }
    case NEGATIVE_FLOOR_ROUND: {
      cout << castedToInt - 1 << endl;
      break;
    }
    case NEGATIVE_CEILING_ROUND: {
      cout << castedToInt << endl;
      break;
   }
    case ROUND: {
      // if decimal >= 0.5, round up else down
      // I couldn't avoid this if/else (or at least wasn't clever enough)
      if (decimals >= 0.5) {
        cout << castedToInt + 1 << endl;
      } else {
        cout << castedToInt << endl;
      }
      break;
    }
    case NEGATIVE_ROUND: {
      // if decimal >=- 0.5, same as NEGATIVE CAIL, else NEGATIVE FLOOR
      if (decimals >= -0.5) {
        cout << castedToInt << endl;
      } else {
        cout << castedToInt - 1<< endl;
      }
      break;
    }
    default: 
      cout << "Invalid input" << endl;
      break;
  }
  
  return 0;
}
