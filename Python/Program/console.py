from abc import ABC, abstractmethod
from utils import format_rupiah


class Console(ABC):
    """Parent class (abstract) untuk Hierarchical Inheritance."""

    def __init__(self, console_id, name, hourly_rate):
        self._console_id = console_id
        self._name = name
        self._hourly_rate = hourly_rate
        self._available = True

    # abstract: wajib di-override oleh child
    @abstractmethod
    def get_console_type(self):
        pass

    # bisa di-override child (contoh: PS5 menambah biaya VR)
    def calculate_cost(self, hours):
        return self._hourly_rate * hours

    def is_available(self):
        return self._available

    def set_available(self, status):
        self._available = status

    def get_id(self):
        return self._console_id

    def get_name(self):
        return self._name

    def display(self):
        status = "Tersedia" if self._available else "Disewa"
        return (f"[{self.get_console_type()}] {self._console_id} | {self._name} | "
                f"{format_rupiah(self._hourly_rate)}/jam | {status}")
