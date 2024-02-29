#pragma once
#include "utilities.h"

class Member {
    public:
        Member();
        //add some more constructors
        bool set_member_info(char name[], int ID[], char addr[], char city[], char state[], int zipcode[]);
        void display_member_info();
    private:
        char member_name[25];
        int member_ID[9];
        char member_street_addr[25];
        char member_city[14];
        char member_state[2];
        int member_zipcode[5];
};