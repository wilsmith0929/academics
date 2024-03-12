#include "person_vec.h"


int PersonVec::add_person(const long & id, const string & i_type, const string & first, const string & last
, const string & s_address, const string & i_city, const string & i_state, const int & zip)
{
	Person to_add(id, A_STAT, i_type, first, last, s_address, i_city, i_state, zip);
	per_vec.push_back(to_add);

	return 0;
}

int PersonVec::update_person(const long & to_find, const Person & to_change)
{
	find_person(to_find);

	hold->change_person_info(to_change);

	return 1;
}

int PersonVec::upload_person(const long & id, const string & i_status, const string & i_type, const string & first, const string & last
, const string & s_address, const string & i_city, const string & i_state, const int & zip)
{
	Person to_upload(id, i_status, i_type, first, last, s_address, i_city, i_state, zip);
	per_vec.push_back(to_upload);

	return 0;	
}

//Verifies the person or the ID passed in.
//Refer to the verify_person function in the person class for return 
//values.
int PersonVec::verify_person(const long to_compare)
{
	int result = -1;
	vector<Person>::iterator it;
	
	for (it = per_vec.begin(); it < per_vec.end(); ++it)
	{
		if (it->compare_ID(to_compare) == 0)
		{
			result = it->verify_person(to_compare);
			return result;	
		}
	}

	return 1;
}

//Find the person, then holds the person object by pointing hold at it.
int PersonVec::find_person(const long to_compare)
{
	unsigned int size = per_vec.size();
	
	for (unsigned int i = 0; i < size; ++i)
	{
		if (per_vec[i].compare_ID(to_compare) == 0)
		{
			hold = &per_vec[i];
			return 0;	
		}
	}
	return 1;	
}

int PersonVec::display_people(void) const
{
	unsigned int size = per_vec.size();
	for (unsigned int i = 0; i < size; ++i)
	{
		per_vec[i].display_person();		
	}
	
	return 0;
}

void PersonVec::load_from_file(const string file_name, const string type) {
	long temp_ID;
	string temp_status;
	string temp_type;
	string temp_first_name;
	string temp_last_name;
	string temp_street_add;
	string temp_city;
	string temp_state;
	int temp_zip_code;

	ifstream in;

	in.open(file_name);
	if(!in) {
		cerr << "\nFailed to open " << file_name << " Exitting!" << endl;
		exit(0);
	}

	
	
}
