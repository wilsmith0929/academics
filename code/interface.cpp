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

void providerMenu() {
    cout << "1- Validate Members" << endl;
    cout << "2- Enter Service Details" << endl;
    cout << "3- View Service History" << endl;
    cout << "4- View Service Directory" << endl;
    cout << "5- Return to Main Menu" << endl;
}

void managerMenu() {
    cout << "1- Manage Members" << endl;
    cout << "2- Manage Providers" << endl;
    cout << "3- Generate Provider Report" << endl;
    cout << "4- Generate Member Report" << endl;
    cout << "5- Return to Main Menu" << endl;
}

void displayMainMenu() {
    cout << "1- Manager Login" << endl;
    cout << "2- Provider Login" << endl;
    cout << "3- Quit" << endl;
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

