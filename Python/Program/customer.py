class Customer:
    def __init__(self, customer_id, name, phone, is_member):
        self._customer_id = customer_id
        self._name = name
        self._phone = phone
        self._is_member = is_member

    # member mendapat diskon 10%
    def get_discount_rate(self):
        return 0.10 if self._is_member else 0.0

    def get_id(self):
        return self._customer_id

    def get_name(self):
        return self._name

    def display(self):
        status = "Member (diskon 10%)" if self._is_member else "Non-member"
        return f"{self._customer_id} | {self._name} | {self._phone} | {status}"
