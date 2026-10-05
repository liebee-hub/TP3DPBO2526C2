def format_rupiah(amount):
    """16200 -> 'Rp 16.200'"""
    return "Rp " + f"{amount:,}".replace(",", ".")


def format_hour(hour):
    """9 -> '09:00'"""
    return f"{hour % 24:02d}:00"
