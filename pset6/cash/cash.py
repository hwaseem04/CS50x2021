# importing get_float from cs50 library
from cs50 import get_float

# Getting input and Prompting user to input valid entry
n = get_float("Cash owed: ")
while True:
    if n >= 0:
        break
    else:
        n = get_float("Cash owed: ")
# Declaring list containing possible coins
List = [0.25, 0.10, 0.05, 0.01]

# Setting up counter
count = 0
i = 0

# CAlculating minimum coins required
while n > 0:
    if n >= List[i]:
        count += 1
        n = round((n - List[i]) * 100)/100
    else:
        i += 1
print(count)