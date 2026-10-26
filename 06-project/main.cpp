#include <iostream>
#include <string>
#include "Dealership.h"
#include "FileStorage.h"
#include "Menu.h"

using namespace std;

void reserveMenu(Dealership &dealership, FileStorage &storage)
{
    string name, email;
    int index;
    cout << "Your name: ";
    cin >> name;
    cout << "Your Email: ";
    cin >> email;
    cout << "Vehicle number (0, 1, ....): ";
    cin >> index;

    try
    {
        Customer customer(name, email);
        Vehicle *v = dealership.reserveVehicle(index);
        dealership.registerCustomer(customer);
        Reservation reservation(&customer, v);
        reservation.printInfo();
        storage.saveReservation(reservation);
    }
    catch (const out_of_range &e)
    {
        cout << "Error: " << e.what() << "\n";
    }
    catch (const ReservationException &e)
    {
        cout << "Reservation error: " << e.what() << "\n";
    }
}

void orderMenu(Dealership &dealership)
{
    int supplierIndex, type, extra;
    string brand, model;
    double price;

    dealership.showSuppliers();
    cout << "Supplier number: ";
    cin >> supplierIndex;
    cout << "Type (1 = Sportsbike, 2 = Car): ";
    cin >> type;
    cout << "Brand: ";
    cin >> brand;
    cout << "Model: ";
    cin >> model;
    cout << "Price: ";
    cin >> price;
    if (type == 1)
    {
        cout << "Engine cc: ";
    }
    else
    {
        cout << "Number of doors: ";
    }
    cin >> extra;

    try
    {
        dealership.orderVehicle(supplierIndex, type, brand, model, price, extra);
    }
    catch (const SupplierException &e)
    {
        cout << "Supplier error: " << e.what() << "\n";
    }
    catch (const out_of_range &e)
    {
        cout << "Error: " << e.what() << "\n";
    }
    catch (const invalid_argument &e)
    {
        cout << "Error: " << e.what() << "\n";
    }
}

int main()
{
    Dealership dealership("Arman Motors");
    FileStorage storage("reservations.txt");

    dealership.addSupplier(Supplier("Yamaha Baltic", "Lithuania", "info@yb.lt", {"Yamaha"}, 7));
    dealership.addSupplier(Supplier("Moto Import", "Germany", "sales@moto.de", {"Suzuki", "BMW", "CF Moto"}, 14));
    dealership.addSupplier(Supplier("Auto Europe", "Poland", "cars@autoeu.pl", {"BMW", "Mercedes", "Audi", "Toyota"}, 10));

    dealership.addVehicle(new Sportsbike("Yamaha", "R1M", 10000, 1000, "Yamaha Baltic"));
    dealership.addVehicle(new Sportsbike("Suzuki", "GSXR", 20000, 1000, "Moto Import"));
    dealership.addVehicle(new Sportsbike("BMW", "1000RR", 30000, 1000, "Moto Import"));
    dealership.addVehicle(new Sportsbike("CF Moto", "V4 SR-RR", 40000, 1000, "Moto Import"));
    dealership.addVehicle(new Car("BMW", "E90", 50000, 4, "Auto Europe"));
    dealership.addVehicle(new Car("Mercedes", "AMG", 50000, 4, "Auto Europe"));
    dealership.addVehicle(new Car("Audi", "B8", 50000, 4, "Auto Europe"));
    dealership.addVehicle(new Car("Toyota", "E90", 50000, 4, "Auto Europe"));

    Menu menu("Dealership Menu");
    menu.addOption("Show all vehicles", [&]() { dealership.showVehicles(); });
    menu.addOption("Reserve a vehicle", [&]() { reserveMenu(dealership, storage); });
    menu.addOption("Show suppliers", [&]() { dealership.showSuppliers(); });
    menu.addOption("Order vehicle from supplier", [&]() { orderMenu(dealership); });
    menu.addOption("Show customers", [&]() { dealership.showCustomers(); });
    menu.addOption("Show saved reservations", [&]() { storage.showReservations(); });
    menu.run();

    return 0;
}
