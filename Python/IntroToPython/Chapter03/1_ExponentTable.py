# 1_ExponentTable.py
"""Exponent or power Table."""

maximumExponrnt = 10

print('\nExponent or power Table.')

print("""A power is defined as: Power = Base^Exponent\n""")

print('| Base | Exponent ', end='(')  # Use "end" to display character's value followed by '('

# The function call range(Number) creates an iterable object that represents a sequence of consecutive integer values starting from 0 and continuing up to, but not including, the argument value (Number).
for exponent in range(maximumExponrnt):
    if exponent != (maximumExponrnt - 1):
        print(exponent + 1, end=', ')
    else:
        print(exponent + 1, end=')\n')

maximumBase = 10

for base in range(maximumBase):
    print('|', base + 1, '|', sep=' ', end=' ')  # Use "sep" to specify the string that appears between the items that print displays

    for exponent in range(maximumExponrnt):
        if exponent != (maximumExponrnt - 1):
            print((base + 1)**(exponent + 1), end=', ')
        else:
            print((base + 1)**(exponent + 1), end='\n')

# Finish
print('Finish')
