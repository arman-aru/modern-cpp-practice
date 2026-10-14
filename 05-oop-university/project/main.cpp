#include <iostream>
#include <string>
#include <vector>

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
};

int main()
{
    vector<Vehicle *> showroom;
    showroom.push_back(new Sportsbike("Yamaha", "R15", 5500, 155));
    showroom.push_back(new Car("BMW", "E90", 50000, 4));
    for (Vehicle *v : showroom)
    {
        v->printInfo();
    }
    for (Vehicle *v : showroom)
    {
        delete v;
    }
    Customer c1("Arman", "arman@mail.com");
    cout << "Customer: " << c1.getName() << " | " << c1.getEmail() << "\n";


    return 0;
}