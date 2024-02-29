#pragma once
#include "utilities.h"

class Manager {
    public:
        Manager();
        bool manager_interface();

        //some more constructors
        bool add_a_provider();
        bool update_a_provider();
        bool remove_a_provider();
        bool add_a_member();
        bool update_a_member();
        bool remove_a_member();
    private:
};