from abc import ABC, abstractmethod

class PaymentCard():
    def __init__(self, card_number: str, balance: float):
        self.card_number = card_number
        self.balance = balance

    # TODO: Implement the process_payment method
    @abstractmethod
    def process_payment(self, amount: int) ->str:
        pass
    

# TODO: Implement the DebitCard class
class DebitCard(PaymentCard):
    def __init__(self, card_number: str, balance: float):
        super().__init__(card_number, balance)

    def process_payment(self, amount: int) -> str:
        if self.balance < amount:
            return "Insufficient funds"
        else: 
            return "Payment successful"
            self.balance = self.balance - amount

# TODO: Implement the CreditCard class
class CreditCard(PaymentCard):
    def process_payment(self, amount: int) -> str:
        return "Payment successful"
        self.balance -= amount

# Don't modify the code below
debit_card = DebitCard("1234", 100.0)  # Card with $100 balance
credit_card = CreditCard("5678", 100.0) # Card with $100 balance

# Test debit card
print(debit_card.process_payment(50.0))  
print(debit_card.balance)                
print(debit_card.process_payment(100.0))  
print(debit_card.balance)    

# Test credit card
print(credit_card.process_payment(50.0))   
print(credit_card.balance)                
print(credit_card.process_payment(100.0))  
print(credit_card.balance)    