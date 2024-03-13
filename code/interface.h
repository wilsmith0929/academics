#pragma once
#include "person_vec.h"

void begin();               //KP - act as main, we will call this in main
void displayMainMenu();     //KP - main menu
void exeCmd(int option, PersonVec & memberList, PersonVec & providerList, PersonVec & managerList);
void providerMenu();        //KP - provider menu mimic test plan
void managerMenu();         //KP - same as above
void manageMembersMenu();   //KP - menu for managing members
void manageProvidersMenu(); //KP - menu for managing providers
void printDetails(string first, string last, string street, string city, string state, string tempZ);


void displayWelcomeMsg();   //KP - welcome msg
void displayExitMsg();      //KP - exit msg
