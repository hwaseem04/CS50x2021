# Importing sys and csv module
import sys
import csv

# Function to count the repetitive occurance of STR in a sequence


def Str_count(s, Str):
    counts = 0
    while Str * (counts + 1) in s:
        counts += 1
    return counts    
    

# Check for correct entry of command-line Arguments
if len(sys.argv) != 3:
    print('Unvalid use of arguments')
    sys.exit(1)


# Opening the text file and storing the sequence
with open(sys.argv[2], 'r') as f:
    sequence = f.read()

header = []
data = []

# Opening the csv file and storing the header and data seperately
with open(sys.argv[1], 'r') as f:
    read = csv.reader(f)
    for i in read:
        data.append(i)
    header = data[0]
    data.pop(0)

# Counting all the STRs in the sequence
count = []
for i in range(len(header) - 1):
    STR = header[i + 1]
    Max = Str_count(sequence, STR)
    count.append(str(Max))

# Displaying the match
for row in data:
    if row[1:] == count:
        print(row[0])
        break
else:
    print('No match')
