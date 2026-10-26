#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "Vehicle.h"

using namespace std;

class Inventory
{
private:
    vector<Vehicle *> vehicles;

public:
    void addVehicle(Vehicle *v)
    {
        vehicles.push_back(v);
    }

    void showAll()
    {
        for (int i = 0; i < (int)vehicles.size(); i++)
        {
            cout << i << ". ";
            vehicles[i]->printInfo();
        }
    }

    Vehicle *getVehicle(int index)
    {
        if (index < 0 || index >= (int)vehicles.size())
        {
            throw out_of_range("Vehicle not found at index " + to_string(index));
        }

        return vehicles[index];
    }

    ~Inventory()
    {
        for (Vehicle *v : vehicles)
        {
            delete v;
        }
    }
};
