#include <iostream>
using namespace std;

int main() {
  int starCount;
  cout << "Enter a non-negative integer to represent the width of the diamond: ";
  cin >> starCount;
  cout << endl; // formating

  // insert spaces between the stars - if count is even, count + spaces = odd
  // if count is odd, count + spaces = odd
  
  // build the top triangle
  // let i = number of stars on the row
  // from 1 to starCount - 1
  // leftpad where padding = max - i
  // render stars
  for (int i = 1; i < starCount; i++) {
    // insert diff
    int padding = starCount - i;
    for (int j = 0; j < padding; j++) cout << " ";
    
    for (int j = 1; j <= i; j++) {
      cout << "*";
      if (j == i) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }

  // mid row
  for (int i = 1; i <= starCount; i++) {
    cout << "*";
    if (i == starCount) {
      cout << endl;
    } else {
      cout << " ";
    }
  }

  // inversion of top triangle
  for (int i = starCount - 1; i > 0; i--) {
    // insert diff
    int padding = starCount - i;
    for (int j = padding; j > 0; j--) cout << " ";
    
    for (int j = 1; j <= i; j++) {
      cout << "*";
      if (j == i) {
        cout << endl;
      } else {
        cout << " ";
      }
    }
  }
  return 0;
}
