#include <iostream>
#include <cmath>
using namespace std;

double cos(double x, int n);
int factorial(int n);

int main() {
  cout << "Enter a positive integer: ";
  int n;
  cin >> n;
  cout << "Enter a precision as an integer: ";
  int precision;
  cin >> precision;

  double ans = cos(n, precision);
  cout << "Your cosine is " << ans << endl;
  return 0;
}

int factorial(int n) {
  if (n == 0) return 1;
  int acc = 1;
  for (int i = 1; i <= n; i++) {
    acc *= i;
  }
  return acc;
}

double cos(double x, int n) {
  double sum = 0;
  int sign = 1;
  for (int i = 0; i < n; i++) {
    int power = 2 * i;
    double ans = sign *  pow(x, power) / factorial(power);
    sign *= -1;
    sum += ans;
  }
  return sum;
}
