import requests
import json
import sys

number = None

if len(sys.argv) != 2:
    print("Missing command-line argument")
    sys.exit(1)

try:
    number = float(sys.argv[1].strip())
except ValueError:
    print("Command-line argument is not a number")
    sys.exit(1)

try:
    response = requests.get("https://api.coindesk.com/v1/bpi/currentprice.json", "rate")
    data = response.json()
    rate = data["bpi"]["USD"]["rate_float"]
    print(f"${number * float(rate):,.4f}")
except requests.RequestException:
    sys.exit(1)
