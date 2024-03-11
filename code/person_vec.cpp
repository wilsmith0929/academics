#include "person_vec.h"
using namespace std;

int PersonVec::add_person(const Person & to_add)
{
	per_vec.push_back(to_add);

	return 0;
}

int PersonVec::update_person(const long & to_find, const Person & to_change)
{
	find_person(to_find);

	hold->change_person_info(to_change);

	return 1;
}

int PersonVec::upload_person(const Person & to_upload)
{
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
