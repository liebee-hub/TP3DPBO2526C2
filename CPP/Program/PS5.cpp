#pragma once

#include "Console.cpp"

class PS5 : public Console
{
private:
    bool supportsVR;
    static const int VR_SURCHARGE = 3000; // biaya tambahan VR per jam

public:
    PS5(string consoleId, string name, int hourlyRate, bool supportsVR)
        : Console(consoleId, name, hourlyRate), supportsVR(supportsVR) {}

    string getConsoleType() const override { return "PS5"; }

    // OVERRIDE: unit dengan VR dikenakan biaya tambahan per jam (polimorfisme)
    int calculateCost(int hours) const override
    {
        int rate = hourlyRate + (supportsVR ? VR_SURCHARGE : 0);
        return rate * hours;
    }

    void display() const override
    {
        Console::display();
        cout << " | VR: " << (supportsVR ? "Ya" : "Tidak") << endl;
    }
};
