#include "person.h"
using namespace std;

//Default Contructor
Person::Person()
{	
	ID = 0;
	status = "";
	type = "";
	first_name = "";
	last_name = "";
	street_add = "";
	city = "";
	state = "";
	zip_code = 0;
}

//Contructor with Arguments
Person::Person(const long & id, const string & i_status, const string & i_type, const string & first, const string & last
, const string & s_address, const string & i_city, const string & i_state, const int & zip)
{
	ID = id;
	status = i_status;
	type = i_type;
	first_name = first;
	last_name = last;
	street_add = s_address;
	city = i_city;
	state = i_state;
	zip_code = zip;
}

//Destructor - Sets everything to 0 or empty string
Person::~Person()
{
	ID = 0;
	status = "";
	type = "";
	first_name = "";
	last_name = "";
	street_add = "";
	city = "";
	state = "";
	zip_code = 0;
}

//Compares only the person's ID to the inputted ID
int Person::compare_ID(const long & id)
{
	if (ID == id) return 0;
	else if (ID < id) return -1;

	return 1;
}

//Verifies if there is a member, if no match return 1. If ID matches but the member is suspended return 2
//if ID matches but member is inactive, return 3. If member is active returns 0
int Person::verify_person(const long & id)
{
	if (compare_ID(id) == 0)
	{
		if (status.compare(S_STAT) == 0) return 2;
		else if (status.compare(I_STAT) == 0) return 3;
		return 0;
	}
	return 1;
}

int Person::display_person(void) const
{
	cout << "Person:\t" << first_name << " " << last_name << endl;
	cout << "ID:\t" << ID << endl;
	cout << "Status:\t" << status << endl;
	cout << "Type:\t" << type << endl << endl;

	cout << "Street:\t" << street_add << endl;
	cout << "City:\t" << city << endl;
	cout << "State:\t" << state << endl;
	cout << "Zip:\t" << zip_code << endl;

	return 0;
}

//Azeezah - This function is called to change the information of a person.
//The information that will be changed is initially loaded into another Person object.
//This object is then passed into the vector object which then finds the person to be updated. It then calles
//this function on the found object, passing in the Person object with new information.
int Person::change_person_info(const Person & updated)
{
	int to_return = 0;

	bool result = updated.first_name.empty();
	if (result == false)
	{
		first_name = updated.first_name;
	}

	result = updated.last_name.empty();
	if (result == false)
	{
		last_name = updated.last_name;
	}
	
	result = updated.status.empty();
	if (result == false)
	{
		if (status.compare(S_STAT) == 0) 
		{
			to_return = 2;	
		}
		else if (updated.status.compare(S_STAT) == 0) 
		{
			to_return = 3;
		}
		status = updated.status;
	}
	
	result = updated.street_add.empty();
	if (result == false)
	{
		street_add = updated.street_add;
	}
	
	result = updated.city.empty();
	if (result == false)
	{
		city = updated.city;
	}

	result = updated.state.empty();
	if (result == false)
	{
		state = updated.state;
	}

	if (updated.zip_code != 0)
	{
		zip_code = updated.zip_code;
	}
	
	return to_return;
}

int Person::change_first_name(const string & first)
{
	bool result = first.empty();
	if (result == false)
	{
		first_name = first;
		return 0;
	}
	return 1;
}

int Person::change_last_name(const string & last)
{
	bool result = last.empty();
	if (result == false)
	{
		last_name = last;
		return 0;
	}
	return 1;
}

int Person::change_status(const string & i_status)
{
	bool result = i_status.empty();
	if (result == false)
	{
		if (status.compare(S_STAT) == 0) return 2;
		else if (i_status.compare(S_STAT) == 0) return 3;
		status = i_status;
	}
	return 1;
}

int Person::change_street_add(const string & s_address)
{
	bool result = s_address.empty();
	if (result == false)
	{
		street_add = s_address;
		return 0;
	}
	return 1;
}

int Person::change_city(const string & i_city)
{
	bool result = i_city.empty();
	if (result == false)
	{
		city = i_city;
		return 0;
	}
	return 1;
}

int Person::change_state(const string & i_state)
{
	bool result = i_state.empty();
	if (result == false)
	{
		state = i_state;
		return 0;
	}
	return 1;
}

int Person::change_zip(const int & zip)
{
	if (zip != 0)
	{
		zip_code = zip;
		return 0;
	}
	return 1;
}

