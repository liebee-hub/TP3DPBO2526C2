from console import Console


class PS3(Console):
    def __init__(self, console_id, name, hourly_rate, hdd_size_gb):
        super().__init__(console_id, name, hourly_rate)
        self._hdd_size_gb = hdd_size_gb

    def get_console_type(self):
        return "PS3"

    def display(self):
        return f"{super().display()} | HDD: {self._hdd_size_gb} GB"
