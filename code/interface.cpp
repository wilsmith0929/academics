#include "interface.h"
#include "manager.h"
#include "provider.h"
#include "member.h"

void display_welcome() {
    cout << "Welcome to the ChocAn interface!" << endl;
}

bool display_menu() {
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
        int choice;
        cin >> choice;
        switch (choice) {
            case 1:
                // the_manager.manager_interface();
                break;
            case 2:
                // the_provider.provider_interface();
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