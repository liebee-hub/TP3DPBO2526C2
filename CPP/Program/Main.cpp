#include <iostream>
#include "PS3.cpp"
#include "PS4.cpp"
#include "PS5.cpp"
#include "Customer.cpp"
#include "RentalShop.cpp"

using namespace std;

int main()
{
    RentalShop shop("PS Rental DPBO");

    // ===== Data awal =====
    // Console & Customer dibuat di luar shop (AGGREGATION)
    PS3 ps3a("PS3-01", "PlayStation 3 Slim", 4000, 250);
    PS4 ps4a("PS4-01", "PlayStation 4 Pro", 6000, 2);
    PS5 ps5a("PS5-01", "PlayStation 5 + VR", 10000, true);
    Customer c1("C001", "Budi", "081234567890", true);
    Customer c2("C002", "Sari", "081298765432", false);

    shop.addConsole(&ps3a);
    shop.addConsole(&ps4a);
    shop.addConsole(&ps5a);
    shop.addCustomer(&c1);
    shop.addCustomer(&c2);

    cout << "--- Membuat transaksi awal ---" << endl;
    shop.rentConsole("C001", "PS4-01", 14, 3);
    shop.rentConsole("C002", "PS5-01", 10, 2);

    cout << "\n>>> SEBELUM penambahan data\n"
         << endl;
    shop.printAll();

    cout << "\n=======================================\n"
         << endl;

    // ===== Penambahan data =====
    PS5 ps5b("PS5-02", "PlayStation 5 Digital", 10000, false);
    Customer c3("C003", "Dimas", "081355577799", true);

    shop.addConsole(&ps5b);
    shop.addCustomer(&c3);

    cout << "--- Menambah transaksi baru ---" << endl;
    shop.rentConsole("C003", "PS5-02", 16, 4);
    shop.rentConsole("C002", "PS4-01", 18, 1); // PS4-01 sedang disewa -> ditolak

    cout << "\n>>> SESUDAH penambahan data\n"
         << endl;
    shop.printAll();

    return 0;
}
