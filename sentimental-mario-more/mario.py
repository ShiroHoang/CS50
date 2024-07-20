while True:
    try:
        n = int(input('Height: '))
        if n < 9 and n > 0:
            break
    except ValueError:
        continue
for i in range(n):
    print(' ' * (n - i - 1) + '#' * (i + 1) + '  ' + '#' * (i + 1))
