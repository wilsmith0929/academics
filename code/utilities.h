#pragma once
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <iterator>
#include <cctype>
#include <fstream>
#include <cstring>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <cstdio>
#include <map>
using namespace std;

const int MAX = 101;

//just some functions that might be useful for inputting, it does data validation
double get_double();
int    read_int();
long   read_long();
char   read_char();
string read_string();
string removeWhitespace(const string & str);
string getCurrentDateMMDDYYYY();
int checkIfFileEmpty(ifstream & inputFile);
int hasFileBeenWrittenTo(string & filename);
void printServices(const string & filename);
int generateProviderReport(const string & filename);
int generateMemberReport(const string & filename);