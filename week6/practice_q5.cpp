#include <iostream>
using namespace std;
/*
 * Given a non-negative integer n
 * cout the sum of the digits
 *
 */
int main() {
  int n;
  cout << "Please enter a non-negative integer: ";
  cin >> n;
  cout << endl; //formatting

  int sum = 0;
  int tmp = n;
  while (tmp > 0) {
    int digit = tmp % 10;
    tmp /= 10;
    sum += digit;
  }

  cout << "The sum of the digits of " << n << " is " << sum << endl;
  return 0;
}
