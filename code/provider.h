#pragma once
#include "utilities.h"

#include "service.h"

class Provider {
    public:
        Provider();
        bool provider_interface();
        bool display_providers();
        bool set_provider_info(char name[], int ID[], char addr[], char city[], char state[], int zipcode[]);
        void display_provider_info();
    private:
        Service current_service;
        char provider_name[25];
        int provider_ID[9];
        char street_addr[25];
        char provider_city[14];
        char provider_state[2];
        int provider_zipcode[5];

};