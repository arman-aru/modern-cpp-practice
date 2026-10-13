// ═══════════════════════════════════════════════════════════════
//  OOP 04 — Abstraction, abstract class, pure virtual
// ═══════════════════════════════════════════════════════════════
// ═══════════════════════════════════════════════════════════════

#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string model;
    double price;

public:
    Vehicle(string m, double p)
    {
        model = m;
        setPrice(p);
    }

    void setPrice(double p)
    {
        if (p > 0)
        {
            price = p;
        }
        else
        {
            cout << " Bhul dam" << "\n";
            price = 0;
        }
    }
    double getPrice()
    {
        return price;
    }

    virtual void callKoro()
    {
        cout << "Bike Model : " << model << "\n"
             << "Bike Price: " << price << "\n";
    }
};

class Sportsbike : public Vehicle
{
private:
    int engineCC;

public:
    Sportsbike(string m, double p, int cc)
        : Vehicle(m, p)
    {
        engineCC = cc;
    }

    void dekhaoCC()
    {
        cout << "Engine: " << engineCC << "\n";
    }
    void callKoro() override
    {
        cout << "Bike: " << model
             << " | " << price
             << " | " << engineCC << "cc\n";
    }
};

class Car : public Vehicle
{
private:
    int numberOfDoors;

public:
    Car(string m, double p, int doors)
        : Vehicle(m, p)
    {
        numberOfDoors = doors;
    }

    void callKoro() override
    {
        cout << "Car : " << model << " | " << price
             << " | " << numberOfDoors << "doors\n";
    }
};

int main()
{
    Sportsbike r15("Yamaha R15", 35000, 155);
    Car civic("Honda Civic", 250000, 4);
    Car corolla("Toyota Corolla", 350000, 5);

    Vehicle *inventory[3];
    inventory[0] = &r15;
    inventory[1] = &civic;
    inventory[2] = &corolla;

    for (int i = 0; i < 3; i++)
    {
        inventory[i]->callKoro();
    }

    return 0;
}