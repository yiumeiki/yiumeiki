name = input("camelCase: ")

for char in name:
    if char.islower():
        print(char, end="")
    else:
        print(f"_{char.lower()}", end="")
print()
