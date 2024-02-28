#include <iostream>
#include <vector>
#include <string>
using namespace std;

// idk where to put these because they are used in multiple classes
// Option: Make them in Interface's "display_menu" method and then pass them to the other classes
// Which will mean passing by reference and also creating other class objects in "display_menu"
// vector<Member> member_list;
// vector<Provider> provider_list;

class Interface {
    public:
        Interface();
        bool display_menu();
        bool display_providers();
    private:
};

class Manager {
    public:
        Manager();
        bool add_a_provider();
        bool update_a_provider();
        bool remove_a_provider();
        bool add_a_member();
        bool update_a_member();
        bool remove_a_member();
    private:
};

class Service {
    public:
        Service();

    private:

};

class Provider {
    public:
        Provider();
    private:
        Service current_service;
};

class Member {
    public:
        Member();
    private:
};
