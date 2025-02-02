# identify companies with recurring transactions
# at least 3 transactions for the same company
# transactions must have the same amount and consistent number of days apart (20% tolerance)
# input: list of transactions with company names, amounts, timestamps
# output list of companies with recurring transactions
from collections import defaultdict

class Transaction:
    def __init__(self, company, amount, timestamp):
        self.company = company
        self.amount = amount
        self.timestamp = timestamp

def get_companies(transactions):
    transactions_map = defaultdict(list)
    for t in transactions:
        transactions_map[t.company].append(t)

    companies = []
    for company, transactions in transactions_map.items():
        if len(transactions) < 3:
            continue
        if has_recurring_transactions(transactions):
            companies.append(company)

    return companies

def get_min_days(transactions):
    prev_timestamp = transactions[0].timestamp
    min_diff = float("inf")
    for t in transactions[1:]:
        interval = t.timestamp - prev_timestamp
        min_diff = min(min_diff, interval)
        prev_timestamp = t.timestamp
    return min_diff

# transactions of the same company
def has_recurring_transactions(transactions):
    min_amount = min(t.amount for t in transactions)
    max_amount = min_amount * 1.2

    min_days = get_min_days(transactions)
    max_days = int(min_days) * 1.2

    prev_timestamp = transactions[0].timestamp

    for t in transactions[1:]:
        if t.amount < min_amount or t.amount > max_amount:
            return False
        interval = t.timestamp - prev_timestamp
        if interval < min_days or interval > max_days:
            return False
        prev_timestamp = t.timestamp

    return True

transactions = [
    Transaction("Netflix", 9.99, 10),
    Transaction("Netflix", 9.99, 20),
    Transaction("Netflix", 9.99, 30),
    Transaction("Amazon", 27.12, 32),
    Transaction("Sprint", 50.11, 45),
    Transaction("Sprint", 50.11, 55),
    Transaction("Sprint", 50.11, 65),
    Transaction("Sprint", 60.13, 77)
]

print(get_companies(transactions))  # ['Netflix', 'Sprint']
