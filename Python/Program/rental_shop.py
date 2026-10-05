from rental import Rental


class RentalShop:
    def __init__(self, shop_name):
        self._shop_name = shop_name
        self._consoles = []    # ARRAY OF OBJECT (polimorfik), AGGREGATION
        self._customers = []   # ARRAY OF OBJECT, AGGREGATION
        self._rentals = []     # ARRAY OF OBJECT, COMPOSITION (dibuat di rent_console)
        self._rental_counter = 0

    def add_console(self, console):
        self._consoles.append(console)

    def add_customer(self, customer):
        self._customers.append(customer)

    def _find_customer(self, customer_id):
        return next((c for c in self._customers if c.get_id() == customer_id), None)

    def _find_console(self, console_id):
        return next((c for c in self._consoles if c.get_id() == console_id), None)

    def rent_console(self, customer_id, console_id, start_hour, hours):
        cust = self._find_customer(customer_id)
        con = self._find_console(console_id)

        if cust is None or con is None:
            print("[GAGAL] Pelanggan atau konsol tidak ditemukan.")
            return False
        if not con.is_available():
            print(f"[GAGAL] {con.get_id()} sedang disewa, "
                  f"{cust.get_name()} tidak bisa menyewa saat ini.")
            return False

        self._rental_counter += 1
        rental_id = f"R{self._rental_counter:03d}"

        self._rentals.append(Rental(rental_id, cust, con, start_hour, hours))
        con.set_available(False)

        print(f"[OK] {rental_id}: {cust.get_name()} menyewa {con.get_id()}")
        return True

    def print_all(self):
        print(f"=== {self._shop_name} ===")

        print(f"\n-- Daftar Konsol ({len(self._consoles)}) --")
        for i, c in enumerate(self._consoles, start=1):
            print(f"{i}. {c.display()}")

        print(f"\n-- Daftar Pelanggan ({len(self._customers)}) --")
        for i, c in enumerate(self._customers, start=1):
            print(f"{i}. {c.display()}")

        print(f"\n-- Daftar Transaksi ({len(self._rentals)}) --")
        if not self._rentals:
            print("(belum ada transaksi)")
        for i, r in enumerate(self._rentals, start=1):
            print(f"{i}. {r.display()}")
