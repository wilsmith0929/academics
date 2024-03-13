#include "interface.h"

//KP - removing the interface class for now just to get things situated and compiling rq

void begin() {

    
    string fileName = "text-documents/people.txt";

    PersonVec memberList;
    PersonVec providerList;
    PersonVec managerList;

    //TESTING PURPOSES since waiting for loadfromfile - KP
    //managers
    long id1 = 111111111;
    string first1 = "manager";
    string last1 = "1";
    string type1 = "MANAGER";
    string status1 = "Active";
    string street1 = "1234 street";
    string city1 = "portland";
    string state1 = "OR";
    int zip1 = 97777;
    managerList.add_person(id1, type1, first1, last1, street1, city1, state1, zip1);

    long id2 = 222222222;
    string first2 = "manager";
    string last2 = "2";
    string type2 = "MANAGER";
    string status2 = "Active";
    string street2 = "5678 street";
    string city2 = "portland";
    string state2 = "OR";
    int zip2 = 97777;
    managerList.add_person(id2, type2, first2, last2, street2, city2, state2, zip2);

    //providers
    long id3 = 123456789;
    string first3 = "provider";
    string last3 = "1";
    string type3 = "PROVIDER";
    string status3 = "Active";
    string street3 = "1234 street";
    string city3 = "portland";
    string state3 = "OR";
    int zip3 = 97777;
    providerList.add_person(id3, type3, first3, last3, street3, city3, state3, zip3);

    long id4 = 333333333;
    string first4 = "provider";
    string last4 = "2";
    string type4 = "PROVIDER";
    string status4 = "Active";
    string street4 = "5678 street";
    string city4 = "portland";
    string state4 = "OR";
    int zip4 = 97777;
    providerList.add_person(id4, type4, first4, last4, street4, city4, state4, zip4);


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
  
    cout << "\nFOR TESTING PURPOSES ONLY DONT DELETE" << endl;
    cout << "WHEN TYPING IN PROVIDER AND MANAGER PASSWORD, ITS GOTTA MATCH";
    cout << "ANY OF THE providers and managers in the list" << endl;
    cout << "\nTESTING - managerlist" << endl;
    managerList.display_people();

    cout << "\nTESTING - providerlist" << endl;
    providerList.display_people();

    cout << "\nTESTING - memberList" << endl;
    memberList.display_people();

    switch(option) {

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
                                            cout << "\t\tFirst Name    : " << first  << endl;
                                            cout << "\t\tLast Name     : " << last   << endl;
                                            cout << "\t\tStreet Address: " << street << endl;
                                            cout << "\t\tCity          : " << city   << endl;
                                            cout << "\t\tState         : " << state  << endl;
                                            cout << "\t\tZipcode       : " << tempZ  << endl;

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

                                        if(input == "EXIT") {
                                            cout << "\n\t\tReturned to Manager Menu" << endl;
                                            break;
                                        }

                                        cout << "\n\t\tNEW MEMBER DETAILS" << endl;
                                        cout << "\t\tFirst Name    : " << first  << endl;
                                        cout << "\t\tLast Name     : " << last   << endl;
                                        cout << "\t\tStreet Address: " << street << endl;
                                        cout << "\t\tCity          : " << city   << endl;
                                        cout << "\t\tState         : " << state  << endl;
                                        cout << "\t\tZipcode       : " << tempZ  << endl;
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
                                        zip = 0;
                                            
                                        
                                        break;
                                    case 2:
                                        cout << "\t\tmanager menu action 2" << endl;
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
                            cout << "\n\tInvalid Option! Please try again!" << endl;
                    }
                } while(userOption != 5);
            }

            break;

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

    cout << "\nTESTING TO SEE IF ADD WORKED - memberList" << endl;
    memberList.display_people();
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

void manageMembersMenu() {
    cout << "\n\t\t**** Manage Members Menu ****" << endl;
    cout << "\t\t1- Create New Member Record" << endl;
    cout << "\t\t2- Update/Inactivate Member Record" << endl;
    cout << "\t\t3- Return to Manager Menu" << endl;
}

void displayWelcomeMsg() {
    cout << "\nWelcome to the ChocAn interface!" << endl;
}

void displayExitMsg() {
    cout << "\nThank you for using the ChocAn interface!" << endl;
}

