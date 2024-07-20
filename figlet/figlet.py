from pyfiglet import Figlet
import sys
from random import choice

figlet = Figlet()
if len(sys.argv) != 3 and len(sys.argv) != 1:
    print("Invalid usage")
    sys.exit(1)
elif len(sys.argv) == 1:
    font = choice(figlet.getFonts())
    figlet.setFont(font= f"{font}")
    Input = input("Input: ")
    print("Output: ")
    print(figlet.renderText(f"{Input}"))
else:
    if sys.argv[1] != "-f" and sys.argv[1] != "-font":
        print("Invalid usage")
        sys.exit(1)
    elif sys.argv[2] in figlet.getFonts():
        figlet.setFont(font= f"{sys.argv[2]}")
        Input = input("Input: ")
        print("Output: ")
        print(figlet.renderText(f"{Input}"))
    else:
        print("Invalid usage")
        sys.exit(1)
