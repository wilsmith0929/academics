#include "interface.h"

//KP - removing the interface class for now just to get things situated and compiling rq

void begin() {

    PersonVec memberList;
    PersonVec providerList;
    PersonVec managerList;

    upload_people(memberList, providerList, managerList);
    int userOption = 0;

    displayWelcomeMsg();

    do {
        displayMainMenu();
        cout << "\n=> Option: ";
        userOption = read_int();    
        exeCmd(userOption, memberList, providerList, managerList);
    } while(userOption != 3);

    displayExitMsg();
}

//KP - execute the options of user, we'll update the vectors to vector<User> respectively 
void exeCmd(int option, PersonVec & memberList, PersonVec & providerList, PersonVec & managerList) {
    int userOption = 0;
    long password = 0;
    int check = 0;

    //all of these variables are required for the manager members menu - pls leave them here
    //if not, theres jump errors
    long id = 0;
    string first = "";
    string last = "";
    string type = "MEMBER"; 
    string status = "Active"; 
    string street = ""; 
    string city = "";
    string state = "";
    string tempZ = "";
    int zip = 0;
    int i = 0;

    string input;
    char save = '\0';

    //all of these variables are for inactivating member
    Person tempMember;

    switch(option) {



        //------------------------------------------------------------------------------------------------------
        case 1:
            //keep this for reset each time
            password = 0;
            //check if valid manager
            cout << "\n\tMANAGER LOGIN" << endl;
            cout << "\t=> Enter Manager ID Number : ";
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
                            do {
                                manageMembersMenu();
                                cout << "\n\t\t=> Option: ";
                                userOption = read_int();

                                switch(userOption) {
                                    case 1:

                                        for(i = 0; i < 6 && input != "EXIT"; i++) {
                                            cout << "\n\t\tNEW MEMBER DETAILS" << endl;
                                            printDetails(first, last, street, city, state, tempZ);

                                            if(i == 0) {
                                                cout << "\t\t=> Enter First Name : ";
                                                cin  >> input;
                                                first = input;
                                            }
                                            else if(i == 1) {
                                                cout << "\t\t=> Enter Last Name : ";
                                                cin  >> input;
                                                last = input;
                                            }
                                            else if(i == 2) {
                                                cout << "\t\t=> Enter Street Address : ";
                                                cin.ignore();
                                                getline(cin, input);
                                                street = input;
                                            }
                                            else if(i == 3) {
                                                cout << "\t\t=> Enter City : ";
                                                cin  >> input;
                                                city = input;
                                            }    
                                            else if(i == 4) {
                                                cout << "\t\t=> Enter State : ";
                                                cin  >> input;
                                                state = input;
                                            }
                                            else if(i == 5) {
                                                cout << "\t\t=> Enter Zipcode : ";
                                                cin  >> input;
                                                tempZ = input;
                                                zip = stoi(input);
                                            }
                                        }
                                        
                                        status = "Active";
                                        type = "MEMBER";

                                        if(input == "EXIT") {
                                            cout << "\n\t\tReturned to Manager Menu" << endl;
                                            break;
                                        }

                                        cout << "\n\t\tNEW MEMBER DETAILS" << endl;
                                        printDetails(first, last, street, city, state, tempZ);
                                        cout << "\t\t=> Save New Member Y/N : ";
                                        cin  >> save;

                                        if(tolower(save == 'y')) {
                                            srand(time(0));
                                            id = 100'000'000 + rand() % 900'000'000;
                                            cout << "\n\t\tMember Number " << id << " is assigned to ";
                                            cout << first << " " << last << "." << endl;
                                            memberList.upload_person(id, status, type, first, last, street, city, state, zip);
                                        }

                                        //needs to get resetted
                                        id = 0;
                                        first = "";
                                        last = "";
                                        type = ""; 
                                        status = ""; 
                                        street = ""; 
                                        city = "";
                                        state = "";
                                        tempZ = "";
                                        zip = 0;
                                        save = '\0';
                                            
                                        break;
                                    case 2:
                                        memberList.display_people();
                                        cout << "\n\t\tSEARCH MEMBER" << endl;
                                        cout << "\t\t=> Enter Member Number : ";
                                        cin  >> id;
                                        check = memberList.find_person(id);
                                        while(check != 0) {
                                            cout << "\t\tMEMBER not found. Check the number and try again" << endl;
                                            cout << "\t\t=> Enter Member Number : ";
                                            cin  >> id;
                                            check = memberList.find_person(id);
                                        }

                                        cout << "\t\tMember found" << endl;
                                        break;
                                    case 3:
                                        cout << "\n\t\tReturned to Manager Menu" << endl;
                                        break;
                                    default:
                                        cout << "\n\t\tInvalid Option! Please try again!" << endl;
                                }

                            } while(userOption != 3);

                            break;

                        case 2:
                            do {
                                manageProvidersMenu();
                                cout << "\n\t\t=> Option: ";
                                userOption = read_int();

                                switch(userOption) {
                                    case 1:

                                        for(i = 0; i < 6 && input != "EXIT"; i++) {
                                            cout << "\n\t\tNEW PROVIDER DETAILS" << endl;
                                            printDetails(first, last, street, city, state, tempZ);

                                            if(i == 0) {
                                                cout << "\t\t=> Enter First Name : ";
                                                cin  >> input;
                                                first = input;
                                            }
                                            else if(i == 1) {
                                                cout << "\t\t=> Enter Last Name : ";
                                                cin  >> input;
                                                last = input;
                                            }
                                            else if(i == 2) {
                                                cout << "\t\t=> Enter Street Address : ";
                                                cin.ignore();
                                                getline(cin, input);
                                                street = input;
                                            }
                                            else if(i == 3) {
                                                cout << "\t\t=> Enter City : ";
                                                cin  >> input;
                                                city = input;
                                            }    
                                            else if(i == 4) {
                                                cout << "\t\t=> Enter State : ";
                                                cin  >> input;
                                                state = input;
                                            }
                                            else if(i == 5) {
                                                cout << "\t\t=> Enter Zipcode : ";
                                                cin  >> input;
                                                tempZ = input;
                                                zip = stoi(input);
                                            }
                                        }

                                        status = "Active";
                                        type = "PROVIDER";

                                        if(input == "EXIT") {
                                            cout << "\n\t\tReturned to Manager Menu" << endl;
                                            break;
                                        }

                                        cout << "\n\t\tNEW PROVIDER DETAILS" << endl;
                                        printDetails(first, last, street, city, state, tempZ);
                                        cout << "\t\t=> Save New Provider Y/N : ";
                                        cin  >> save;

                                        if(tolower(save == 'y')) {
                                            srand(time(0));
                                            id = 100'000'000 + rand() % 900'000'000;
                                            cout << "\n\t\tProvider Number " << id << " is assigned to ";
                                            cout << first << " " << last << "." << endl;
                                            providerList.upload_person(id, status, type, first, last, street, city, state, zip);
                                        }

                                        //needs to get resetted
                                        id = 0;
                                        first = "";
                                        last = "";
                                        type = ""; 
                                        status = ""; 
                                        street = ""; 
                                        city = "";
                                        state = "";
                                        tempZ = "";
                                        zip = 0;
                                        save = '\0';
                                            
                                        break;
                                    case 2:
                                        memberList.display_people();
                                        cout << "\n\t\tSEARCH PROVIDER" << endl;
                                        cout << "\t\t=> Enter Provider Number : ";
                                        cin  >> id;
                                        check = providerList.find_person(id);
                                        while(check != 0) {
                                            cout << "\t\tPROVIDER not found. Check the number and try again" << endl;
                                            cout << "\t\t=> Enter Provider Number : ";
                                            cin  >> id;
                                            check = memberList.find_person(id);
                                        }

                                        cout << "\t\tProvider found" << endl;
                                        
                                        break;
                                    case 3:
                                        cout << "\n\t\tReturned to Manager Menu" << endl;
                                        break;
                                    default:
                                        cout << "\n\t\tInvalid Option! Please try again!" << endl;
                                }

                            } while(userOption != 3);

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
                            cout << "\n\tInvalid Option! Please try again!" << endl;
                    }
                } while(userOption != 5);
            }

            break;













        //----------------------------------------------------------------------------------------------------
        //ALL OPTION 2 - PROVIDER STUFF
        case 2:
            //keep this for reset each time
            password = 0;
            //check if valid provider
            cout << "\n\tPROVIDER LOGIN" << endl;
            cout << "\t=> Enter Provider ID Number : ";
            cin  >> password;
            check = providerList.verify_person(password);

            while(check != 0) {
                cout << "\tProvider " << password << " is not found. Check the number and try again" << endl;
                cout << "\t=> Enter Provider Number : ";
                cin  >> password;
                check = providerList.verify_person(password);
            }
            if(check == 0) {
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
            break;










        //-----------------------------------------------------------------------------------------------------
        case 3:
            cout << "\nExiting Main Menu!" << endl;
            break;
    
        default:
            cout << "Invalid Option! Please try again!" << endl;

    }
}

