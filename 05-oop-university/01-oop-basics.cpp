// ═══════════════════════════════════════════════════════════════
//  OOP 01 — OOP ki, 4 ta stombho
// ═══════════════════════════════════════════════════════════════
//  ENCAPSULATION er udahoron:
//    - data private (bahir theke chowa jay na)
//    - public function diye niyontrito access
//    - setter e validation — invalid obostha toiri-i hote pare na
// ═══════════════════════════════════════════════════════════════

#include <iostream>
#include <string>
using namespace std;

class Vehicle
{
private:
    string brand;
    double price;

public:
    Vehicle(string b, double p)
    {
        brand = b;
        setPrice(p);          // setter diye — validation ek jaygay
    }

    void setPrice(double p)
    {
        if (p > 0)
        {
            price = p;
        }
        else
        {
            cout << "Bhul dam! 0 kora holo.\n";
            price = 0;
        }
    }

    double getPrice()
    {
        return price;
    }

    void dekhao()
    {
        cout << brand << " - $" << price << "\n";
    }
};

int main()
{
    Vehicle v("Honda", 25000);
    v.dekhao();

    v.setPrice(-500);         // validation e atkabe
    v.setPrice(22000);        // boidho
    v.dekhao();

    cout << "getPrice() = " << v.getPrice() << "\n";

    // v.price = 99;          // comment khule dekho: compile error (private)

    return 0;
}
