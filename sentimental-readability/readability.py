text = input('Text: ')
L = 0  # Number of Letters
S = 0  # Number of sentences
W = 0  # Number of words
for i in text:
    if i.lower() >= 'a' and i.lower() <= 'z':
        L += 1
    elif i == '.' or i == '!' or i == '?':
        S += 1
    elif i == ' ':
        W += 1
W += 1
L = L / W * 100
S = S / W * 100

index = 0.0588 * L - 0.296 * S - 15.8
if index >= 16:
    print('Grade 16+')
elif index < 1:
    print('Before Grade 1')
else:
    print(f'Grade {round(index)}')
