#include "utilities.h"

int read_int() {
  //temp integer to be inputted
  int temp = 0;
  cin >> temp;
  while(!cin || temp <= 0) {
    cin.clear();
    cin.ignore(MAX, '\n');
    cout << "\nInvalid input! Try again: ";
    cin  >> temp;
  }
  cin.ignore(MAX, '\n');
  return temp;
}

long read_long() {
  //temp integer to be inputted
  long temp = 0;
  cin >> temp;
  while(!cin || temp <= 0) {
    cin.clear();
    cin.ignore(MAX, '\n');
    cout << "\nInvalid input! Try again: ";
    cin  >> temp;
  }
  cin.ignore(MAX, '\n');
  return temp;
}

char read_char() {
  //temp char to be inputted
  char temp = '\0';
  cin >> temp;
  while(!cin) {
    cin.clear();
    cin.ignore(MAX, '\n');
    cout << "\nInvalid character! Try again: ";
    cin  >> temp;
  }
  cin.ignore(MAX, '\n');
  return temp;
}

double get_double() {
  //temp double to be inputted
  double temp = 0;
  cin >> temp;
  while(!cin || temp <= 0) {
    cin.clear();
    cin.ignore(MAX, '\n');
    cout << "\nInvalid input! Try again: ";
    cin  >> temp;
  }
  cin.ignore(MAX, '\n');
  return temp;
}

string read_string() {
  //temp string to be inputted
  string input;
  getline(cin, input);
  //while(input.find_first_not_of(' ') == string::npos) {
  //  cout << "\nInvalid input! Try again: ";
  //  getline(cin, input);
  //}
  return input;
}

void printServices(const string & filename) {
  ifstream fin(filename);

  if (!fin) {
    cerr << "Failed to open file " << filename << endl;
    exit(0);
    return;
  }

  string line;
  while (getline(fin, line)) {
    cout << "\t" << line << endl; 
  }

  fin.close();
}

