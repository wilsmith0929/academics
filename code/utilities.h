#pragma once
#include <iostream>
#include <vector>
#include <string>
#include <iterator>
#include <cctype>
#include <fstream>
#include <cstring>
#include <ctime>
#include <cstdlib>
using namespace std;

#define MEM_TYPE "MEMBER"
#define PRO_TYPE "PROVIDER"
#define MAN_TYPE "MANAGER"
#define PEOPLE_FILE "people.txt"

const int MAX = 101;
const int _PASSWORD = 1111;

//other side functions we might use

//just some functions that might be useful for inputting, it does data validation
double get_double();
int    read_int();
char   read_char();

//The prototype for the function that uploads all members, providers, and managers. 
//Returns the largest ID. I was thinking that whenever we create a new member we just increment the
//largest value.
long upload_people(PersonVec & members, PersonVec & providers, PersonVec & managers);
