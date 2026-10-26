#pragma once
#include <iostream>
#include <string>

using namespace std;

class Customer
{
private:
    string name;
    string email;

public:
    Customer(string n, string e)
    {
        name = n;
        email = e;
    }
    string getName() { return name; }
    string getEmail() { return email; }

    void printInfo()
    {
        cout << name << " | " << email << "\n";
    }
};
