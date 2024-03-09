#include "interface.h"
#include "manager.h"
#include "provider.h"
#include "member.h"
#include "utilities.h"

void begin() {

    //update names accordingly + the files are in text-doucments folder
    //need to figure out how we load in in when from different folder
    string providerFile = "provider_details.txt";
    string memberFile = "member_details.txt";

    vector<Provider> providerList;
    vector<Member> memberList;

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
void exeCmd(int option, vector<Member> & memberList, vector<Provider> & providerList) {
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
void displayMainMenu() {
    cout << "\n**** Main Menu ****" << endl;
    cout << "\t1- Manager Login" << endl;
    cout << "\t2- Provider Login" << endl;
    cout << "\t3- Quit" << endl;
}

//KP - lmk if we need to remove the tabs, just doing it cuz it'll be easier to naviagte 
//later on
void providerMenu() {
    cout << "\n\t**** Provider Menu ****" << endl;
    cout << "\t\t1- Validate Members" << endl;
    cout << "\t\t2- Enter Service Details" << endl;
    cout << "\t\t3- View Service History" << endl;
    cout << "\t\t4- View Service Directory" << endl;
    cout << "\t\t5- Return to Main Menu" << endl;
}

//KP - lmk if we need to remove the tabs, just doing it cuz it'll be easier to naviagte 
//later on
void managerMenu() {
  cout << "\n\t**** Manager Menu ****" << endl;
    cout << "\t\t1- Manage Members" << endl;
    cout << "\t\t2- Manage Providers" << endl;
    cout << "\t\t3- Generate Provider Report" << endl;
    cout << "\t\t4- Generate Member Report" << endl;
    cout << "\t\t5- Return to Main Menu" << endl;
}



void displayWelcomeMsg() {
    cout << "\nWelcome to the ChocAn interface!" << endl;
}

void displayExitMsg() {
    cout << "\nThank you for using the ChocAn interface!" << endl;
}
