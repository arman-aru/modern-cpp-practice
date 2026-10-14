// ═══════════════════════════════════════════════════════════════
//  06 — Conditions (if / else if / else, switch)
// ═══════════════════════════════════════════════════════════════

#include <iostream>
using namespace std;

int main()
{

    int marks = 0;
    cout << "Marks dao: ";
    cin >> marks;
    if (marks >= 80)
    {
        cout << "Pass. Your grade is A+";
    }
    else if (marks >= 70)
    {
        cout << "Pass. Your grade is A";
    }
    else if (marks >= 50)
    {
        cout << "Pass. Your grade is B";
    }
    else if (marks >= 40)
    {
        cout << "Pass. Your grade is C";
    }
    else
    {
        cout << "Fail";
    }

    return 0;
}
