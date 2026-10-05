#pragma once

#include <iostream>
#include "Utils.cpp"

using namespace std;

class RentalPeriod
{
private:
    int startHour;
    int durationHours;

public:
    RentalPeriod(int startHour, int durationHours)
        : startHour(startHour), durationHours(durationHours) {}

    int getEndHour() const { return startHour + durationHours; }
    int getDurationHours() const { return durationHours; }

    void display() const
    {
        cout << formatHour(startHour) << " - " << formatHour(getEndHour())
             << " (" << durationHours << " jam)";
    }
};
