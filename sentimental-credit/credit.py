from sys import exit


def First_Sum(Credit):
    Sum1 = 0
    for x in range(len(Credit) - 2, -1, -2):
        if int(Credit[x]) * 2 > 9:
            Sum1 += int(Credit[x]) * 2 % 10 + int(int(Credit[x]) * 2 / 10)
        else:
            Sum1 += int(Credit[x]) * 2
    return Sum1


def Second_Sum(Credit):
    Sum2 = 0
    for x in range(len(Credit) - 1, -1, -2):
        Sum2 += int(Credit[x])
    return Sum2


# Main
while True:
    try:
        a = input('Number: ')
        break
    except ValueError:
        continue
Sum = First_Sum(a) + Second_Sum(a)
if Sum % 10 != 0:
    print('INVALID')
    exit(1)
# Check Visa
if len(a) == 13 or len(a) == 16:
    if a[0] == '4':
        print('VISA')
        exit(0)
# Check AMEX
if len(a) == 15:
    if a[:2] == '34' or a[:2] == '37':
        print('AMEX')
        exit(0)
# Check MASTERCARD
if len(a) == 16:
    if a[:2] in {'51', '52', '53', '54', '55'}:
        print('MASTERCARD')
        exit(0)
print('INVALID')
