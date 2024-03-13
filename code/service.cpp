#include "service.h"
using namespace std;

Service::Service() {
	ID = 0;
	service_name = "";
	service_fee = 0.0;
}

Service::Service(const int & id, const string & i_name, const float & i_cost) {
	ID = id;
	service_name = i_name;
	service_fee = i_cost;
}
		
int Service::compare_ID(const int & id) {
	if (ID == id) return 0;
	else if (ID < id) return -1;
	return 1;
}

//Testing display function
int Service::display_service(void) const {
	cout << "ID:\t" << ID << endl;
	cout << "Name:\t" << service_name << endl;
	cout << "Cost:\t" << service_fee << endl << endl;
	return 0;
}

int Service::display(void) const {
	cout << setw(15) << left << ID;
	cout << setw(15) << left << service_name;
	cout << setw(15) << left << service_fee << endl;
	return 0;
}

