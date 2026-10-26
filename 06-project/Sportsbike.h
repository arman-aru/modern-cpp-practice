#pragma once
#include "Vehicle.h"

class Sportsbike : public Vehicle
{
private:
    int engineCC;

public:
    Sportsbike(string b, string m, double p, int cc, string s) : Vehicle(b, m, p, s)
    {
        engineCC = cc;
    }
    void printInfo() override
    {
        cout << brand << " " << model << " | Price: " << price << " | Engine: " << engineCC << "cc | Supplier: " << supplierName << "\n";
    }
};
