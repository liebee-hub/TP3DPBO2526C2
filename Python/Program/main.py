from ps3 import PS3
from ps4 import PS4
from ps5 import PS5
from customer import Customer
from rental_shop import RentalShop


def main():
    shop = RentalShop("PS Rental DPBO")

    # ===== Data awal =====
    # Console & Customer dibuat di luar shop (AGGREGATION)
    ps3a = PS3("PS3-01", "PlayStation 3 Slim", 4000, 250)
    ps4a = PS4("PS4-01", "PlayStation 4 Pro", 6000, 2)
    ps5a = PS5("PS5-01", "PlayStation 5 + VR", 10000, True)
    c1 = Customer("C001", "Budi", "081234567890", True)
    c2 = Customer("C002", "Sari", "081298765432", False)

    shop.add_console(ps3a)
    shop.add_console(ps4a)
    shop.add_console(ps5a)
    shop.add_customer(c1)
    shop.add_customer(c2)

    print("--- Membuat transaksi awal ---")
    shop.rent_console("C001", "PS4-01", 14, 3)
    shop.rent_console("C002", "PS5-01", 10, 2)

    print("\n>>> SEBELUM penambahan data\n")
    shop.print_all()

    print("\n=======================================\n")

    # ===== Penambahan data =====
    ps5b = PS5("PS5-02", "PlayStation 5 Digital", 10000, False)
    c3 = Customer("C003", "Dimas", "081355577799", True)

    shop.add_console(ps5b)
    shop.add_customer(c3)

    print("--- Menambah transaksi baru ---")
    shop.rent_console("C003", "PS5-02", 16, 4)
    shop.rent_console("C002", "PS4-01", 18, 1)  # PS4-01 sedang disewa -> ditolak

    print("\n>>> SESUDAH penambahan data\n")
    shop.print_all()


if __name__ == "__main__":
    main()
