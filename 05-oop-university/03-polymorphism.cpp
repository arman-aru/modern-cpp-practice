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

    void show()
    {

        cout << "Ami ekta Vehicle: " << model << "\n";
    }
};

int main()
{
    Vehicle v("Honda");
    v.show();
    return 0;
}