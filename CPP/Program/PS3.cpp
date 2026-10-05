#pragma once

#include "Console.cpp"

class PS3 : public Console
{
private:
    int hddSizeGB;

public:
    // consoleId, name, hourlyRate di-init oleh class Console
    PS3(string consoleId, string name, int hourlyRate, int hddSizeGB)
        : Console(consoleId, name, hourlyRate), hddSizeGB(hddSizeGB) {}

    string getConsoleType() const override { return "PS3"; }

    void display() const override
    {
        Console::display();
        cout << " | HDD: " << hddSizeGB << " GB" << endl;
    }
};
