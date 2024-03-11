#pragma once
#include "utilities.h"
#include "person_vec.h"
#include "person.h" //KP - for now just inlcuding these, will update later with 
                    //the "user.h" class


//William - added these in a class, put vectors in the private section, can update once the people
//class is created

//kp - im removing the interface class for now to get everything situated first
//and running first
/*
class Interface
    public:
        Interface();
        void begin();               //KP - act as main, we will call this in main
        void displayMainMenu();     //KP - main menu
        //KP - execute the options of user, we'll update the vectors to vector<User> respectively 
        void exeCmd(int option, vector<Person> & memberList, vector<Person> & providerList);
        void providerMenu();        //KP - provider menu mimic test plan
        void managerMenu();         //KP - same as above^
        void displayWelcomeMsg();   //KP - welcome msg
        void displayExitMsg();      //KP - exit msg
    protected:
        vector<Person> & memberList;
        vector<Person> & providerList;
*/

void begin();               //KP - act as main, we will call this in main
void displayMainMenu();     //KP - main menu
//KP - execute the options of user, we'll update the vectors to vector<User> respectively 
void exeCmd(int option, PersonVec & memberList, PersonVec & providerList);
void providerMenu();        //KP - provider menu mimic test plan
void managerMenu();         //KP - same as above
void displayWelcomeMsg();   //KP - welcome msg
void displayExitMsg();      //KP - exit msg
