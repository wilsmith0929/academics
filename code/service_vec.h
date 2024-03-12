#pragma once
#include "service.h"

class SerVec
{
	public:
		int upload_services(const string & filename);	
		
		int add_service(const int & id, const string & name, const float & cost);
		int display_services(void) const;
		int verify_service(const int to_find);

		int display_found_service(void) const;
	private:
		vector<Service> ser_vec;
		Service * hold;
};
