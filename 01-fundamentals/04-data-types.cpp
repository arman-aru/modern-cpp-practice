// ═══════════════════════════════════════════════════════════════
//  04 — Data Types (int, double, char, bool, string)
// ═══════════════════════════════════════════════════════════════
// ═══════════════════════════════════════════════════════════════

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    string nam = "";
    int boyosh = 0;
    double cgpa = 0.0;
    string grade = "";

    cout << "Tomar naam ki = ";
    getline(cin, nam);
    cout << "Tomar boyosh koto = ";
    cin >> boyosh;
    cout << "Tomar CGPA koto = ";
    cin >> cgpa;
    cout << "Tomar Grade koto = ";
    cin >> grade;
    cout << fixed << setprecision(2);
    cout << "---- Student Card ----" << "\n";
    cout << "Naam : " << nam << "\n";
    cout << "Boyosh: " << boyosh << "\n";
    cout << "CGPA: " << cgpa << "\n";
    cout << "Grade: " << grade << "\n";

    return 0;
}