from utils import format_hour


class RentalPeriod:
    def __init__(self, start_hour, duration_hours):
        self._start_hour = start_hour
        self._duration_hours = duration_hours

    def get_end_hour(self):
        return self._start_hour + self._duration_hours

    def get_duration_hours(self):
        return self._duration_hours

    def display(self):
        return (f"{format_hour(self._start_hour)} - {format_hour(self.get_end_hour())} "
                f"({self._duration_hours} jam)")
