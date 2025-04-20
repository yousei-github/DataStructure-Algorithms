# 2_AverageNumber.py
"""Average program with sequence-controlled repetition."""

# Initialization phase
total = 0  # Sum
counter = 0
numbers = []  # List of numbers

# Processing phase
INPUT_NUMBERS = input("Enter numbers with ',' as the separator: ")

for item in INPUT_NUMBERS.split(","):
    if (item != None) and (item != '') and (item != ' '):
        numbers.append(float(item))

for number in numbers:
    total += number  # Add current number to the running total
    counter += 1  # Indicate that one more number was processed

# Termination phase
AVERAGE = total / counter
print(f'Average number is {AVERAGE}')  # Formatted string (f-string)

# Finish
print('Finish')
