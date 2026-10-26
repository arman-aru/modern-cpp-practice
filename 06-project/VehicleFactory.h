#pragma once
#include <stdexcept>
#include <string>
#include "Car.h"
#include "Sportsbike.h"

using namespace std;

class VehicleFactory
{
public:
    static Vehicle *create(int type, string brand, string model, double price, int extra, string supplierName)
    {
        if (type == 1)
        {
            return new Sportsbike(brand, model, price, extra, supplierName);
        }
        if (type == 2)
        {
            return new Car(brand, model, price, extra, supplierName);
        }
        throw invalid_argument("Unknown vehicle type " + to_string(type));
    }
};
