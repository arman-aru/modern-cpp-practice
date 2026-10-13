// ═══════════════════════════════════════════════════════════════
//  03 — Input (cin)
// ═══════════════════════════════════════════════════════════════

#include <iostream>
using namespace std;

int main()
{
    int chipsDam = 0;
    int chipsQty = 0;
    int icecreamDam = 0;
    int icecreamQty = 0;
    cout << "Chips er dam = ";
    cin >> chipsDam;
    cout << "Chips koyta = ";
    cin >> chipsQty;
    cout << "Ice Cream er dam koto = ";
    cin >> icecreamDam;
    cout << "Ice Cream koyta = ";
    cin >> icecreamQty;
    int billTotal = (chipsDam * chipsQty) + (icecreamDam * icecreamQty);
    cout << "Tomar " << billTotal << " taka bill hoise. ";

    return 0;
}