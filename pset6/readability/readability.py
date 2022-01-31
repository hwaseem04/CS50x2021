# Importing get_string function from cs50 library
from cs50 import get_string

# Getting Text input
text = get_string('Text: ')

# Initializing variables for 'Letters per 100 words' and 'Sentences per 100 words'
L = 0
S = 0

# Setting counter variables for calculating letters and sentences
letters = 0
sentences = 0

# Calculating the number of words
words = len(text.split())

# Calculating number of letters and sentences
for i in text:
    if i.isalpha():
        letters += 1
    elif i in ['!', '.', '?']:
        sentences += 1
# Calculating value for L and S
L = (letters/words)*100
S = (sentences/words)*100
# Calculating value of index
index = 0.0588 * L - 0.296 * S - 15.8

# Printing the result
if index < 1:
    print("Before Grade 1")
elif index >= 16:
    print("Grade 16+")
else:
    print('Grade', round(index))