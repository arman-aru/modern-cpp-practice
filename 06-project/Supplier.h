#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Supplier
{
private:
    string name;
    string country;
    string email;
    vector<string> brands;
    int deliveryDays;

public:
    Supplier(string n, string c, string e, vector<string> b, int d)
    {
        name = n;
        country = c;
        email = e;
        brands = b;
        deliveryDays = d;
    }
    string getName() { return name; }

    bool suppliesBrand(string brand)
    {
        for (string b : brands)
        {
            if (b == brand)
            {
                return true;
            }
        }
        return false;
    }

    void printInfo()
    {
        cout << name << " | " << country << " | " << email << " | Delivery: " << deliveryDays << " days | Brands: ";
        for (string b : brands)
        {
            cout << b << " ";
        }
        cout << "\n";
    }
};
