from console import Console


class PS5(Console):
    VR_SURCHARGE = 3000  # biaya tambahan VR per jam

    def __init__(self, console_id, name, hourly_rate, supports_vr):
        super().__init__(console_id, name, hourly_rate)
        self._supports_vr = supports_vr

    def get_console_type(self):
        return "PS5"

    # OVERRIDE: unit dengan VR dikenakan biaya tambahan per jam (polimorfisme)
    def calculate_cost(self, hours):
        rate = self._hourly_rate + (self.VR_SURCHARGE if self._supports_vr else 0)
        return rate * hours

    def display(self):
        vr = "Ya" if self._supports_vr else "Tidak"
        return f"{super().display()} | VR: {vr}"
