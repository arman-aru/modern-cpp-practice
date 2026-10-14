#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string brand;
    string model;
    double price;

public:
    Vehicle(string b, string m, double p)
    {
        brand = b;
        model = m;
        price = p;
    }

    virtual void printInfo() = 0;
    virtual ~Vehicle()
    {
        cout << "Vehicle destroyed: " << brand << " " << model << "\n";
    }
};

int main()
{

    return 0;
}