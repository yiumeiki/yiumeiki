import sys
import csv
from tabulate import tabulate

menu = []

if len(sys.argv) < 2:
    print("Too few command-line arguments")
    sys.exit(1)
elif len(sys.argv) > 2:
    print("Too many command-line arguments")
    sys.exit(1)
elif sys.argv[1][-3:] != "csv":
    print("Not a CSV file")
    sys.exit(1)
    
try:
    with open(sys.argv[1]) as file:
        reader = csv.reader(file)
        for row in reader:
            menu.append(row)
    print(tabulate(menu[1:], menu[0], tablefmt="grid"))

except FileNotFoundError:
        print("File does not exist")
        sys.exit(1)
