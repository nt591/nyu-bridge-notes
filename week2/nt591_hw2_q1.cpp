/*
 * Name: Nikhil Thomas
 * NetID: nt591
 * Question: Homework 2 Problem 1
 * Compiled with: clang++ --std=c++11 
 */

#include <iostream> 
using namespace std;

const int CENTS_PER_QUARTER = 25;
const int CENTS_PER_DIME = 10;
const int CENTS_PER_NICKEL = 5;
const int CENTS_PER_PENNY = 1;
const int CENTS_PER_DOLLAR = 100;

int main() {
  int quarters, dimes, nickels, pennies, totalValue, dollars, cents;
  cout << "Please enter number of coins:" << endl;
  cout << "# of quarters: ";
  cin >> quarters;

  cout << "# of dimes: ";
  cin >> dimes;

  cout << "# of nickels: ";
  cin >> nickels;

  cout << "# of pennies: ";
  cin >> pennies;

  totalValue = quarters * CENTS_PER_QUARTER + dimes * CENTS_PER_DIME +
    nickels * CENTS_PER_NICKEL + pennies * CENTS_PER_PENNY;

  dollars = totalValue / CENTS_PER_DOLLAR;
  cents = totalValue % CENTS_PER_DOLLAR;

  cout << "The total is " << dollars << " dollars and " << cents << " cents" << endl;
  return 0;
}
