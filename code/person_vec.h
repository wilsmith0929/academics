#pragma once
#include "person.h"
#include "utilities.h"

using std::vector;

class PersonVec
{
	public:
		//Azeezah - I might change this add function to be different than the upload
		//person function
		int add_person(const long & id, const string & i_type, const string & first, const string & last,
			const string & s_address, const string & i_city, const string & i_state, const int & zip);
	
		int update_person(const long & to_find, const Person & to_change);
		
		int upload_person(const long & id, const string & i_status, const string & i_type, const string & first, const string & last, 
			const string & s_address, const string & i_city, const string & i_state, const int & zip);
		
		int verify_person(const long to_compare);
		int find_person(const long to_compare);

		int display_people(void) const;
	private:
		vector<Person> per_vec;
		Person * hold;
		long starting_value;
};
