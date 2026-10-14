#include <iostream>
#include <string>
#include <vector>
#include <stdexcept>

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
        for (Vehicle *v : vehicles)
        {
            v->printInfo();
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
class Reservation
{
private:
    Customer *customer;
    Vehicle *vehicle;

public:
    Reservation(Customer *c, Vehicle *v)
    {
        customer = c;
        vehicle = v;
    }

    void printInfo()
    {
        cout << "Reservation: " << customer->getName() << " booked ";
        vehicle->printInfo();
    }
};

int main()
{
    Inventory inventory;
    inventory.addVehicle(new Sportsbike("Yamaha", "R15", 5500, 155));
    inventory.addVehicle(new Car("BMW", "E90", 50000, 4));
    inventory.showAll();

    Customer c1("Arman", "arman@mail.com");
    cout << "Customer: " << c1.getName() << " | " << c1.getEmail() << "\n";

    Reservation r1(&c1, inventory.getVehicle(0));
    r1.printInfo();
    try
    {
        inventory.getVehicle(10)->printInfo();
    }
    catch (const out_of_range &e)
    {
        cout << "Error: " << e.what() << "\n";
    }

    return 0;
}