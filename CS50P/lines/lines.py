import sys
lines = []
i = 0
j = 0

try:
    if len(sys.argv) > 2:
        print("Too many command-line arguments")
        sys.exit(1)

    elif len(sys.argv) < 2:
        print("Too few command-line arguments")
        sys.exit(1)

    else:
        if sys.argv[1][-3:] == ".py" :
            with open(sys.argv[1]) as file:
                lines = file.readlines()
            for line in lines:
                 line = line.lstrip()
                 if line and line[0] != "#":
                    i += 1
            print(i)

        else:
            print("Not a Python file")
            sys.exit(1)

except FileNotFoundError:
        print("File does not exist")
        sys.exit(1)

