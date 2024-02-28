#include <iostream>
#include <vector>
#include <string>
using namespace std;

#include "service.h"

class Provider {
    public:
        Provider();
    private:
        Service current_service;
};