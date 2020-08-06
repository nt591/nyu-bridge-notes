#include <iostream>

int main() {
  int base = 1;
  int x, prec;
  
  std::cout << "Enter a number and precision as integers: " ;
  std::cin >> x >> prec;
  int sign = 1;
  double accum = 0;
  double numerator = 1;
  double denominator = 1;
  
  for (int i = 0; i < prec; i++) {
    accum += sign * numerator / denominator;
    numerator *= (x * x);
    sign *= -1;
    denominator *= (2 *i + 2) *  (2 *i + 1);
  }

  std::cout << "Your number is: " << accum << std::endl;
  return 0;
}
