#pragma once

#include <iostream>
#include <string>
#include <vector>
#include "Console.cpp"
#include "Customer.cpp"
#include "Rental.cpp"

using namespace std;

class RentalShop
{
private:
    string shopName;
    vector<Console *> consoles;   // ARRAY OF OBJECT (polimorfik), AGGREGATION
    vector<Customer *> customers; // ARRAY OF OBJECT, AGGREGATION
    vector<Rental> rentals;       // ARRAY OF OBJECT, COMPOSITION (dibuat di rentConsole)
    int rentalCounter;

    Customer *findCustomer(const string &id)
    {
        for (auto c : customers)
            if (c->getId() == id)
                return c;
        return nullptr;
    }

    Console *findConsole(const string &id)
    {
        for (auto c : consoles)
            if (c->getId() == id)
                return c;
        return nullptr;
    }

public:
    RentalShop(string shopName) : shopName(shopName), rentalCounter(0) {}

    void addConsole(Console *console) { consoles.push_back(console); }
    void addCustomer(Customer *customer) { customers.push_back(customer); }

    bool rentConsole(string customerId, string consoleId, int startHour, int hours)
    {
        Customer *cust = findCustomer(customerId);
        Console *con = findConsole(consoleId);

        if (cust == nullptr || con == nullptr)
        {
            cout << "[GAGAL] Pelanggan atau konsol tidak ditemukan." << endl;
            return false;
        }
        if (!con->isAvailable())
        {
            cout << "[GAGAL] " << con->getId() << " sedang disewa, "
                 << cust->getName() << " tidak bisa menyewa saat ini." << endl;
            return false;
        }

        rentalCounter++;
        string num = to_string(rentalCounter);
        string rentalId = "R" + string(3 - num.length(), '0') + num;

        rentals.emplace_back(rentalId, cust, con, startHour, hours);
        con->setAvailable(false);

        cout << "[OK] " << rentalId << ": " << cust->getName()
             << " menyewa " << con->getId() << endl;
        return true;
    }

    void printAll() const
    {
        cout << "=== " << shopName << " ===" << endl;

        cout << "\n-- Daftar Konsol (" << consoles.size() << ") --" << endl;
        for (size_t i = 0; i < consoles.size(); i++)
        {
            cout << i + 1 << ". ";
            consoles[i]->display();
        }

        cout << "\n-- Daftar Pelanggan (" << customers.size() << ") --" << endl;
        for (size_t i = 0; i < customers.size(); i++)
        {
            cout << i + 1 << ". ";
            customers[i]->display();
        }

        cout << "\n-- Daftar Transaksi (" << rentals.size() << ") --" << endl;
        if (rentals.empty())
            cout << "(belum ada transaksi)" << endl;
        for (size_t i = 0; i < rentals.size(); i++)
        {
            cout << i + 1 << ". ";
            rentals[i].display();
        }
    }
};
