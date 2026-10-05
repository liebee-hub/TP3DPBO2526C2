#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include "Customer.cpp"
#include "Console.cpp"
#include "RentalPeriod.cpp"

using namespace std;

class Rental
{
private:
    string rentalId;
    Customer *customer;  // AGGREGATION: hanya referensi, tidak dibuat di sini
    Console *console;    // AGGREGATION: hanya referensi, tidak dibuat di sini
    RentalPeriod period; // COMPOSITION: dibuat di dalam Rental
    int totalCost;

public:
    Rental(string rentalId, Customer *customer, Console *console, int startHour, int hours)
        : rentalId(rentalId), customer(customer), console(console),
          period(startHour, hours), totalCost(0)
    {
        totalCost = calculateTotal();
    }

    // biaya konsol (polimorfik) dikurangi diskon pelanggan
    int calculateTotal() const
    {
        int base = console->calculateCost(period.getDurationHours());
        return (int)round(base * (1.0 - customer->getDiscountRate()));
    }

    void finish() { console->setAvailable(true); }

    void display() const
    {
        cout << rentalId << " | " << customer->getName() << " | "
             << console->getId() << " (" << console->getConsoleType() << ") | ";
        period.display();
        cout << " | Total: " << formatRupiah(totalCost) << endl;
    }
};
