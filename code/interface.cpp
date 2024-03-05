#include "interface.h"
#include "manager.h"
#include "provider.h"
#include "member.h"
#include "utilities.h"

void begin() {

    //update names accordingly + the files are in text-doucments folder
    //need to figure out how we load in in when from different folder
    string providerFile = "provider_details.txt";
    string memberFile = "member_deetails.txt";

    vector<Provider> providerList;
    vector<Member> memberList;

    //temp load from file's
    //providerList.loadFromFile(providerFile);
    //memberList.loadFromFile(memberList);

    int userOption = 0;

    displayWelcomeMsg();

    do {
        displayMainMenu();
        cout << "=> Option: ";
        userOption = read_int();    //some data validation
        exeCmd(userOption, memberList, providerList);
    } while(userOption != 3);

    displayExitMsg();
}

//KP - execute the options of user, we'll update the vectors to vector<User> respectively 
void exeCmd(int option, vector<Member> & memberList, vector<Provider> & providerList) {
    int userOption = 0;

    //KP - using nested switches
    //feel free to change
    //THESE ARE JUST TO GET US STARTED

    switch(option) {
        
        //manager login, then if valid we prompt them with manager menu
        case 1:
            int password = 0;
            //check if valid manager
            cout << "Manager Login!" << endl;
            cout << "Enter manager password: ";
            cin  >> password;

            // we can maybe have a utility functin that checks for password
            //just a temporary for now, PASSWORD is global in utilities.h
            //if valid, proceed with manager menu
            if(password == PASSWORD) {
                do {
                    managerMenu();
                    cout << "\n\t=> Option: ";
                    userOption = read_int();

                    switch(userOption) {
                        case 1:
                            cout << "manager menu action 1" << endl;
                            break;
                        case 2:
                            cout << "manager menu action 2" << endl;
                            break;
                        case 3:
                            cout << "manager menu action 3" << endl;
                            break;
                        case 4:
                            cout << "manager menu action 4" << endl;
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
                //we can prompt them to try again or just break back to main menu
                break;
            }

        //check if valid provider, then prompt providerMenu
        case 2:
            int password = 0;
            //check if valid provider
            cout << "Provider Login!" << endl;
            cout << "Enter provider password: ";
            cin  >> password;

            // we can maybe have a utility functin that checks for password
            //just a temporary for now, PASSWORD is global in utilities.h
            //if valid, proceed with manager menu
            if(password == PASSWORD) {
                do {
                    providerMenu();
                    cout << "\n\t=> Option: ";
                    userOption = read_int();

                    switch(userOption) {
                        case 1:
                            cout << "provider menu action 1" << endl;
                            break;
                        case 2:
                            cout << "provider menu action 2" << endl;
                            break;
                        case 3:
                            cout << "provider menu action 3" << endl;
                            break;
                        case 4:
                            cout << "provider menu action 4" << endl;
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
                //we can prompt them to try again or just break back to main menu
                break;
            }

        
        case 3:
            cout << "Exiting Main Menu!" << endl;
            break;
        default:
            cout << "Invalid Option! Please try again! : " << endl;

    }
}

void displayMainMenu() {
    cout << "\n** Main Menu **" << endl;
    cout << "\t1- Manager Login" << endl;
    cout << "\t2- Provider Login" << endl;
    cout << "\t3- Quit" << endl;
}

void providerMenu() {
    cout << "\n\t** Provider Menu **" << endl;
    cout << "\t\t1- Validate Members" << endl;
    cout << "\t\t2- Enter Service Details" << endl;
    cout << "\t\t3- View Service History" << endl;
    cout << "\t\t4- View Service Directory" << endl;
    cout << "\t\t5- Return to Main Menu" << endl;
}

//KP - lmk if we need to remove the tabs, just doing it cuz it'll be easier to naviagte 
//later on
void managerMenu() {
    cout << "\t\t1- Manage Members" << endl;
    cout << "\t\t2- Manage Providers" << endl;
    cout << "\t\t3- Generate Provider Report" << endl;
    cout << "\t\t4- Generate Member Report" << endl;
    cout << "\t\t5- Return to Main Menu" << endl;
}



void displayWelcomeMsg() {
    cout << "Welcome to the ChocAn interface!" << endl;
}

void displayExitMsg() {
    cout << "Thank you for using the ChocAn interface!" << endl;
}

/* KP - commented this out
bool display_menu() {
    display_welcome();
    bool exit_program_flag = false;
    Manager the_manager;
    Provider the_provider;
    vector<Provider> provider_list;
    vector<Member> member_list;
    while (!exit_program_flag) {
        cout << "Please select an option:" << endl;
        cout << "1. Manager" << endl;
        cout << "2. Provider" << endl;
        cout << "3. Exit" << endl;
        int choice = 0;
        choice = read_int();
        switch (choice) {
            case 1:
                // the_manager.manager_interface(provider_list, member_list);
                break;
            case 2:
                // the_provider.provider_interface(provider_list, member_list);
                break;
            case 3:
                exit_program_flag = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }
    return true;
}
*/