void displayMainMenu() {
    cout << "\n**** Main Menu ****" << endl;
    cout << "1- Manager Login" << endl;
    cout << "2- Provider Login" << endl;
    cout << "3- Quit" << endl;
}

void providerMenu() {
    cout << "\n\t**** Provider Menu ****" << endl;
    cout << "\t1- Validate Members" << endl;
    cout << "\t2- Enter Service Details" << endl;
    cout << "\t3- View Service History" << endl;
    cout << "\t4- View Service Directory" << endl;
    cout << "\t5- Return to Main Menu" << endl;
}

void managerMenu() {
    cout << "\n\t**** Manager Menu ****" << endl;
    cout << "\t1- Manage Members" << endl;
    cout << "\t2- Manage Providers" << endl;
    cout << "\t3- Generate Provider Report" << endl;
    cout << "\t4- Generate Member Report" << endl;
    cout << "\t5- Return to Main Menu" << endl;
}

void manageMembersMenu() {
    cout << "\n\t\t**** Manage Members Menu ****" << endl;
    cout << "\t\t1- Create New Member Record" << endl;
    cout << "\t\t2- Update/Inactivate Member Record" << endl;
    cout << "\t\t3- Return to Manager Menu" << endl;
}

void manageProvidersMenu() {
    cout << "\n\t\t**** Manage Providers Menu ****" << endl;
    cout << "\t\t1- Create New Provider Record" << endl;
    cout << "\t\t2- Update/Inactivate Provider Record" << endl;
    cout << "\t\t3- Return to Manager Menu" << endl;
}

void printDetails(string first, string last, string street, string city, string state, string tempZ) {
    cout << "\t\tFirst Name    : " << first  << endl;
    cout << "\t\tLast Name     : " << last   << endl;
    cout << "\t\tStreet Address: " << street << endl;
    cout << "\t\tCity          : " << city   << endl;
    cout << "\t\tState         : " << state  << endl;
    cout << "\t\tZipcode       : " << tempZ  << endl;
}

void displayWelcomeMsg() {
    cout << "\nWelcome to the ChocAn interface!" << endl;
}

void displayExitMsg() {
    cout << "\nThank you for using the ChocAn interface!" << endl;
}

