#pragma once
#include "utilities.h"
#include "provider.h"
#include "member.h"
#include "service.h"

class Manager {
    public:
        Manager();
        bool manager_interface(vector<Provider> & provider_list, vector<Member> & member_list);

        //some more constructors
        bool add_a_provider(vector<Provider> & provider_list);
        bool update_a_provider(vector<Provider> & provider_list);
        bool remove_a_provider(vector<Provider> & provider_list);
        bool add_a_member(vector<Member> & member_list);
        bool update_a_member(vector<Member> & member_list);
        bool remove_a_member(vector<Member> & member_list);
    private:
};