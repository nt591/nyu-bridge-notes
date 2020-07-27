/*
 * Name: Nikhil Thomas
 * NetID: nt591
 * Problem: Homework 3 Question 6
 * Compiled with: clang++ --std=c++14 
 */

#include <iostream>
#include <string>
using namespace std;

int main() {
  int hours, minutes, duration;
  char tmp;
  string day;

  cout << "Please enter the time the call started: ";
  cin >> hours >> tmp >> minutes;
  cout << "Please enter the day of the week the call started: ";
  cin >> day;
  cout << "Please enter the duration of the call in minutes: ";
  cin >> duration;

  // if it's a weekend, cheap call
  if (day == "Sa" || day == "Su") {
    cout << "The cost of the call is $" << 0.15f * duration << endl;
  } else if ((hours >= 8 && hours < 18 ) || (hours == 18 && minutes == 0)) {
      // two conditions for peak time
      // Calling on or after 8am and before 6:00pm
      // OR, since 6:00pm is inclusive, calling at 6:00pm
    cout << "The cost of the call is $" << 0.4f * duration << endl;
  } else {
    cout << "The cost of the call is $" << 0.25f * duration << endl;
  }

  return 0;
}
