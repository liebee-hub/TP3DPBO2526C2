#pragma once

#include <iostream>
#include <string>

using namespace std;

class Customer
{
private:
    string customerId;
    string name;
    string phone;
    bool isMember;

public:
    Customer(string customerId, string name, string phone, bool isMember)
        : customerId(customerId), name(name), phone(phone), isMember(isMember) {}

    // member mendapat diskon 10%
    double getDiscountRate() const { return isMember ? 0.10 : 0.0; }

    string getId() const { return customerId; }
    string getName() const { return name; }

    void display() const
    {
        cout << customerId << " | " << name << " | " << phone << " | "
             << (isMember ? "Member (diskon 10%)" : "Non-member") << endl;
    }
};
