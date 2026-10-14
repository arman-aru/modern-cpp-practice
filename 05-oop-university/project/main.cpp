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

class Sportsbike : public Vehicle
{
private:
    int engineCC;

public:
    Sportsbike(string b, string m, double p, int cc) : Vehicle(b, m, p)
    {
        engineCC = cc;
    }
    void printInfo() override
    {
        cout << brand << " " << model << " | Price: " << price << " | Engine: " << engineCC << "cc\n";
    }
};

class Car : public Vehicle
{
private:
    int numberOfDoors;

public:
    Car(string b, string m, double p, int d) : Vehicle(b, m, p)
    {
        numberOfDoors = d;
    }
    void printInfo() override
    {
        cout << brand << " " << model << " | Price: " << price << " | Number Of Doors: " << numberOfDoors << "\n";
    }
};

int main()
{
    Sportsbike bike("Yamaha", "R15", 5500, 155);
    bike.printInfo();
    Car sedan("BMW", "E90", 50000, 5);
    sedan.printInfo();

    return 0;
}