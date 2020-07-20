/*
 * Name: Nikhil Thomas
 * NetID: nt591
 * Question: Homework 2 Problem 2
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
  int dollars, cents;
  cout << "Please enter your amount in the format of dollars and cents separated by a space: " << endl;
  cin >> dollars >> cents;
  cout << dollars << " dollars and " << cents << " cents are:" << endl;

  int totalValue = dollars * CENTS_PER_DOLLAR + cents;

  int quarters = totalValue / CENTS_PER_QUARTER;
  totalValue = totalValue % CENTS_PER_QUARTER;

  int dimes = totalValue / CENTS_PER_DIME;
  totalValue = totalValue % CENTS_PER_DIME;

  int nickels = totalValue / CENTS_PER_NICKEL;
  totalValue = totalValue % CENTS_PER_NICKEL;

  int pennies = totalValue / CENTS_PER_PENNY;
  totalValue = totalValue % CENTS_PER_PENNY; // this doesn't need to exist

  cout << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels and " << pennies << " pennies" << endl;
  return 0;
}
