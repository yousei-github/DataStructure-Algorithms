# Calculator_AdditionWithTwoOperands.py

print("""Wellcome!
This is the addition calculator with two operands\n""")

value1 = input('Enter first number: ')

operator = input('Enter the operator: ')

value2 = input('Enter second number: ')

if operator == '+':
    print('The result is:', float(value1) + float(value2))
elif operator == '-':
    print('The result is:', float(value1) - float(value2))
elif operator == '*':
    print('The result is:', float(value1) * float(value2))
elif operator == '/':
    print('The result is:', float(value1) / float(value2))
elif operator == '%':
    print('The result is:', float(value1) % float(value2))
elif ((operator == 'min') or (operator == 'Min')):
    print('The minimum is:', min(float(value1), float(value2)))
elif ((operator == 'max') or (operator == 'Max')):
    print('The minimum is:', max(float(value1), float(value2)))
else:
    print('Unknown operator:', operator)
