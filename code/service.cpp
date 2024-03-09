#include "service.h"

Service::Service() {}

int Service::display_services()
{
    ifstream inputFile("services.txt");

    if (!inputFile.is_open()) 
    {
        cerr << "Error opening the file" << endl;
        return 1;
    }

    string line;
    while(getline(inputFile, line)) 
    {
        istringstream iss(line);
        
        if (iss >> service_code >> ws && getline(iss, service_name, '|') && iss >> service_fee)
        {
            cout << "Service Code: " << service_code << " Service Name: " << service_name << " Service Fee: " << service_fee << endl;
        }

        else {
            cerr << "Error parsing line" << line << endl;
        }
    }

    inputFile.close();

    return 1;
}
