#include "utilities.h"

int read_int() {
  //temp integer to be inputted
  int temp = 0;
  cin >> temp;
  while(!cin || temp <= 0) {
    cin.clear();
    cin.ignore(MAX, '\n');
    cout << "Invalid input! Try again: ";
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
    cout << "Invalid character! Try again: ";
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
    cout << "Invalid input! Try again: ";
    cin  >> temp;
  }
  cin.ignore(MAX, '\n');
  return temp;
}

long upload_people(PersonVec & members, PersonVec & providers, PersonVec & managers)
{
        string filename = PEOPLE_FILE;
        ifstream fin;

        long highest_ID = 0;

        long ID = 0;
        string id_buf = "";
        string status = "";
        string type = "";
        string first_name = "";
        string last_name = "";
        string street_add = "";
        string city = "";
        string state = "";
        int zip_code = 0;

        fin.open(filename.c_str());
        if (!fin) return 1;
        else
        {
                while(!fin.eof())
                {
                        getline(fin, id_buf, '|');
                        getline(fin, first_name, '|');
                        getline(fin, last_name, '|');
                        getline(fin, status, '|');
                        getline(fin, type, '|');
                        getline(fin, street_add, '|');
                        getline(fin, city, '|');
                        getline(fin, state, '|');

                        fin >> zip_code;
                        fin.ignore(20, '\n');

                        ID = stol(id_buf);


                        if (type.compare(MAN_TYPE) == 0)
                        {
                                managers.upload_person(ID, status, type, first_name, last_name, street_add, city, state, zip_code);
                        }
                        else if (type.compare(MEM_TYPE) == 0)
                        {
                                members.upload_person(ID, status, type, first_name, last_name, street_add, city, state, zip_code);
                        }
                        else
                        {
                                providers.upload_person(ID, status, type, first_name, last_name, street_add, city, state, zip_code);
                        }

                        if (ID > highest_ID)

                        {
                                highest_ID = ID;
                        }

                        fin.peek();
                }
        }

        fin.close();

        return highest_ID;
}
