import emoji
import re

name = input("Input: ")
result = re.split(r'(:\w+:)', name)
result = [part for part in result if part]

print(result)

for i in range(len(result)):
    if result[i][0] == ":":
        print(emoji.emojize(result[i], language='alias'), end="")
    else:
        print(result[i], end="")

print()
