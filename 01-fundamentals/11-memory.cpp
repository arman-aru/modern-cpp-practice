// ═══════════════════════════════════════════════════════════════
//  11 — Memory (stack vs heap, new/delete, smart ptr)
// ═══════════════════════════════════════════════════════════════
#include <iostream>
#include <memory>
using namespace std;

class Test
{
    public:
    Test() { cout << "Jonmo nilam" << "\n";}
    ~Test() {cout << "Mara gelam \n";}
};

int main()
{
    cout << "---- Block e dhukchi ----" << "\n";
    {
        Test t;
    }
    cout << "--- Block theke berolam --- \n";

    cout << "---Heap e banacci---" << "\n";
    {
        Test* t = new Test();
        delete t;
    }
    cout << "---BLock theke berolam---" << "\n";

    cout << "----Smart Pointer----" << "\n";
    {
        unique_ptr<Test> t = make_unique<Test>();
    }
    cout << "---Berolam---" << "\n";

    return 0;
}