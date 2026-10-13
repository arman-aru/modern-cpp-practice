// ═══════════════════════════════════════════════════════════════
//  SOBCHEYE CHHOTO CLASS
//  Shudhu duita jinish: ekta data, ekta kaj.
// ═══════════════════════════════════════════════════════════════

#include <iostream>
#include <string>
using namespace std;

// class Kukur
// {
// public:
//     string nam;          // ← ei kukur er ekta NAAM ache      (data)

//     void dako()          // ← ei kukur DAKTE pare             (kaj)
//     {
//         cout << nam << " bole: Ghew ghew!\n";
//     }
// };

// int main()
// {
//     Kukur k1;            // ekta kukur banalam
//     k1.nam = "Tommy";    // tar naam dilam
//     k1.dako();           // take dakte bollam

//     return 0;
// }

class Vehicle
{
private:
    string model;
    double price;

public:
    Vehicle(string m, double p)
    {
        model = m;
        setPrice (p);
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

    void callKoro()
    {
        cout << "Bike er Model holo : " << model << " Dam holo: " << price << "\n";
    }
};

int main()
{
    Vehicle r15("Yamaha R15 V3", -350000);
    r15.callKoro();

    Vehicle r25("Yamaha R15 V3", 40000);
    r25.callKoro();

    Vehicle r35("Yamaha R15 V3", 350000);
    r35.callKoro();

    cout << r25.getPrice();

    return 0;
}