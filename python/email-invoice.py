class Invoicer:
    def __init__(self, send_schedule):
        self.send_schedule = send_schedule

    def send_emails(self, invoices, payments = None, changes = None):
        if changes:
            email_info = self.generate_email_info(invoices, payments, changes)
        else:
            email_info = self.generate_email_info1(invoices, payments)
            if payments:
                email_info = self.apply_payments(email_info, payments)

        email_info.sort(key=lambda x: x[0]) # Sort by time
        for info in email_info:
            time, email_type, name, amount, plan = info
            if amount > 0:
                print(f"{time}: [{email_type}] Invoice for {name} for {amount} dollars ({plan})")

        delinquent = self.get_delinquent(email_info)
        for message in delinquent:
            print(message)

    def generate_email_info(self, invoices, payments = None, changes = None):
        # Generate the email invoice
        emails = []

        changes_by_customer = {}
        for change in changes:
            if change["name"] not in changes_by_customer:
                changes_by_customer[change["name"]] = []
            changes_by_customer[change["name"]].append(change)

        for name in changes_by_customer.keys():
            changes_by_customer[name].sort(key=lambda x: x["change_date"])

        for invoice in invoices:
            name = invoice["name"]
            original_plan = invoice.get('plan', '')

            cur_changes = changes_by_customer.get(name, [])
            for offset, email_type in self.send_schedule.items():
                time = invoice["invoice_time"] + offset
                cur_plan = original_plan
                for change in cur_changes:
                    if int(change["change_date"]) < time:
                        cur_plan = change["plan"]
                    else:
                        break
                emails.append((time, email_type, name, invoice['amount'], cur_plan))

        return emails

    def generate_email_info1(self, invoices, payments = None, changes = None):
        emails = []
        for invoice in invoices:
            name = invoice["name"]
            original_plan = invoice.get('plan', '')
            for offset, email_type in self.send_schedule.items():
                emails.append((invoice["invoice_time"] + offset, email_type, invoice['name'], invoice['amount']))
        return emails


    def apply_payments(self, email_info, payments):
        adjusted_info = []

        # sort by name then time
        payments.sort(key=lambda x: (x["name"], x["payment_time"]))
        payments_by_customer = {}
        for payment in payments:
            if payment["name"] not in payments_by_customer:
                payments_by_customer[payment["name"]] = []
            payments_by_customer[payment["name"]].append(payment)

        payment_indices = {name: 0 for name in payments_by_customer.keys()}

        balances = {}
        for info in email_info:
            time, email_type, name, amount, _ = info
            if name not in balances:
                balances[name] = amount

            cur_balance = balances[name]
            cur_payments = payments_by_customer.get(name, [])
            while payment_indices.get(name, 0) < len(cur_payments):
                payment = payments[payment_indices[name]]
                if payment["payment_time"] < time:
                    cur_balance -= payment["amount"]
                    payment_indices[name] += 1
                else:
                    break
            balances[name] = cur_balance
            adjusted_info.append((time, email_type, name, cur_balance))
        return adjusted_info

    def get_delinquent(self, email_info):
        delinquent = {}
        for info in email_info:
            time, email_type, name, amount, plan = info
            delinquent[name] = amount
            if amount <= 0:
                delinquent.pop(name)
        return [f"{name} owes {amount}" for name, amount in delinquent.items()]
# part 1
send_schedule = {
    -10: "Upcoming",
    0: "New",
    20: "Reminder",
    30: "Due"
}

customer_invoices = [
    {"invoice_time": 0, "name": "Alice", "amount": 200},
    {"invoice_time": 1, "name": "Bob", "amount": 100}
]

invoicer = Invoicer(send_schedule)
# invoicer.send_emails(customer_invoices)

# part 2
customer_invoices = [
    {"invoice_time": 0, "name": "Alice", "amount": 200},
    {"invoice_time": 1, "name": "Bob", "amount": 100}
]

customer_payments = [
    {"payment_time": -9, "name": "Alice", "amount": 100},
    {"payment_time": 1, "name": "Bob", "amount": 50},
    {"payment_time": 0, "name": "Alice", "amount": 50}
]

# invoicer.send_emails(customer_invoices, customer_payments)

customer_invoices = [
    {"invoice_time": 0, "name": "Alice", "amount": 200, "plan": "Gold"},
    {"invoice_time": 1, "name": "Bob", "amount": 100}
]

# Payments
customer_payments = [
    {"payment_time": -9, "name": "Alice", "amount": 100},
    {"payment_time": 1, "name": "Bob", "amount": 50},
    {"payment_time": 0, "name": "Alice", "amount": 50}
]

# Multiple subscription changes
subscription_changes = [
    {"change_date": "1", "name": "Alice", "plan": "Platinum"},
    {"change_date": "20", "name": "Alice", "plan": "Diamond"}
]
invoicer.send_emails(customer_invoices, customer_payments, subscription_changes)
