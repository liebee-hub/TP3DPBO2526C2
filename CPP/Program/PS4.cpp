#pragma once

#include "Console.cpp"

class PS4 : public Console
{
private:
    int controllerCount;

public:
    PS4(string consoleId, string name, int hourlyRate, int controllerCount)
        : Console(consoleId, name, hourlyRate), controllerCount(controllerCount) {}

    string getConsoleType() const override { return "PS4"; }

    void display() const override
    {
        Console::display();
        cout << " | Stik: " << controllerCount << endl;
    }
};
