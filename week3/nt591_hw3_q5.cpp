/*
 * Name: Nikhil Thomas
 * NetID: nt591
 * Problem: Homework 3 Question 5
 * Compiled with: clang++ --std=c++14 
 */
#include <iostream>
using namespace std;

const float LBS_TO_KGS = 0.453592f;
const float INCHES_TO_METERS = 0.0254f;

int main() {
  float height, weight, convertedHeight, convertedWeight;

  cout << "Please enter weight (in pounds)";
  cin >> weight;
  cout << "Please enter height (in inches)";
  cin >> height;

  convertedHeight = INCHES_TO_METERS * height;
  convertedWeight = LBS_TO_KGS * weight;
  float bmi = convertedWeight / (convertedHeight * convertedHeight);

  if (bmi < 18.5f) {
    cout << "The weight status is: Underweight" << endl;
  } else if (bmi < 25.0f) {
    cout << "The weight status is: Normal" << endl;
  } else if (bmi < 30.0f) {
    cout << "The weight status is: Overweight" <<endl;
  } else {
    cout << "The weight status is: Obese" << endl;
  }
  return 0;
}
