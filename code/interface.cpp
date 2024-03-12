#include "interface.h"

//KP - removing the interface class for now just to get things situated and compiling rq

void begin() {

    //update names accordingly + the files are in text-doucments folder
    //need to figure out how we load in in when from different folder
    //string providerFile = "provider_details.txt";
    //string memberFile = "member_details.txt";

    //vector<Person> memberList;
    //vector<Person> providerList;

    PersonVec memberList;
    PersonVec providerList;
    PersonVec managerList;

//TESTING PURPOSES since waiting for loadfromfile - KP
    long id1 = 111111111;
    string first1 = "person1";
    string last1 = "1";
    string type1 = "MANAGER";
    string status1 = "Active";
    string street1 = "1234 street";
    string city1 = "portland";
    string state1 = "OR";
    int zip1 = 97777;
    managerList.add_person(id1, type1, first1, last1, street1, city1, state1, zip1);

    long id2 = 222222222;
    string first2 = "person2";
    string last2 = "2";
    string type2 = "MANAGER";
    string status2 = "Active";
    string street2 = "5678 street";
    string city2 = "portland";
    string state2 = "OR";
    int zip2 = 97777;
    managerList.add_person(id2, type2, first2, last2, street2, city2, state2, zip2);


    int userOption = 0;

    displayWelcomeMsg();

    do {
        displayMainMenu();
        cout << "\n=> Option: ";
        userOption = read_int();    //some data validation
        exeCmd(userOption, memberList, providerList, managerList);
    } while(userOption != 3);

    displayExitMsg();
}

//KP - execute the options of user, we'll update the vectors to vector<User> respectively 
void exeCmd(int option, PersonVec & memberList, PersonVec & providerList, PersonVec & managerList) {
    int userOption = 0;
    long password = 0;
    int check = 0;
  
    managerList.display_people();

    switch(option) {

        //manager login, then if valid we prompt them with manager menu
        case 1:
            //keep this for reset each time
            password = 0;
            //check if valid manager
            cout << "\n\tMANAGER LOGIN" << endl;
            cout << "\t=> Enter Manager Number : ";
            cin  >> password;
            check = managerList.verify_person(password);
            while(check != 0) {
                cout << "\tManager " << password << " is not found. Check the number and try again" << endl;
                cout << "\t=> Enter Manager Number : ";
                cin  >> password;
                check = managerList.verify_person(password);
            }
            
            if(check == 0) {
                do {
                    managerMenu();
                    cout << "\n\t=> Option: ";
                    userOption = read_int();

                    switch(userOption) {
                        case 1:
                            cout << "\tmanager menu action 1" << endl;
                            break;
                        case 2:
                            cout << "\tmanager menu action 2" << endl;
                            break;
                        case 3:
                            cout << "\tmanager menu action 3" << endl;
                            break;
                        case 4:
                            cout << "\tmanager menu action 4" << endl;
                            break;
                        case 5:
                            cout << "\n\tExiting Manager Menu, back to main menu" << endl;
                            break;
                        default:
                            cout << "\n\tInvalid Option! Please try again! : " << endl;
                    }
                } while(userOption != 5);
            }

            break;

        //check if valid provider, then prompt providerMenu
        case 2:
            password = 0;
            //check if valid provider
            cout << "\n\tProvider Login!" << endl;
            cout << "\tEnter provider password: (its 1111) - add func later: ";
            cin  >> password;

            // we can maybe have a utility functin that checks for password
            //just a temporary for now, PASSWORD is global in utilities.h
            //if valid, proceed with manager menu
            if(password == _PASSWORD) {
                do {
                    providerMenu();
                    cout << "\n\t=> Option: ";
                    userOption = read_int();

                    switch(userOption) {
                        case 1:
                            cout << "\tprovider menu action 1" << endl;
                            break;
                        case 2:
                            cout << "\tprovider menu action 2" << endl;
                            break;
                        case 3:
                            cout << "\tprovider menu action 3" << endl;
                            break;
                        case 4:
                            cout << "\tprovider menu action 4" << endl;
                            break;
                        case 5:
                            cout << "\n\tExiting Provider Menu, back to main menu" << endl;
                            break;
                        default:
                            cout << "\n\tInvalid Option! Please try again! : " << endl;
                    }
                } while(userOption != 5);
            }
            else {
                cout << "\n\tInvalid password! Back to main menu!" << endl;
                //we can prompt them to try again or just break back to main menu
                break;
            }

            break;


        case 3:
            cout << "\nExiting Main Menu!" << endl;
            break;
    
        default:
            cout << "Invalid Option! Please try again! : " << endl;

    }
}

//KP - lmk if we need to remove the tabs, just doing it cuz it'll be easier to naviagte 
//later on
void displayMainMenu() {
    cout << "\n**** Main Menu ****" << endl;
    cout << "1- Manager Login" << endl;
    cout << "2- Provider Login" << endl;
    cout << "3- Quit" << endl;
}

//KP - lmk if we need to remove the tabs, just doing it cuz it'll be easier to naviagte 
//later on
void providerMenu() {
    cout << "\n\t**** Provider Menu ****" << endl;
    cout << "\t1- Validate Members" << endl;
    cout << "\t2- Enter Service Details" << endl;
    cout << "\t3- View Service History" << endl;
    cout << "\t4- View Service Directory" << endl;
    cout << "\t5- Return to Main Menu" << endl;
}

//KP - lmk if we need to remove the tabs, just doing it cuz it'll be easier to naviagte 
//later on
void managerMenu() {
    cout << "\n\t**** Manager Menu ****" << endl;
    cout << "\t1- Manage Members" << endl;
    cout << "\t2- Manage Providers" << endl;
    cout << "\t3- Generate Provider Report" << endl;
    cout << "\t4- Generate Member Report" << endl;
    cout << "\t5- Return to Main Menu" << endl;
}



