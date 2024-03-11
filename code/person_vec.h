#include "person.h"
#include <vector>

using std::vector;

class PersonVec
{
	public:
		//Azeezah - I might change this add function to be different than the upload
		//person function
		int add_person(const Person & to_add);
		int update_person(const long & to_find, const Person & to_change);
		
		int upload_person(const Person & to_upload);
		
		int verify_person(const long to_compare);
		int find_person(const long to_compare);
	private:
		vector<Person> per_vec;
		Person * hold;
		long starting_value;
};
