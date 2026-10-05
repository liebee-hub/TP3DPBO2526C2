from console import Console


class PS4(Console):
    def __init__(self, console_id, name, hourly_rate, controller_count):
        super().__init__(console_id, name, hourly_rate)
        self._controller_count = controller_count

    def get_console_type(self):
        return "PS4"

    def display(self):
        return f"{super().display()} | Stik: {self._controller_count}"
