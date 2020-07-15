#include <iostream>
#include <cmath>
using namespace std;

int main() {
 cout << "Enter the radius of your circle: " << endl;

 double radius;
 cin >> radius;
 double area = radius * radius * M_PI;

 cout << "the area of your circle is " << area << endl;

 return 0;
}
