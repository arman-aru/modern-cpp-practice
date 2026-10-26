#pragma once
#include <iostream>
#include <string>
#include "Customer.h"
#include "Vehicle.h"

using namespace std;

class Reservation
{
private:
    Customer *customer;
    Vehicle *vehicle;

public:
    Reservation(Customer *c, Vehicle *v)
    {
        customer = c;
        vehicle = v;
    }

    void printInfo()
    {
        cout << "Reservation: " << customer->getName() << " booked ";
        vehicle->printInfo();
    }

    string toFileLine()
    {
        return customer->getName() + "," + customer->getEmail() + "," + vehicle->getTitle();
    }
};
