#pragma once
#include <functional>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Menu
{
private:
    string title;
    vector<string> labels;
    vector<function<void()>> actions;

public:
    Menu(string t)
    {
        title = t;
    }

    void addOption(string label, function<void()> action)
    {
        labels.push_back(label);
        actions.push_back(action);
    }

    void run()
    {
        int choice = -1;
        while (choice != 0)
        {
            cout << "\n=== " << title << " ===\n";
            for (int i = 0; i < (int)labels.size(); i++)
            {
                cout << i + 1 << ". " << labels[i] << "\n";
            }
            cout << "0. Exit\n";
            cout << "Choose: ";

            cin >> choice;

            if (choice == 0)
            {
                cout << "Goodbye!\n";
            }
            else if (choice >= 1 && choice <= (int)actions.size())
            {
                actions[choice - 1]();
            }
            else
            {
                cout << "Invalid option\n";
            }
        }
    }
};
