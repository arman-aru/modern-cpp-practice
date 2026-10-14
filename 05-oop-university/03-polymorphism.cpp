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

class Sportsbike : public Vehicle

{
    private:
	int engineCC;

    public:
Sportsbike(string m, int cc) : Vehicle(m)

    {
 engineCC = cc;

    }

    void show()
    {
        cout << "Ami ekta Sportbike: " << model << " " << engineCC << "cc\n";
    };

};

int main()
{
    Vehicle v("Honda");
    v.show();
Sportsbike r15  ("Yamaha R15", 155); 

    r15.show();
    return 0;
}