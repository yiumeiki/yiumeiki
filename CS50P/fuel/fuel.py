while True:
    try:
        fraction = input("Fraction: ").split("/")
        if len(fraction) != 2:
            raise ValueError
        if fraction[1] != 0:
            number = int(fraction[0])/int(fraction[1]) * 100
            if number >= 99 and number <= 100:
                print("F")
            elif number <= 1:
                print("E")
            elif number > 100:
                raise ValueError
            else:
                print(f"{number:.0f}%")
            break
        else:
            if fraction[0] == 0:
                raise ZeroDivisionError

    except (ValueError, ZeroDivisionError):
        fraction = input("Fraction: ").split("/")
