// ═══════════════════════════════════════════════════════════════
//  08 — Functions (parameter, return, overloading)
// ═══════════════════════════════════════════════════════════════
#include <iostream>
#include <string>
using namespace std;

void bolo(string kotha)
{
    cout << kotha << "\n";
}
int jog(int a, int b)
{
    return a + b;
}

void boloNew(string kothaTwo)
{
    cout << kothaTwo << "\n";
}
int gun(int a, int b)
{
    return a * b;
}
bool isEven(int n)
{
    return n % 2 == 0;
}
bool isOdd(int n)
{
    return !isEven(n);
}
int main()
{
    cout << jog(5, 3) << "\n";
    int fol = jog(10, 20);
    cout << "Fol = " << fol << "\n";
    cout << gun(4, 5) << "\n";
    cout << isEven(10) << "\n";
    bolo("Ami ekhon chollam");
    cout << isOdd(7) << "\n";  
    cout << isOdd(10) << "\n";
}