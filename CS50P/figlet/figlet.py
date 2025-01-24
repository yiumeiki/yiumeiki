import sys
import random
from pyfiglet import Figlet

figlet = Figlet()
type = figlet.getFonts()

if len(sys.argv) != 1 and len(sys.argv) != 3:
    sys.exit("Invalid usage")


if len(sys.argv) == 1:
    str = input("Input: ")
    num = random.randint(0, len(type))
    figlet.setFont(font=type[num])

elif len(sys.argv) == 3:
    if sys.argv[1] != "-f" and sys.argv[1] != "--font" or sys.argv[2] not in type:
        sys.exit("Invalid usage")
    str = input("Input: ")
    figlet.setFont(font=sys.argv[2])

print(figlet.renderText(str))
