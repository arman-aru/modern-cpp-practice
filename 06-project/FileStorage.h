#pragma once
#include <fstream>
#include <iostream>
#include <string>
#include "Reservation.h"

using namespace std;

class FileStorage
{
private:
    string fileName;

public:
    FileStorage(string f)
    {
        fileName = f;
    }

    void saveReservation(Reservation &reservation)
    {
        ofstream file(fileName, ios::app);
        if (!file)
        {
            cout << "Error: could not open " << fileName << "\n";
            return;
        }
        file << reservation.toFileLine() << "\n";
    }

    void showReservations()
    {
        ifstream file(fileName);
        if (!file)
        {
            cout << "No reservations saved yet.\n";
            return;
        }

        string line;
        int count = 0;
        while (getline(file, line))
        {
            cout << count << ". " << line << "\n";
            count++;
        }
    }
};
