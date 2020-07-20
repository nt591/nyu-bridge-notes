/*
 * Name: Nikhil Thomas
 * NetID: nt591
 * Question: Homework 2 Problem 3
 * Compiled with: clang++ --std=c++11 
 */

#include <iostream> 
using namespace std;

const int MINUTES_PER_HOUR = 60;
const int HOURS_PER_DAY = 24;
int main() {
  int johnMinutes, johnHours, johnDays;
  cout << "Please enter the number of days John has worked: ";
  cin >> johnDays;

  cout << "Please enter the number of hours John has worked: ";
  cin >> johnHours;

  cout << "Please enter the number of minutes John has worked: ";
  cin >> johnMinutes;
  cout << endl;

  int billMinutes, billHours, billDays;

  cout << "Please enter the number of days Bill has worked: ";
  cin >> billDays;

  cout << "Please enter the number of hours Bill has worked: ";
  cin >> billHours;

  cout << "Please enter the number of minutes Bill has worked: ";
  cin >> billMinutes;
  cout << endl;

  int minutesSum = billMinutes + johnMinutes;
  int roundupHours = minutesSum / MINUTES_PER_HOUR;
  minutesSum = minutesSum % MINUTES_PER_HOUR;

  int hoursSum = billHours + johnHours + roundupHours;
  int roundupDays = hoursSum / HOURS_PER_DAY;
  hoursSum = hoursSum % HOURS_PER_DAY;

  int daysSum = billDays + johnDays + roundupDays;

  cout << "The total time both of the worked together is: ";
  cout << daysSum << " days, ";
  cout << hoursSum << " hours and ";
  cout << minutesSum << " minutes." << endl;
  return 0;
}
