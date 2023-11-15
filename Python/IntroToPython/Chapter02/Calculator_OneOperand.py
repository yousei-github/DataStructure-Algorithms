# Calculator_OneOperand.py

print("""Wellcome!
This is the calculator with one operand\n""")

value1 = input('Enter the number: ')

operator = input('Enter the operator: ')

if ((operator == 'even') or (operator == 'odd') or (operator == 'Even') or (operator == 'Odd')):
    if (float(value1) % 2) == 0:
        print('The result is: even number')
    else:
        print('The result is: odd number')
elif ((operator == 'value') or (operator == 'Value')):
    print('The result is:', ord(value1))
else:
    print('Unknown operator:', operator)
