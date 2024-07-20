while True:
    try:
        cash = float(input('Change owed: '))
        if cash > 0:
            break
    except ValueError:
        continue

cash = int((cash * 100))
count = int(cash / 25)
cash = cash % 25 
count += int(cash / 10)
cash = cash % 10
count += int(cash / 5)
cash = cash % 5
count += cash
print(count)
