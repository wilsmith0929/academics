#pragma once
#include "person.h"

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

		void load_from_file(const string file_name, const string type);
	private:
		vector<Person> per_vec;
		Person * hold;
		long starting_value;
};
