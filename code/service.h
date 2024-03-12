#pragma once
#include "utilities.h"

using std::string;

class Service 
{
	public:
		Service();
		Service(const int & id, const string & i_name, const float & i_cost);
		
		int compare_ID(const int & id);
		int display_service(void) const;

	private:
		int ID;
		string service_name;
		float service_fee;
};
