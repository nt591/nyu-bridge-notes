#include <iostream>

const int DAYS_PER_WEEK = 7;

int main () {
  std::cout << "Please enter the number of days you traveled: " << std::endl;
  int days;
  std::cin >> days;

  int weeks = days / DAYS_PER_WEEK;
  int daysLeft = days % DAYS_PER_WEEK;

  std::cout << days << " days are " << weeks << " weeks and " << daysLeft << " days." << std::endl;

  return 0;
}
