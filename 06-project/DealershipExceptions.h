#pragma once
#include <stdexcept>
#include <string>

using namespace std;

class ReservationException : public runtime_error
{
public:
    ReservationException(string msg) : runtime_error(msg) {}
};

class SupplierException : public runtime_error
{
public:
    SupplierException(string msg) : runtime_error(msg) {}
};
