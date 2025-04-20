# 3_Calculator_TwoOperands.py

print("""Wellcome! This is the calculator with two operands\n""")

value1 = float(input('Enter first number: '))

operator = input('Enter the operator: ')

value2 = float(input('Enter second number: '))

if operator == '+':
    print('The result is:', value1 + value2)
elif operator == '-':
    print('The result is:', value1 - value2)
elif operator == '*':
    print('The result is:', value1 * value2)
elif operator == '/':
    print('The result is:', value1 / value2)
elif operator == '%':
    print('The result is:', value1 % value2)
elif ((operator == 'min') or (operator == 'Min')):
    print('The minimum is:', min(value1, value2))
elif ((operator == 'max') or (operator == 'Max')):
    print('The minimum is:', max(value1, value2))
else:
    print('Unknown operator:', operator)

# Finish
print('Finish')
