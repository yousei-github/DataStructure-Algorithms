# 3_CompoundInterest.py
"""Compound-Interest calculation."""

# For monetary calculations and other applications that require precise representation and manipulation of numbers with decimal points,
# the Python Standard Library provides type Decimal, which uses a special coding scheme to solve the problem of to-the-penny precision.
# That scheme requires additional memory to hold the numbers and additional processing time to perform calculations,
# but provides the to-the-penny precision required for monetary calculations.
# Banks also have to deal with other issues such as using a fair rounding algorithm when they're calculating daily interest on accounts.
# Type Decimal offers such capabilities.
import decimal  # from decimal import Decimal

# Initialization phase

principal = '0'  # Original amount invested
rate = '5.0'  # Annual interest rate [%]
numberOfYears = 1  # Number of years
deposit = '0'  # Amount on deposit at the end of the nth year
extraPrincipal = '0'  # Extra amount invested for the rest of each year

# Processing phase
principal = input('Enter the original amount invested: ')
inputRate = input('(Optional) Enter the annual interest rate [%]: ')
numberOfYears = input('Enter the number of years: ')
InputExtraPrincipal = input('(Optional) Enter the extra amount invested for the rest of each year: ')


def isInvalidInput(argument):
    """
    This function checks whether the argument is invalid input (None, invalid string, space)
    """

    if (argument == None) or (argument == '') or (argument == ' '):
        return True
    else:
        return False


if isInvalidInput(inputRate):
    inputRate = rate
if isInvalidInput(InputExtraPrincipal):
    InputExtraPrincipal = extraPrincipal

print(f'\nInput Parameters\n\
      Original Amount Invested: {principal:>10}\n\
      Annual Interest Rate: {inputRate:>10} %\n\
      Number Of Years: {numberOfYears:>10}\n\
      Extra Amount Invested For The Rest Of Each Year: {InputExtraPrincipal:>10}')

principal = decimal.Decimal(principal)
rate = decimal.Decimal(inputRate) / decimal.Decimal('100')
numberOfYears = int(numberOfYears)
extraPrincipal = decimal.Decimal(InputExtraPrincipal)

print(f'Calculating:')

deposit = principal
for year in range(1, numberOfYears + 1):
    deposit = deposit * (1 + rate) ** year
    print(f'Year: {year:>2}, amount: {deposit:>10.2f}')

    if 1 < year:
        deposit += extraPrincipal

# Finish
print('Finish')
