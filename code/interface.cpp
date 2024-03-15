#include "interface.h"

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


void exeCmd(int option, PersonVec & memberList, PersonVec & providerList, PersonVec & managerList) {
    int userOption = 0;
    long password  = 0;
    int check      = 0;
    long id        = 0;
    int zip        = 0;
    int i          = 0;
    string first  = "";
    string last   = "";
    string type   = "";
    string status = "";
    string street = "";
    string city   = "";
    string state  = "";
    string tempZ  = "";

    char save = '\0';
    string input = "";
    Person tempMember;
    Person tempProvider;
    map<string, vector<vector<string>>> providerRecords;
    map<string, vector<vector<string>>> memberRecords;
    int reportResult = 0;

    switch(option) {

        //-------------------------------------------MAIN MENU OPTION 1 - MANAGER STUFF -------------------------------------------------------------------------------------------------------------
        case 1:

            password = 0;
            cout << "\n\tMANAGER LOGIN" << endl;
            cout << "\t=> Enter Manager ID Number : ";
            password = read_long();
            check = managerList.verify_person(password);

            while(check != 0) {
                cout << "\tManager " << password << " is not found. Check the number and try again" << endl;
                cout << "\t=> Enter Manager Number : ";
                password = read_long();
                check = managerList.verify_person(password);
            }


            if(check == 0) {
                do {
                    managerMenu();
                    cout << "\n\t=> Option: ";
                    userOption = read_int();

                    switch(userOption) {

                        //--------------------------------MANAGER MENU OPTION 1 MANAGE MEMBERS------------------------------------------------------------
                        case 1:
                            do {
                                manageMembersMenu();
                                cout << "\n\t\t=> Option: ";
                                userOption = read_int();

                                switch(userOption) {

                                    //-----------------------------MANAGE MEMBERS MENU OPTION 1 - NEW MEMBER--------------------------
                                    case 1:

                                        for(i = 0; i < 6 && input != "EXIT"; i++) {
                                            cout << "\n\t\tNEW MEMBER DETAILS" << endl;
                                            printDetails(first, last, street, city, state, tempZ);

                                            if(i == 0) {
                                                cout << "\t\t=> Enter First Name : ";
                                                input = read_string();
                                                first = input;
                                            }
                                            else if(i == 1) {
                                                cout << "\t\t=> Enter Last Name : ";
                                                input = read_string();
                                                last = input;
                                            }
                                            else if(i == 2) {
                                                cout << "\t\t=> Enter Street Address : ";
                                                input = read_string();
                                                street = input;
                                            }
                                            else if(i == 3) {
                                                cout << "\t\t=> Enter City : ";
                                                input = read_string();
                                                city = input;
                                            }
                                            else if(i == 4) {
                                                cout << "\t\t=> Enter State : ";
                                                input = read_string();
                                                state = input;
                                            }
                                            else if(i == 5) {
                                                cout << "\t\t=> Enter Zipcode : ";
                                                zip = read_int();
                                                tempZ = to_string(zip);
                                            }
                                        }

                                        status = "Active";
                                        type = "MEMBER";

                                        if(input == "EXIT") {
                                            resetVariables(first, last, type, status, street, city, state, tempZ, zip, id, i, save, input);
                                            cout << "\n\t\tReturned to Manager Menu" << endl;
                                            break;
                                        }

                                        cout << "\n\t\tNEW MEMBER DETAILS" << endl;
                                        printDetails(first, last, street, city, state, tempZ);
                                        cout << "\t\t=> Save New Member Y/N : ";
                                        save = read_char();

                                        if(tolower(save == 'y')) {
                                            srand(time(0));
                                            id = 100'000'000 + rand() % 900'000'000;
                                            cout << "\n\t\tMember Number " << id << " is assigned to ";
                                            cout << first << " " << last << "." << endl;
                                            memberList.upload_person(id, status, type, first, last, street, city, state, zip);
                                        }

                                        //needs to get resetted
                                        resetVariables(first, last, type, status, street, city, state, tempZ, zip, id, i, save, input);
                                        break;

                                    //---------------------------MANAGE MEMBERS MENU OPTION 2 - Update/Deactivate----------------------
                                    case 2:
                                        memberList.display_people();
                                        cout << "\n\t\tSEARCH MEMBER" << endl;
                                        cout << "\t\t=> Enter Member Number : ";
                                        id = read_long();
                                        check = memberList.retrieve_person(id, tempMember);
                                        while(check != 0) {
                                            cout << "\n\t\tMEMBER not found. Check the number and try again" << endl;
                                            cout << "\t\t=> Enter Member Number : ";
                                            cin  >> id;
                                            check = memberList.retrieve_person(id, tempMember);
                                        }

                                        for(i = 0; i < 7 && input != "EXIT"; i++) {
                                            cout << "\n\t\tMEMBER DETAILS" << endl;
                                            cout << "\n\t\tHit enter to leave as is or update with text" << endl << endl;
                                            tempMember.display_person_formatted();

                                            if(i == 0) {
                                                cout << "\t\t=> Change First Name : ";
                                                input = read_string();
                                                if (input.empty()) continue;
                                                first = input;
                                            }
                                            else if(i == 1) {
                                                cout << "\t\t=> Change Last Name : ";
                                                input = read_string();
                                                if (input.empty()) continue;
                                                last = input;
                                            }
                                            else if(i == 2) {
                                                cout << "\t\t=> Change Address : ";
                                                input = read_string();
                                                if (input.empty()) continue;
                                                street = input;
                                            }
                                            else if(i == 3) {
                                                cout << "\t\t=> Change City : ";
                                                input = read_string();
                                                if (input.empty()) continue;
                                                city = input;
                                            }
                                            else if(i == 4) {
                                                cout << "\t\t=> Change State : ";
                                                input = read_string();
                                                if (input.empty()) continue;
                                                state = input;
                                            }
                                            else if(i == 5) {
                                                cout << "\t\t=> Change Zipcode : ";
                                                input = read_string();
                                                if (input.empty()) continue;
                                                tempZ = input;
                                                zip = stoi(input);
                                            }
                                            else if(i == 6) {
                                                cout << "\t\t=> Change Status : ";
                                                input = read_string();
                                                if (input.empty()) continue;
                                                status = input;
                                            }
                                        }

                                        if(input == "EXIT") {
                                            resetVariables(first, last, type, status, street, city, state, tempZ, zip, id, i, save, input);
                                            cout << "\n\t\tReturned to Manager Menu" << endl;
                                            break;
                                        }

                                        cout << "\n\t\tMEMBER DETAILS" << endl;
                                        tempMember.display_person_formatted();
                                        cout << "\t\t=> Save New Member Y/N : ";
                                        cin  >> save;

                                        if(tolower(save == 'y')) {
                                            if(!first.empty()) {
                                                tempMember.change_first_name(first);
                                            }
                                            if(!last.empty()) {
                                                tempMember.change_last_name(last);
                                            }
                                            if(!street.empty()) {
                                                tempMember.change_street_add(street);
                                            }
                                            if(!city.empty()) {
                                                tempMember.change_city(city);
                                            }
                                            if(!state.empty()) {
                                                tempMember.change_state(state);
                                            }
                                            if(!tempZ.empty()) {
                                                tempMember.change_zip(zip);
                                            }
                                            if(!status.empty()) {
                                                tempMember.change_status(status);
                                            }
                                            memberList.update_person(id, tempMember);

                                            cout << "\n\t\tMember Details Updated as Follows" << endl;
                                            tempMember.display_person_formatted();
                                        }

                                        //needs to get resetted
                                        resetVariables(first, last, type, status, street, city, state, tempZ, zip, id, i, save, input);
                                        break;

                                    //------------------------------------MANAGE MEMBERS MENU OPTION 3--------------------------
                                    case 3:
                                        cout << "\n\t\tReturned to Manager Menu" << endl;
                                        break;
                                    default:
                                        cout << "\n\t\tInvalid Option! Please try again!" << endl;
                                }

                            } while(userOption != 3);
                            break;

                        //--------------------------------MANAGER MENU OPTION 2 - MANAGE PROVIDERS-------------------------------------------------------
                        case 2:
                            do {
                                manageProvidersMenu();
                                cout << "\n\t\t=> Option: ";
                                userOption = read_int();

                                switch(userOption) {

                                    //----------------------------------MANAGE PROVIDERS MENU 1 - CREATE NEW PROVIDER--------------------------------
                                    case 1:
                                        for(i = 0; i < 6 && input != "EXIT"; i++) {
                                            cout << "\n\t\tNEW PROVIDER DETAILS" << endl;
                                            printDetails(first, last, street, city, state, tempZ);

                                            if(i == 0) {
                                                cout << "\t\t=> Enter First Name : ";
                                                input = read_string();
                                                first = input;
                                            }
                                            else if(i == 1) {
                                                cout << "\t\t=> Enter Last Name : ";
                                                input = read_string();
                                                last = input;
                                            }
                                            else if(i == 2) {
                                                cout << "\t\t=> Enter Street Address : ";
                                                input = read_string();
                                                street = input;
                                            }
                                            else if(i == 3) {
                                                cout << "\t\t=> Enter City : ";
                                                input = read_string();
                                                city = input;
                                            }
                                            else if(i == 4) {
                                                cout << "\t\t=> Enter State : ";
                                                input = read_string();
                                                state = input;
                                            }
                                            else if(i == 5) {
                                                cout << "\t\t=> Enter Zipcode : ";
                                                zip = read_int();
                                                tempZ = to_string(zip);
                                            }
                                        }

                                        status = "Active";
                                        type = "PROVIDER";

                                        if(input == "EXIT") {
                                            resetVariables(first, last, type, status, street, city, state, tempZ, zip, id, i, save, input);
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
                                        resetVariables(first, last, type, status, street, city, state, tempZ, zip, id, i, save, input);
                                        break;

                                    //----------------------------------MANAGE PROVIDERS MENU 2 - UPDATE/DEACTIVATE PROVIDER-------------------
                                    case 2:
                                        providerList.display_people();
                                        cout << "\n\t\tSEARCH PROVIDER" << endl;
                                        cout << "\t\t=> Enter Provider Number : ";
                                        id = read_long();
                                        check = providerList.retrieve_person(id, tempProvider);
                                        while(check != 0) {
                                            cout << "\n\t\tPROVIDER not found. Check the number and try again" << endl;
                                            cout << "\t\t=> Enter Provider Number : ";
                                            id = read_long();
                                            check = providerList.retrieve_person(id, tempProvider);
                                        }

                                        for(i = 0; i < 7 && input != "EXIT"; i++) {
                                            cout << "\n\t\tPROVIDER DETAILS" << endl;
                                            cout << "\n\t\tHit enter to leave as is or update with text" << endl << endl;
                                            tempProvider.display_person_formatted();

                                            if(i == 0) {
                                                cout << "\t\t=> Change First Name : ";
                                                input = read_string();
                                                if (input.empty()) continue;
                                                first = input;
                                            }
                                            else if(i == 1) {
                                                cout << "\t\t=> Change Last Name : ";
                                                input = read_string();
                                                if (input.empty()) continue;
                                                last = input;
                                            }
                                            else if(i == 2) {
                                                cout << "\t\t=> Change Address : ";
                                                input = read_string();
                                                if (input.empty()) continue;
                                                street = input;
                                            }
                                            else if(i == 3) {
                                                cout << "\t\t=> Change City : ";
                                                input = read_string();
                                                if (input.empty()) continue;
                                                city = input;
                                            }
                                            else if(i == 4) {
                                                cout << "\t\t=> Change State : ";
                                                input = read_string();
                                                if (input.empty()) continue;
                                                state = input;
                                            }
                                            else if(i == 5) {
                                                cout << "\t\t=> Change Zipcode : ";
                                                input = read_string();
                                                if (input.empty()) continue;
                                                tempZ = input;
                                                zip = stoi(input);
                                            }
                                            else if(i == 6) {
                                                cout << "\t\t=> Change Status : ";
                                                input = read_string();
                                                if (input.empty()) continue;
                                                status = input;
                                            }
                                        }

                                        if(input == "EXIT") {
                                            resetVariables(first, last, type, status, street, city, state, tempZ, zip, id, i, save, input);
                                            cout << "\n\t\tReturned to Manager Menu" << endl;
                                            break;
                                        }

                                        cout << "\n\t\tPROVIDER DETAILS" << endl;
                                        tempProvider.display_person_formatted();
                                        cout << "\t\t=> Save New Member Y/N : ";
                                        cin  >> save;

                                        if(tolower(save == 'y')) {
                                            if(!first.empty()) {
                                                tempProvider.change_first_name(first);
                                            }
                                            if(!last.empty()) {
                                                tempProvider.change_last_name(last);
                                            }
                                            if(!street.empty()) {
                                                tempProvider.change_street_add(street);
                                            }
                                            if(!city.empty()) {
                                                tempProvider.change_city(city);
                                            }
                                            if(!state.empty()) {
                                                tempProvider.change_state(state);
                                            }
                                            if(!tempZ.empty()) {
                                                tempProvider.change_zip(zip);
                                            }
                                            if(!status.empty()) {
                                                tempProvider.change_status(status);
                                            }
                                            providerList.update_person(id, tempProvider);

                                            cout << "\n\t\tProvider Details Updated as Follows" << endl;
                                            tempProvider.display_person_formatted();
                                        }

                                        //needs to get resetted
                                        resetVariables(first, last, type, status, street, city, state, tempZ, zip, id, i, save, input);
                                        break;

                                    //----------------------------------MANAGE PROVIDERS MENU 3 - RETURN TO MANAGER MENU-------------------------
                                    case 3:
                                        cout << "\n\t\tReturned to Manager Menu" << endl;
                                        break;
                                    default:
                                        cout << "\n\t\tInvalid Option! Please try again!" << endl;
                                }

                            } while(userOption != 3);
                            break;

                        //---------------------------------------MANAGER MENU OPTION 3 - Generate Provider Report------------------------------------
                        case 3:
                            cout << "\n\tGenerate Provider Report" << endl << endl;
                            reportResult = generateProviderReport(providerRecords, "../text-documents/services_provided.txt");
                            if(reportResult == 2) {
                                cout << "\n\t-- Provider Reports Emailed Sucessfully --" << endl;
                                cout << "\n\tAll providers emailed:" << endl;
                                printProviderReport(providerRecords);
                            }
                            else {
                                cout << "\n\t-- Provider Reports Emailed Unsucessfully --" << endl;
                            }
                            break;

                        //---------------------------------------MANAGER MENU OPTION 4 - Generate Member Report--------------------------------------
                        case 4:
                            //generateMemberReport("../text-documents/services_provided.txt");
                            break;

                        //---------------------------------------MANAGER MENU OPTION 5 - Exit Manager Menu ------------------------------------------
                        case 5:
                            cout << "\n\tExiting Manager Menu, back to main menu" << endl;
                            break;

                        //------------------------------------------------DEFAULT--------------------------------------------------------------------
                        default:
                            cout << "\n\tInvalid Option! Please try again!" << endl;

                    }                                   //switch case for MANAGER MENU

                } while(userOption != 5);       //do while loop for continuous input

            }                       //if to check if check is valid
            break;

        //-------------------------------------------MAIN MENU OPTION 2 - PROVIDER STUFF ----------------------------------------------------------------------------
        case 2:

            password = 0;
            cout << "\n\tPROVIDER LOGIN" << endl;
            cout << "\t=> Enter Provider ID Number : ";
            password = read_long();
            check = providerList.verify_person(password);

            while(check != 0) {
                cout << "\tProvider " << password << " is not found. Check the number and try again" << endl;
                cout << "\t=> Enter Provider Number : ";
                password = read_long();
                check = providerList.verify_person(password);
            }

            if(check == 0) {
                do {
                    providerMenu();
                    cout << "\n\t=> Option: ";
                    userOption = read_int();

                    switch(userOption) {

                        //---------------------------------------PROVIDER MENU OPTION 1 - Validate Members------------------------------------------
                        case 1:
                            cout << "\tprovider menu action 1 - Validate Member" << endl;
                            break;

                        //---------------------------------------PROVIDER MENU OPTION 2 - Enter service deatils-------------------------------------
                        case 2:
                            cout << "\tprovider menu action 2 - Enter service details" << endl;
                            break;

                        //---------------------------------------PROVIDER MENU OPTION 3 - View Service History---------------------------------------
                        case 3:
                            cout << "\tprovider menu action 3 - View Service History" << endl;
                            break;

                        //---------------------------------------PROVIDER MENU OPTION 4 - View Service Directory-------------------------------------
                        case 4:
                            cout << "\n\tPROVIDER SERVICES OFFERED DIRECTORY" << endl;
                            cout << "\n\tService Code | Service Name           | Service Fee" << endl;
                            cout << "\t-----------------------------------------------------" << endl;
                            printServices("../text-documents/services.txt");
                            break;

                        //---------------------------------------PROVIDER MENU OPTION 5 - Exit provider menu ----------------------------------------
                        case 5:
                            cout << "\n\tExiting Provider Menu, back to main menu" << endl;
                            break;

                        //---------------------------------------DEFAULT-----------------------------------------------------------------------------
                        default:
                            cout << "\n\tInvalid Option! Please try again! : " << endl;

                    }                           //switch case for PROVIDER MENU

                } while(userOption != 5);  //do while loop for continuous input

            }                       //if to check if check is valid
            break;

        //-------------------------------------------MAIN MENU OPTION 3-------------------------------------------------------------------------------------------------------------------------------------
        case 3:
            cout << "\nExiting Main Menu!" << endl;
            break;

        default:
            cout << "Invalid Option! Please try again!" << endl;

    } //MAIN MENU SWITCH CASE

} //exeCmd

//    cout << "\n**** Main Menu ****" << endl;                        //DONE
//    cout << "1- Manager Login"      << endl;                        //DONE
//    cout << "2- Provider Login"     << endl;                        //DONE
//    cout << "3- Quit"               << endl;                        //DONE

//    cout << "\n\t**** Manager Menu ****"    << endl;                //DONE
//    cout << "\t1- Manage Members"           << endl;                //DONE
//    cout << "\t2- Manage Providers"         << endl;                //DONE
//    cout << "\t3- Generate Provider Report" << endl;                //DONE //STILL NEEDS FORMATTING
//    cout << "\t4- Generate Member Report"   << endl;                //DONE //STILL NEEDS FORMATTING
//    cout << "\t5- Return to Main Menu"      << endl;                //DONE

//    cout << "\n\t**** Provider Menu ****" << endl;                  //DONE
//    cout << "\t1- Validate Members"       << endl;                  //
//    cout << "\t2- Enter Service Details"  << endl;                  //
//    cout << "\t3- View Service History"   << endl;                  //
//    cout << "\t4- View Service Directory" << endl;                  //DONE
//    cout << "\t5- Return to Main Menu"    << endl;                  //DONE

//    cout << "\n\t\t**** Manage Members Menu ****"    << endl;       //DONE
//    cout << "\t\t1- Create New Member Record"        << endl;       //DONE
//    cout << "\t\t2- Update/Inactivate Member Record" << endl;       //DONE
//    cout << "\t\t3- Return to Manager Menu"          << endl;       //DONE

//    cout << "\n\t\t**** Manage Providers Menu ****"    << endl;     //DONE
//    cout << "\t\t1- Create New Provider Record"        << endl;     //DONE
//    cout << "\t\t2- Update/Inactivate Provider Record" << endl;     //DONE
//    cout << "\t\t3- Return to Manager Menu"            << endl;     //DONE

void displayMainMenu() {
    cout << "\n**** Main Menu ****" << endl;
    cout << "1- Manager Login"      << endl;
    cout << "2- Provider Login"     << endl;
    cout << "3- Quit"               << endl;
}

void providerMenu() {
    cout << "\n\t**** Provider Menu ****" << endl;
    cout << "\t1- Validate Members"       << endl;
    cout << "\t2- Enter Service Details"  << endl;
    cout << "\t3- View Service History"   << endl;
    cout << "\t4- View Service Directory" << endl;
    cout << "\t5- Return to Main Menu"    << endl;
}

void managerMenu() {
    cout << "\n\t**** Manager Menu ****"    << endl;
    cout << "\t1- Manage Members"           << endl;
    cout << "\t2- Manage Providers"         << endl;
    cout << "\t3- Generate Provider Report" << endl;
    cout << "\t4- Generate Member Report"   << endl;
    cout << "\t5- Return to Main Menu"      << endl;
}

void manageMembersMenu() {
    cout << "\n\t\t**** Manage Members Menu ****"    << endl;
    cout << "\t\t1- Create New Member Record"        << endl;
    cout << "\t\t2- Update/Inactivate Member Record" << endl;
    cout << "\t\t3- Return to Manager Menu"          << endl;
}

void manageProvidersMenu() {
    cout << "\n\t\t**** Manage Providers Menu ****"    << endl;
    cout << "\t\t1- Create New Provider Record"        << endl;
    cout << "\t\t2- Update/Inactivate Provider Record" << endl;
    cout << "\t\t3- Return to Manager Menu"            << endl;
}

void printDetails(string first, string last, string street, string city, string state, string tempZ) {
    cout << "\t\tFirst Name    : " << first  << endl;
    cout << "\t\tLast Name     : " << last   << endl;
    cout << "\t\tStreet Address: " << street << endl;
    cout << "\t\tCity          : " << city   << endl;
    cout << "\t\tState         : " << state  << endl;
    cout << "\t\tZipcode       : " << tempZ  << endl;
}

void resetVariables(string & first, string & last, string & type, string & status,
                    string & street, string & city, string & state, string & tempZ,
                    int & zip, long & id, int & i, char & save, string & input)
{
    first  = "";
    last   = "";
    type   = "";
    status = "";
    street = "";
    city   = "";
    state  = "";
    tempZ  = "";
    zip = 0;
    id  = 0;
    i   = 0;
    save = '\0';
    input = "";
}

void displayWelcomeMsg() {
    cout << "\nWelcome to the ChocAn interface!\n";
}

void displayExitMsg() {
    cout << "\nThank you for using the ChocAn interface!\n";
}

