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
    };

};

int main()
{
    Vehicle v("Honda");
    v.show();
Sportsbike r15  ("Yamaha R15", 155); 

    r15.show();
    Vehicle* p = &r15;
p->show();

    return 0;
}