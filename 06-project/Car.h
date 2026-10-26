#pragma once
#include "Vehicle.h"

class Car : public Vehicle
{
private:
    int numberOfDoors;

public:
    Car(string b, string m, double p, int d, string s) : Vehicle(b, m, p, s)
    {
        numberOfDoors = d;
    }
    void printInfo() override
    {
        cout << brand << " " << model << " | Price: " << price << " | Number Of Doors: " << numberOfDoors << " | Supplier: " << supplierName << "\n";
    }
};
