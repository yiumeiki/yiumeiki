result = input("Expression: ").split(" ")

x = int(result[0])
z = int(result[2])

match result[1]:
    case "+":
        print(f"{x + z:.1f}")
    case "-":
        print(f"{x - z:.1f}")
    case "*":
        print(f"{x * z:.1f}")
    case "/":
        print(f"{x / z:.1f}")
