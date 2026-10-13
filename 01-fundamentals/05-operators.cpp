// ═══════════════════════════════════════════════════════════════
//  05 — Operators (+ - * / %, ==, &&, ||)
// ═══════════════════════════════════════════════════════════════
//
// 1.  ( )              ← bracket, sob theke age
// 2.  !                ← NOT
// 3.  *  /  %          ← gun, bhag, baki
// 4.  +  -             ← jog, biyog
// 5.  <  >  <=  >=     ← tulona
// 6.  ==  !=           ← soman/oshoman
// 7.  &&               ← AND
// 8.  ||               ← OR
//
// ═══════════════════════════════════════════════════════════════

#include <iostream>
using namespace std;

int main()
{
    int numDao = 0;
    cout << "Akta number dao : ";
    cin >> numDao;
    cout << " -----Number Analyzer ----- " << "\n";
    cout << " Number : " << numDao << "\n";
    cout << " 5 diye bhag : " << (numDao / 5) << "\n";
    cout << " 5 er baki : " << (numDao % 5) << "\n";
    cout << " Sesh digit : " << (numDao % 10) << "\n";
    cout << " Sesh digit bad : " << (numDao / 10) << "\n";
    cout << " Jugmo? :  " << (numDao % 2 == 0) << "\n";
    cout << " Bijor? : " << (numDao % 2 != 0) << "\n";
    cout << " Do-onker? : " << (numDao > 9 && numDao <100 ) << "\n";
    cout << " FizzBuzz? : " << (numDao % 3 == 0 || numDao % 5 == 0) << "\n";
    return 0;
}