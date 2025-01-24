import sys
import csv
from PIL import Image, ImageOps

if len(sys.argv) < 3:
    sys.exit("Too few command-line arguments")
elif len(sys.argv) > 3:
    sys.exit("Too many command-line arguments")
elif sys.argv[1][-3:] != sys.argv[2][-3:]:
    sys.exit("Input and output have different extensions")
elif sys.argv[1][-3:].lower() not in ["jpg", "peg", "png"] or sys.argv[2][-3:].lower() not in ["jpg", "peg", "png"]:
    sys.exit("Invalid output")

try:

    shirt = Image.open("shirt.png")
    before = Image.open(sys.argv[1])

except FileNotFoundError:
    sys.exit("Input does not exist")

else:
    size = shirt.size
    before = ImageOps.fit(before, size)
    before.paste(shirt, box = (0, 0), mask = shirt)
    before.save(sys.argv[2], format=None)
