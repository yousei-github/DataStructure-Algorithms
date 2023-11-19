# ExponentTable.py
"""Exponent or power Table."""

maximumExponrnt = 10

print('\nExponent or power Table.')

print("""A power is defined as:
    Power = Base^Exponent\n""")

print('| Base | Exponent ', end='(')
for exponent in range(maximumExponrnt):
    if exponent != (maximumExponrnt - 1):
        print(exponent + 1, end=', ')
    else:
        print(exponent + 1, end=')\n')

maximumBase = 10

for base in range(maximumBase):
    print('| ', base + 1, '  |', end=' ')

    for exponent in range(maximumExponrnt):
        if exponent != (maximumExponrnt - 1):
            print((base + 1)**(exponent + 1), end=', ')
        else:
            print((base + 1)**(exponent + 1), end='\n')
