#pragma once
#include <iostream>
#include <string>
#include "Customer.h"
#include "DealershipExceptions.h"
#include "Inventory.h"
#include "Repository.h"
#include "Supplier.h"
#include "VehicleFactory.h"

using namespace std;

class Dealership
{
private:
    string name;
    Inventory inventory;
    Repository<Supplier> suppliers;
    Repository<Customer> customers;

public:
    Dealership(string n)
    {
        name = n;
    }

    void addSupplier(Supplier s)
    {
        suppliers.add(s);
    }

    void showSuppliers()
    {
        for (int i = 0; i < suppliers.size(); i++)
        {
            cout << i << ". ";
            suppliers.get(i).printInfo();
        }
    }

    void registerCustomer(Customer c)
    {
        customers.add(c);
    }

    void showCustomers()
    {
        if (customers.size() == 0)
        {
            cout << "No customers yet.\n";
            return;
        }
        for (int i = 0; i < customers.size(); i++)
        {
            cout << i << ". ";
            customers.get(i).printInfo();
        }
    }

    void addVehicle(Vehicle *v)
    {
        inventory.addVehicle(v);
    }

    void showVehicles()
    {
        cout << "=== " << name << " ===\n";
        inventory.showAll();
    }

    Vehicle *reserveVehicle(int index)
    {
        Vehicle *v = inventory.getVehicle(index);
        if (v->isReserved())
        {
            throw ReservationException(v->getTitle() + " is already reserved");
        }
        v->reserve();
        return v;
    }

    void orderVehicle(int supplierIndex, int type, string brand, string model, double price, int extra)
    {
        Supplier supplier = suppliers.get(supplierIndex);
        if (!supplier.suppliesBrand(brand))
        {
            throw SupplierException(supplier.getName() + " does not supply " + brand);
        }

        inventory.addVehicle(VehicleFactory::create(type, brand, model, price, extra, supplier.getName()));
        cout << "Ordered " << brand << " " << model << " from " << supplier.getName() << "\n";
    }
};
