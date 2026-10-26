# Vehicle & Sportsbike Dealership System: Project Plan

## 1. Idea

A console application for a dealership that sells cars and sportsbikes.
The dealership buys vehicles from suppliers, keeps them in its inventory,
registers customers, and lets customers reserve a vehicle.

## 2. Main Classes

| Class | What it represents | Main data | Main actions |
|---|---|---|---|
| `Dealership` | The business itself; the central class of the program | name, inventory, suppliers, customers | add supplier, order vehicles from a supplier, register customer, reserve vehicle, show inventory |
| `Supplier` | A company that delivers vehicles to the dealership | name, country, contact email, brands supplied, delivery time (days) | show supplier info, check if it supplies a brand |
| `Vehicle` (abstract) | Common base for everything the dealership sells | brand, model, price, supplier name, reserved | `printInfo()` (pure virtual), `reserve()`, getters |
| `Car` | A car for sale (inherits `Vehicle`) | number of doors | overrides `printInfo()` |
| `Sportsbike` | A sportsbike for sale (inherits `Vehicle`) | engine cc | overrides `printInfo()` |
| `Customer` | A person who buys or reserves a vehicle | name, email | show customer info |
| `Inventory` | Storage of all vehicles in the dealership | list of vehicles | add, remove, list, get by index |
| `Reservation` | A customer reserving one vehicle | customer, vehicle | show reservation, convert to a file line |

### 2.1 Dealership (details)

`Dealership` is the "main" object. `main.cpp` only creates one `Dealership`
and starts the menu; all work goes through it.

- **Data:** name, one `Inventory`, a `Repository<Supplier>` and a
  `Repository<Customer>`.
- **Responsibilities:**
  - Register and list suppliers.
  - Order a vehicle from a supplier: checks the supplier sells that brand,
    creates the vehicle (via `VehicleFactory`) and puts it into the inventory.
  - Register and list customers.
  - Create a reservation: checks the vehicle exists and is not already
    reserved, otherwise throws an exception.

### 2.2 Supplier (details)

`Supplier` shows where the vehicles come from.

- **Data:** name (e.g. "Yamaha Baltic"), country, contact email,
  list of brands it supplies (e.g. Yamaha, Honda), delivery time in days.
- **Responsibilities:**
  - `suppliesBrand(brand)`: answers whether this supplier can deliver the brand.
  - Show its information.
- **Rule:** the dealership can only order a brand from a supplier that
  supplies it; otherwise a `SupplierException` is thrown.
- Every vehicle remembers which supplier delivered it (supplier name), so the
  inventory listing shows the source of each vehicle.

## 3. Relationships Between Classes

```
                    Dealership
     ┌──────────────┬────┴─────────┬──────────────┐
     ◆ owns         ◇ has          ◇ has          ◆ owns
  Inventory      Supplier(s)    Customer(s)    Reservation(s)
     ◆ owns                                      │ links
  Vehicle(s) ◄───────────────────────────────────┘ Customer + Vehicle
     ▲ inherits
  ┌──┴───┐
 Car  Sportsbike
```

| Relationship | Type | Why |
|---|---|---|
| `Car`, `Sportsbike` → `Vehicle` | Inheritance ("is-a") | A car *is a* vehicle; shared data lives in the base class |
| `Dealership` → `Inventory` | Composition (◆) | The inventory cannot exist without the dealership |
| `Inventory` → `Vehicle` | Composition (◆) | The inventory owns the vehicles and deletes them |
| `Dealership` → `Supplier` | Aggregation (◇) | A supplier is an independent company; it still exists if the dealership closes |
| `Dealership` → `Customer` | Aggregation (◇) | A customer exists independently of the dealership |
| `Reservation` → `Customer`, `Vehicle` | Association | A reservation only points to them; it does not own them |
| `Supplier` → `Vehicle` | Dependency | A supplier is used when creating vehicles but does not keep them |

## 4. OOP Concepts Shown

| Concept | Where |
|---|---|
| Encapsulation | All data is `private`; access only through methods (e.g. `Supplier::suppliesBrand`) |
| Inheritance | `Car` and `Sportsbike` inherit `Vehicle` |
| Abstraction | `Vehicle` is abstract (pure virtual `printInfo()`) |
| Polymorphism | `Inventory` stores `Vehicle*` and calls `printInfo()` on cars and bikes alike |
| Constructors / destructors | `Inventory` destructor frees all vehicles; virtual destructor in `Vehicle` |
| Object relationships | Composition, aggregation, association (section 3) |
| Exceptions | Invalid index, vehicle already reserved, supplier does not sell brand |
| Generics (templates) | `Repository<T>` used for suppliers (`Repository<Supplier>`) and customers (`Repository<Customer>`) |
| Design pattern | Factory (`VehicleFactory::create`) |
| SOLID | Each class has one job (S); a new vehicle type is added in `VehicleFactory` without changing `Inventory` (O) |
| Serialization | `Reservation::toFileLine()` turns an object into text; `FileStorage` saves reservations to `reservations.txt` and loads them back |
| Delegates | Menu actions stored as `std::function<void()>` (lambdas) |

## 5. Project Structure

All classes are header-only (`.h`), so the whole project builds from `main.cpp`
with one command: `clang++ -std=c++17 main.cpp -o dealership`.
Templates (`Repository<T>`) must live in headers anyway.

```
project/
├── main.cpp                 Entry point; creates the Dealership, adds data, builds the menu
├── Dealership.h             Central class; connects suppliers, inventory and customers
├── Supplier.h               Supplier data (name, country, email, brands, delivery days)
├── Vehicle.h                Abstract base class (brand, model, price, supplier name, reserved)
├── Car.h                    Derived class (number of doors)
├── Sportsbike.h             Derived class (engine cc)
├── Customer.h               Customer data (name, email)
├── Inventory.h              Owns and manages all vehicles
├── Reservation.h            Links a customer to a vehicle
├── Repository.h             Generic template container
├── VehicleFactory.h         Creates vehicles by type (Factory pattern)
├── FileStorage.h            Saves and loads reservations (serialization)
├── DealershipExceptions.h   Custom exception classes
└── Menu.h                   Console UI; menu actions stored as std::function
```

### Menu

```
1. Show all vehicles
2. Reserve a vehicle
3. Show suppliers
4. Order vehicle from supplier
5. Show customers
6. Show saved reservations
0. Exit
```

## 6. Example Flow

1. The program starts and creates the dealership "Arman Motors".
2. Admin adds supplier "Yamaha Baltic" (Lithuania, brands: Yamaha).
3. Admin orders a Yamaha R6 from "Yamaha Baltic" → the bike appears in the inventory.
4. Admin tries to order a BMW from "Yamaha Baltic" → error: this supplier does not sell BMW.
5. Customer "Jonas" registers and reserves the Yamaha R6.
6. Someone tries to reserve the same bike again → error: already reserved.
7. Every reservation is saved to `reservations.txt`; option 6 reads the file back.
