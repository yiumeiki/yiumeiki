import sys
import csv

info = []

if len(sys.argv) < 3:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 3:
    sys.exit("Too many command-line arguments")

try:
    with open(sys.argv[1]) as file:
        reader = csv.DictReader(file)
        for row in reader:
            first = row["name"].split(", ")
            info.append({"first":first[1], "last":first[0], "house":row['house']})
    with open(sys.argv[2], "w") as file:
        writer = csv.DictWriter(file, fieldnames=["first", "last", "house"])
        writer.writeheader()
        for row in info:
            writer.writerow(row)

except FileNotFoundError:
    sys.exit(f"Could not read {sys.argv[1]}")
