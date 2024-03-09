#pragma once
#include "utilities.h"


class Service {
    public:
        Service();
        int display_services();

    private:
        int service_code;
        string service_name;
        int service_fee;


};
