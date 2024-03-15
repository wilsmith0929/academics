#include "utilities.h"

int read_int() {
  //temp integer to be inputted
  int temp = 0;
  cin >> temp;
  while(!cin || temp <= 0) {
    cin.clear();
    cin.ignore(MAX, '\n');
    cout << "\nInvalid input! Try again: ";
    cin  >> temp;
  }
  cin.ignore(MAX, '\n');
  return temp;
}

long read_long() {
  //temp integer to be inputted
  long temp = 0;
  cin >> temp;
  while(!cin || temp <= 0) {
    cin.clear();
    cin.ignore(MAX, '\n');
    cout << "\nInvalid input! Try again: ";
    cin  >> temp;
  }
  cin.ignore(MAX, '\n');
  return temp;
}

char read_char() {
  //temp char to be inputted
  char temp = '\0';
  cin >> temp;
  while(!cin) {
    cin.clear();
    cin.ignore(MAX, '\n');
    cout << "\nInvalid character! Try again: ";
    cin  >> temp;
  }
  cin.ignore(MAX, '\n');
  return temp;
}

double get_double() {
  //temp double to be inputted
  double temp = 0;
  cin >> temp;
  while(!cin || temp <= 0) {
    cin.clear();
    cin.ignore(MAX, '\n');
    cout << "\nInvalid input! Try again: ";
    cin  >> temp;
  }
  cin.ignore(MAX, '\n');
  return temp;
}

string read_string() {
  //temp string to be inputted
  string input;
  getline(cin, input);
  //while(input.find_first_not_of(' ') == string::npos) {
  //  cout << "\nInvalid input! Try again: ";
  //  getline(cin, input);
  //}
  return input;
}

void printServices(const string & filename) {
  ifstream fin(filename);

  if (!fin) {
    cerr << "Failed to open file " << filename << endl;
    exit(0);
    return;
  }

  string line;
  while (getline(fin, line)) {
    cout << "\t" << line << endl;
  }

  fin.close();
}

string removeWhitespace(const string & str) {
    string newStr = str;
    newStr.erase(remove(newStr.begin(), newStr.end(), ' '), newStr.end());
    cout << newStr << endl;
    return newStr;
}

string getCurrentDateMMDDYYYY() {
    char time_char[80];
    time_t t = time(0);
    strftime(time_char, 80, "%m%d%Y", localtime(&t));
    string time_str = time_char;
    return time_str;
}

int checkIfFileEmptyAndOpenable(const string & filename) {
    ifstream fileToTest(filename);
    if (!fileToTest.is_open()) return 0;
    fileToTest.seekg(0, ios::end);
    if (fileToTest.tellg() == 0) return 1;
    fileToTest.close();
    return 2;
}


int generateProviderReport(const string & filename)
{
    int result = checkIfFileEmptyAndOpenable(filename);
    if (result != 2) return result;
    ifstream inputFile(filename);
    string line, filename_to_write;
    map<string, vector<vector<string>>> providerRecords;

    //Ignoring the first line specifying each part
    getline(inputFile, line);

    //Read input file and parse the service records
    while(getline(inputFile, line)) {
            size_t pos = 0;
            string field;
            vector<string> recordFields;
            while((pos = line.find('|')) != string::npos) {
                field = line.substr(0, pos);
                recordFields.push_back(field);
                line.erase(0, pos + 1);
            }
            recordFields.push_back(line);
            providerRecords[recordFields[6]].push_back(recordFields);
        }

        //Generate reports for each provider
        for (const auto &[providerName, records]: providerRecords) {
            filename_to_write = "../text-documents/weekly-provider-reports/" + removeWhitespace(providerName) + "_" +
                getCurrentDateMMDDYYYY() + "." + records.front()[5] + ".txt";
            ofstream outputFile(filename_to_write);
            outputFile << "First Name     : " << providerName << endl;
            outputFile << "Street Address : " << records.front()[7] << endl;
            outputFile << "City           : " << records.front()[8] << endl;
            outputFile << "State          : " << records.front()[9] << endl;
            outputFile << "Zip Code       : " << records.front()[10] << endl;
            outputFile << endl;
            outputFile << "Service Date   Record Date          Member Name            Member#        Service Code     Service Fee" << endl;

            //Write service records
            double totalFee = 0;
            for (const auto& record : records) {
            outputFile << record[1] << "   " << record[4] << "   "
                        << record[12] << "   " << record[11] << "   "
                        << record[0] << "\t" << record[3] << endl;
            totalFee += stod(record[3]);
            }
            outputFile << endl;
            outputFile << "Total number of consultations : " << records.size() << endl;
            outputFile << "Total fee for the week        : " << totalFee << endl;
            result = checkIfFileEmptyAndOpenable(filename_to_write);
            outputFile.close();
        }
    return result;
}

int generateMemberReport(const string & filename)
{
    int result = checkIfFileEmptyAndOpenable(filename);
    if (result != 2) return result;
    ifstream inputFile(filename);
    string line, filename_to_write;
    map<string, vector<vector<string>>> memberRecords;

    //Ignoring the first line specifying each part
    getline(inputFile, line);

    //Read input file and parse the service records
    while(getline(inputFile, line)) {
         size_t pos = 0;
         string field;
         vector<string> recordFields;
          while((pos = line.find('|')) != string::npos) {
             field = line.substr(0, pos);
             recordFields.push_back(field);
             line.erase(0, pos + 1);
          }
          recordFields.push_back(line);
          memberRecords[recordFields[12]].push_back(recordFields);
     }

     //Generate reports for each member
     for (const auto &[memberName, records]: memberRecords) {
         filename_to_write = "../text-documents/weekly-member-reports/" + removeWhitespace(memberName) + "_" +
             getCurrentDateMMDDYYYY() + "." + records.front()[11] + ".txt";
          ofstream outputFile(filename_to_write);
          outputFile << "Member Name    : " << memberName << endl;
          outputFile << "Member Number  : " << records.front()[11] << endl;
          outputFile << "Street Address : " << records.front()[12] << endl;
          outputFile << "City           : " << records.front()[13] << endl;
          outputFile << "State          : " << records.front()[14] << endl;
          outputFile << "Zip Code       : " << records.front()[15] << endl;
          outputFile << endl;
          outputFile << "Service Date   Provider Name          Service Name        Service Code" << endl;

          //Write service records
          for (const auto& record : records) {
            outputFile << record[1] << "   " << record[6] << "   "
                       << record[2] << "   " << record[0] << endl;
          }
          outputFile << endl;
          result = checkIfFileEmptyAndOpenable(filename_to_write);
          outputFile.close();
    }
    return result;
}

