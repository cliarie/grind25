"""
Part 1 prompt: Stripe in Brazil is obliged to register customer's transactions for each merchant with the central bank as an aggregated unit per day.
These are called receivables. A receivable is identified by 3 identifiers:
* merchant_id (String): The id of the merchant on Stripe side.
* card_type (String): The type of the card used for the transaction (e.g. Visa)
* payout_date (String): String date of the funds available to the merchant by Stripe.

A payment transaction in Stripe API can be represented as the following object:
```
Transaction {
    string customer_id
    string merchant_id
    string payout_date
    string card_type
    int amount
}
```

Implement register_receivables function that takes a string in CSV format
where each line represents a transaction and returns the registered aggregated receivables using the rules above.
Print the returned receivables to console using the format below.
Feel free to parse the CSV using a standard or a 3rd party library or implement it yourself.

You can assume the following about the input:
* The first line of the input is a header. The header is always the same so it can be ignored or hardcoded
* You can assume that the input has
already been read from a file and checked for correctness
* No data fields in this file will include commas or whitespace surrounding the field values.

You can also assume the following about the output:
* The first line of the output is the header. The header is always the same so it can be hardcoded
* Order of the output does not matter

Example input 1:
```
customer_id,merchant_id,payout_date,card_type,amount
cust1,merchantA,2021-12-30,Visa,150
cust2,merchantA,2021-12-30,Visa,200
cust3,merchantB,2021-12-31,MasterCard,300
cust4,merchantA,2021-12-30,Visa,50
```

Output 1:
```
merchant_id,card_type,payout_date,amount
merchantA,Visa,2021-12-30,400
merchantB,MasterCard,2021-12-31,300
```


Example input 2:
```
customer_id,merchant_id,payout_date,card_type,amount
cust1,merchantA,2021-12-29,MasterCard,50
cust2,merchantA,2021-12-29,Visa,150
cust3,merchantB,2021-12-31,Visa,300
cust4,merchantB,2021-12-29,MasterCard,200
```

Output 2
```
merchant_id,card_type,payout_date,amount
merchantA,MasterCard,2021-12-29,50
merchantA,Visa,2021-12-29,150
merchantB,Visa,2021-12-31,300
merchantB,MasterCard,2021-12-29,200
```
"""
# Enter your code here. Read input from STDIN. Print output to STDOUT

def parse(input):
    entries= input.splitlines()
    customers = []
    merchants = []
    payouts = []
    cards = []
    amounts = []
    for entry in entries:
        [customer, merchant, payout, card, amount] = entry.split(',')
        if customer == "customer_id" or customer == "contract_id":
            continue
        customers.append(customer)
        merchants.append(merchant)
        payouts.append(payout)
        cards.append(card)
        amt = int(amount)
        amounts.append(amt)

    return [customers, merchants, payouts, cards, amounts]

def register_receivables(customers_ids, merchant_ids, payout_dates, card_types, amount_v):

    history = {}
    mcmap = {}
    for i in range(len(customers_ids)):
        cur_mer = merchant_ids[i]
        key = cur_mer + "," + card_types[i] + ',' + payout_dates[i]
        if key not in mcmap:
            mcmap[key] = amount_v[i]
        else:
            cur_amt = mcmap[key]
            new_amt = cur_amt + amount_v[i]
            mcmap[key] = new_amt

    # for [key, value] in mcmap.items():
    #     print(key + "," + str(value))

    return mcmap

def update_receivables(register, newinput):
    [customers, merchants, payouts, cards, amounts] = parse(register)
    constmap = register_receivables(customers, merchants, payouts, cards, amounts)
    map = dict(constmap)
    [contract_ids, merchant_ids, payout_dates, card_types, amounts] = parse(newinput)

    for i in range(len(contract_ids)):
        cur_mer = merchant_ids[i]
        key = cur_mer + "," + card_types[i] + ',' + payout_dates[i]
        if key in map:
            # remove key and add new with contract instead of cust
            newkey = contract_ids[i] + "," + card_types[i] + ',' + payout_dates[i]
            map[newkey] = map.pop(key)
        else:
            continue

    for [key, value] in map.items():
        print(key + "," + str(value))


input1 = """customer_id,merchant_id,payout_date,card_type,amount
cust1,merchantA,2022-01-05,Visa,300
cust2,merchantA,2022-01-05,Visa,200
cust3,merchantB,2022-01-06,MasterCard,1000
"""
contracts2 = """contract_id,merchant_id,payout_date,card_type,amount
contract1,merchantA,2022-01-05,Visa,500"""
update_receivables(input1, contracts2)
