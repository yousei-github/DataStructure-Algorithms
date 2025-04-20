# 2_Calculator_OneOperand.py

print("""Wellcome! This is the calculator with one operand\n""")

# The built-in input function requests and obtains user input
value1 = input('Enter the number: ')

operator = input('Enter the operator: ')

if ((operator == 'even') or (operator == 'odd') or (operator == 'Even') or (operator == 'Odd')):
    if (float(value1) % 2) == 0:
        print('The result is: even number')
    else:
        print('The result is: odd number')
elif ((operator == 'value') or (operator == 'Value')):
    print('The result is:', ord(value1))
elif ((operator == 'square root') or (operator == 'Square root')):
    print('The result is:', float(value1) ** (0.5))
else:
    print('Unknown operator:', operator)

# Finish
print('Finish')
