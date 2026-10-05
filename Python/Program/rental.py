from rental_period import RentalPeriod
from utils import format_rupiah


class Rental:
    def __init__(self, rental_id, customer, console, start_hour, hours):
        self._rental_id = rental_id
        self._customer = customer  # AGGREGATION: hanya referensi
        self._console = console    # AGGREGATION: hanya referensi
        # COMPOSITION: RentalPeriod dibuat di dalam Rental
        self._period = RentalPeriod(start_hour, hours)
        self._total_cost = self.calculate_total()

    # biaya konsol (polimorfik) dikurangi diskon pelanggan
    def calculate_total(self):
        base = self._console.calculate_cost(self._period.get_duration_hours())
        return round(base * (1 - self._customer.get_discount_rate()))

    def finish(self):
        self._console.set_available(True)

    def display(self):
        return (f"{self._rental_id} | {self._customer.get_name()} | "
                f"{self._console.get_id()} ({self._console.get_console_type()}) | "
                f"{self._period.display()} | Total: {format_rupiah(self._total_cost)}")
