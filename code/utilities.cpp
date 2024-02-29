#include "utilities.h"

int readInt() {
  //temp integer to be inputted
  int temp = 0;
  cin >> temp;
  while(!cin || temp <= 0) {
    cin.clear();
    cin.ignore(MAX, '\n');
    cout << "Invalid input! Try again: ";
    cin  >> temp;
  }
  cin.ignore(MAX, '\n');
  return temp;
}

char readChar() {
  //temp char to be inputted
  char temp = '\0';
  cin >> temp;
  while(!cin) {
    cin.clear();
    cin.ignore(MAX, '\n');
    cout << "Invalid character! Try again: ";
    cin  >> temp;
  }
  cin.ignore(MAX, '\n');
  return temp;
}

double getDouble() {
  //temp double to be inputted
  double temp = 0;
  cin >> temp;
  while(!cin || temp <= 0) {
    cin.clear();
    cin.ignore(MAX, '\n');
    cout << "Invalid input! Try again: ";
    cin  >> temp;
  }
  cin.ignore(MAX, '\n');
  return temp;
}

