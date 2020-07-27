#include <iostream>
using namespace std;

int main() {
  float  price1, price2;
  bool isMember;
  char memberInput;
  float taxRate;
  
  cout << "Enter price of first item: ";
  cin >> price1;
  cout << "Enter price of second item: ";
  cin >> price2;
  cout << "Does customer have a club card? (Y/N)";
  cin >> memberInput;

  if (memberInput == 'Y' || memberInput == 'y') {
    isMember = true;
  } else {
    isMember = false; // assume no invalid input by user
  }

  cout << "Enter tax rate, e.g. 5.5 for 5.5\% tax: ";
  cin >> taxRate;

  float lowerPrice, higherPrice;
  if (price1 < price2) {
    lowerPrice = price1;
    higherPrice = price2;
  } else {
    lowerPrice = price2;
    higherPrice = price1;
  }

  float basePrice = higherPrice + (lowerPrice * 0.5);
  float priceAfterDiscount = basePrice;
  if (isMember) {
    priceAfterDiscount *= 0.9;
  }

  float totalPrice = priceAfterDiscount * (1 + taxRate / 100);

  cout << "Base price: " << basePrice << endl;
  cout << "Price after discounts: " << priceAfterDiscount << endl;
  cout << "Total price: " << totalPrice << endl;
  return 0;
}
