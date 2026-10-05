#pragma once

#include <iostream>
#include <string>
#include "Utils.cpp"

using namespace std;

// Parent class (abstract) untuk Hierarchical Inheritance
class Console
{
protected:
    string consoleId;
    string name;
    int hourlyRate;
    bool available;

public:
    Console(string consoleId, string name, int hourlyRate)
        : consoleId(consoleId), name(name), hourlyRate(hourlyRate), available(true) {}

    // pure virtual: wajib di-override oleh child
    virtual string getConsoleType() const = 0;

    // bisa di-override child (contoh: PS5 menambah biaya VR)
    virtual int calculateCost(int hours) const
    {
        return hourlyRate * hours;
    }

    bool isAvailable() const { return available; }
    void setAvailable(bool status) { available = status; }
    string getId() const { return consoleId; }
    string getName() const { return name; }

    virtual void display() const
    {
        cout << "[" << getConsoleType() << "] " << consoleId << " | " << name
             << " | " << formatRupiah(hourlyRate) << "/jam | "
             << (available ? "Tersedia" : "Disewa");
    }

    virtual ~Console() {}
};
