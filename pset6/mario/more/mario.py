import sys

# Getting user input for height
n = input("Height: ")

# Prompting user to input values between 1 and 8(inclusive)
while True: 
    if n.isdigit():
        if (int(n) >= 1) and (int(n) <= 8):
            break
        else:
            n = input("Height: ")
    else:
        n = input("Height: ")
n = int(n)    
# Printing Triangles
for i in range(n):  
    # Printing spaces - left side
    for j in range(n - i - 1):
        print(' ', end='')
        
    # Printing hashes - left side
    for k in range(i + 1):
        print('#', end='')
    
    # Printing seperator between the triangles
    print('  ', end='')
    
    # Priniting Right side Triangle
    for L in range(i + 1):
        print('#', end='')
    print()    
        