name = input("Input: ")

for char in name:
    if char not in ["A", "E", "I", "O", "U", "a", "e", "i", "o", "u"]:
        print(char, end="")

print()
