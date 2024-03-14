#include "ser_pro.h"


ServicePro::ServicePro()
{
        provider_date = "";
        memset(received_date, 0, sizeof(received_date));
        received_time = NULL;
}

ServicePro::ServicePro(const Person & i_member, const Person & i_provider, const Service & i_service, const string & i_date, const time_t & rawtime)
{
        member = i_member;
        provider = i_provider;
        service = i_service;
        provider_date = i_date;

        received_time = localtime(&rawtime);
        strftime(received_date, 80, "%m-%d-%Y %H:%M:%S", received_time);
}

int ServicePro::input_provider(const Person & i_provider)
{
        provider = i_provider;
        return 0;
}

int ServicePro::input_member(const Person & i_member)
{
        member = i_member;
        return 0;
}

int ServicePro::input_service(const Service & i_service)
{
        service = i_service;
        return 0;
}

int ServicePro::input_provider_date(const string & i_date)
{
        provider_date = i_date;
        return 0;
}

int ServicePro::input_received_date(const time_t & rawtime)
{
        received_time = localtime(&rawtime);
        strftime(received_date, 80, "%m-%d-%Y %H:%M:%S", received_time);

        return 0;
}

int display(void)
{

        return 0;
}
