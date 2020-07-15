#include <iostream>
using namespace std;

int main() {
  
  char lowerCase;

  cout << "Please enter a letter. " << endl;
  cin >> lowerCase;
  
  int asciiCode = lowerCase - 32;
  cout << asciiCode << endl;
  char upperCase = (char)asciiCode;

  cout << "The upper case of your letter is " << upperCase << "." << endl;
  return 0;
}
