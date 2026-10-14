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
    inventory.addVehicle(new Sportsbike("Yamaha", "R1M", 10000, 1000));
    inventory.addVehicle(new Sportsbike("Suzuki", "GSXR", 20000, 1000));
    inventory.addVehicle(new Sportsbike("BMW", "1000RR", 30000, 1000));
    inventory.addVehicle(new Sportsbike("CF Moto", "V4 SR-RR", 40000, 1000));
    inventory.addVehicle(new Car("BMW", "E90", 50000, 4));
    inventory.addVehicle(new Car("Mercedes", "AMG", 50000, 4));
    inventory.addVehicle(new Car("Audi", "B8", 50000, 4));
    inventory.addVehicle(new Car("Toyota", "E90", 50000, 4));

    int choice = -1;
    while (choice != 0)
    {
        cout << "\n=== Dealership Menu ===\n";
        cout << "1. Show all vehicles\n";
        cout << "2. Reserve a vehicle\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        if (choice == 1)
        {
            inventory.showAll();
        }
        else if (choice == 2)
        {
            string name, email;

            int index;
            cout << "Your name: ";
            cin >> name;
            cout << "Your Email: ";
            cin >> email;
            cout << "Vehicle number (0, 1, ....): ";

            cin >> index;

            try
            {
                Customer customer(name, email);
                Reservation reservation(&customer, inventory.getVehicle(index));
                reservation.printInfo();
            }
            catch (const out_of_range &e)
            {
                cout << "Error: " << e.what() << "\n";
            }
        }
        else if (choice == 0)
        {
            cout << "Goodbye!\n";
        }
        else
        {
            cout << "Invalid option\n";
        }
    }

    return 0;
}