price = 50
change = 0
amount = 0

while True:
    print(f"Amount Due: {price}")
    change = int(input("Insert Coin: "))
    if change in [25, 10, 5]:
        amount += change
        price -= change
        if amount >= 50:
            print(f"Change Owed: {amount - 50}")
            break
    else:
        continue
