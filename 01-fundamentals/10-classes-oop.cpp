// ═══════════════════════════════════════════════════════════════
//  10 — Classes & OOP (constructor, encapsulation)
// ═══════════════════════════════════════════════════════════════
// ═══════════════════════════════════════════════════════════════

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string nam;
    int boyosh;
    double cgpa;

public:
    void setCgpa(double c)
    {
        if (c >= 0.0 && c <= 4.0)
        {
            cgpa = c;
        }
        else
        {
            cout << "Bhul CGPA! 0 kora holo. \n";
            cgpa = 0.0;
        }
    }
    double getCgpa()
    {
        return cgpa;
    }
    Student(string n, int b, double c)
    {
        nam = n;
        boyosh = b;
        setCgpa(c);
    }

    void dekhao()
    {
        cout << nam << " | " << boyosh << " | " << cgpa << "\n";
    }
};

int main()
{
    Student s1("Arman", 25, 99.40);
    Student s2("Rahim", 26, 3.50);
    Student s3("Karim", 23, 3.80);
    Student s4("Sheeema", 20, 3.90);

    s1.dekhao();
    s2.dekhao();
    s3.dekhao();
    s4.dekhao();
    return 0;
}