void displayWelcomeMsg() {
    cout << "\nWelcome to the ChocAn interface!" << endl;
}

void displayExitMsg() {
    cout << "\nThank you for using the ChocAn interface!" << endl;
}

//KP just removing the interface for now to reduce complexity
/*
void Interface::begin() {

    //update names accordingly + the files are in text-doucments folder
    //need to figure out how we load in in when from different folder
    //string providerFile = "provider_details.txt";
    //string memberFile = "member_details.txt";

    providerList;
    memberList;

    //temp load from file's
    //providerList.loadFromFile(providerFile);
    //memberList.loadFromFile(memberList);

    int userOption = 0;

    displayWelcomeMsg();

    do {
        displayMainMenu();
        cout << "\n=> Option: ";
        userOption = read_int();    //some data validation
        exeCmd(userOption, memberList, providerList);
    } while(userOption != 3);

    displayExitMsg();
}

//KP - execute the options of user, we'll update the vectors to vector<User> respectively 
void Interface::exeCmd(int option, vector<Person> & memberList, vector<Person> & providerList) {
    int userOption = 0;
    int password = 0;
  

    switch(option) {

        //manager login, then if valid we prompt them with manager menu
        case 1:
            password = 0;
            //check if valid manager
            cout << "\n\tManager Login!" << endl;
            cout << "\tEnter manager password: (its 1111, add func later)";
            cin  >> password;

            // we can maybe have a utility functin that checks for password
            //just a temporary for now, PASSWORD is global in utilities.h
            //if valid, proceed with manager menu
            if(password == _PASSWORD) {
                do {
                    managerMenu();
                    cout << "\n\t=> Option: ";
                    userOption = read_int();

                    switch(userOption) {
                        case 1:
                            cout << "\tmanager menu action 1" << endl;
                            break;
                        case 2:
                            cout << "\tmanager menu action 2" << endl;
                            break;
                        case 3:
                            cout << "\tmanager menu action 3" << endl;
                            break;
                        case 4:
                            cout << "\tmanager menu action 4" << endl;
                            break;
                        case 5:
                            cout << "\n\tExiting Manager Menu, back to main menu" << endl;
                            break;
                        default:
                            cout << "\n\tInvalid Option! Please try again! : " << endl;
                    }
                } while(userOption != 5);
            }
            else {
                cout << "\n\tInvalid password! Back to main menu!" << endl;
                //we can prompt them to try again or just break back to main menu
                break;
            }

            break;

        //check if valid provider, then prompt providerMenu
        case 2:
            password = 0;
            //check if valid provider
            cout << "\n\tProvider Login!" << endl;
            cout << "\tEnter provider password: (its 1111) - add func later: ";
            cin  >> password;

            // we can maybe have a utility functin that checks for password
            //just a temporary for now, PASSWORD is global in utilities.h
            //if valid, proceed with manager menu
            if(password == _PASSWORD) {
                do {
                    providerMenu();
                    cout << "\n\t=> Option: ";
                    userOption = read_int();

                    switch(userOption) {
                        case 1:
                            cout << "\tprovider menu action 1" << endl;
                            break;
                        case 2:
                            cout << "\tprovider menu action 2" << endl;
                            break;
                        case 3:
                            cout << "\tprovider menu action 3" << endl;
                            break;
                        case 4:
                            cout << "\tprovider menu action 4" << endl;
                            break;
                        case 5:
                            cout << "\n\tExiting Provider Menu, back to main menu" << endl;
                            break;
                        default:
                            cout << "\n\tInvalid Option! Please try again! : " << endl;
                    }
                } while(userOption != 5);
            }
            else {
                cout << "\n\tInvalid password! Back to main menu!" << endl;
                //we can prompt them to try again or just break back to main menu
                break;
            }

            break;


        case 3:
            cout << "\nExiting Main Menu!" << endl;
            break;
    
        default:
            cout << "Invalid Option! Please try again! : " << endl;

    }
}

//KP - lmk if we need to remove the tabs, just doing it cuz it'll be easier to naviagte 
//later on
void Interface::displayMainMenu() {
    cout << "\n**** Main Menu ****" << endl;
    cout << "\t1- Manager Login" << endl;
    cout << "\t2- Provider Login" << endl;
    cout << "\t3- Quit" << endl;
}

//KP - lmk if we need to remove the tabs, just doing it cuz it'll be easier to naviagte 
//later on
void Interface::providerMenu() {
    cout << "\n\t**** Provider Menu ****" << endl;
    cout << "\t\t1- Validate Members" << endl;
    cout << "\t\t2- Enter Service Details" << endl;
    cout << "\t\t3- View Service History" << endl;
    cout << "\t\t4- View Service Directory" << endl;
    cout << "\t\t5- Return to Main Menu" << endl;
}

//KP - lmk if we need to remove the tabs, just doing it cuz it'll be easier to naviagte 
//later on
void Interface::managerMenu() {
    cout << "\n\t**** Manager Menu ****" << endl;
    cout << "\t\t1- Manage Members" << endl;
    cout << "\t\t2- Manage Providers" << endl;
    cout << "\t\t3- Generate Provider Report" << endl;
    cout << "\t\t4- Generate Member Report" << endl;
    cout << "\t\t5- Return to Main Menu" << endl;
}



void Interface::displayWelcomeMsg() {
    cout << "\nWelcome to the ChocAn interface!" << endl;
}

void Interface::displayExitMsg() {
    cout << "\nThank you for using the ChocAn interface!" << endl;
}
*/
