def main():
    plate = input("Plate: ")
    if is_valid(plate):
        print("Valid")
    else:
        print("Invalid")


def is_valid(s):
    if 1 < len(s) < 7:
        if s[0].isalpha() and s[1].isalpha() and s.isalnum():
            found_number = False
            for i, char in enumerate(s):
                if char.isdigit():
                    if not found_number:
                        if char == '0':
                            return False
                        found_number = True
                    else:
                        if not s[i:].isdigit():
                            return False
            return True
        else:
            return False
    else:
        return False


main()
