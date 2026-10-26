#pragma once
#include <iostream>
#include <string>

using namespace std;

class Vehicle
{
protected:
    string brand;
    string model;
    double price;
    string supplierName;
    bool reserved;

public:
    Vehicle(string b, string m, double p, string s)
    {
        brand = b;
        model = m;
        price = p;
        supplierName = s;
        reserved = false;
    }

    string getTitle() { return brand + " " + model; }
    string getSupplierName() { return supplierName; }
    bool isReserved() { return reserved; }
    void reserve() { reserved = true; }

    virtual void printInfo() = 0;
    virtual ~Vehicle()
    {
        cout << "Vehicle destroyed: " << brand << " " << model << "\n";
    }
};
