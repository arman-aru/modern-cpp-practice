// ═══════════════════════════════════════════════════════════════
//  OOP 03 — Polymorphism, virtual function, vtable
// ═══════════════════════════════════════════════════════════════

#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
protected:
    string model;

public:
    Vehicle(string m)
    {
        model = m;
    }

    virtual void show()
    {

        cout << "Ami ekta Vehicle: " << model << "\n";
    }
};

class Sportsbike : public Vehicle

{
private:
    int engineCC;

public:
    Sportsbike(string m, int cc) : Vehicle(m)

    {
        engineCC = cc;
    }

    void show() override
    {
        cout << "Ami ekta Sportbike: " << model << " " << engineCC << "cc\n";
    }
};

class Car : public Vehicle

{
private:
    int doors;

public:
    Car(string m, int d) : Vehicle(m)

    {
        doors = d;
    }
    void show() override
    {
        cout << "Ami ekta Car: " << model << " " << doors << " doors\n";
    }
};

int main()
{
    Sportsbike r15("Yamaha R15", 155);
    Car civic("Honda Civic", 4);
    Car corolla("Toyota Corolla", 4);

    Vehicle *showroom[3];
    showroom[0] = &r15;
    showroom[1] = &civic;
    showroom[2] = &corolla;

    for (int i = 0; i < 3; i++)
    {
        showroom[i]->show();
    }

    return 0;
}
