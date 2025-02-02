# minimize number of transfers required to settle debts between banks at the end of the day
# input: list of transfers between banks (bank names and amounts)
# output: list of transfers to settle debts between banks
# 1. find net balance of each bank on transfers

input = ["AB 1", "BA 2"]

def settle_debts(transfer):
    central_bank = 0 # ascii for A

    send_amt = [0] * 26
    receive_amt = [0] * 26
    net_balance = [0] * 26

    for t in transfer:
        send = ord(t[0]) - ord('A')
        receive = ord(t[1]) - ord('A')
        amount = int(t[3:])

        send_amt[send] += amount
        receive_amt[receive] += amount
        net_balance[send] += amount
        net_balance[receive] -= amount

    final_transfers = []
    for i in range(26):
        if i == central_bank:
            continue
        net_balance = receive_amt[i] - send_amt[i]

        if net_balance > 0:
            final_transfers.append(f"{chr(central_bank + ord('A'))} {chr(i + ord('A'))} {net_balance}")
        elif net_balance < 0:
            final_transfers.append(f"{chr(i + ord('A'))} {chr(central_bank + ord('A'))} {-net_balance}")

    return final_transfers
