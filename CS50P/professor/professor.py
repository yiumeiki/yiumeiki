import random
import sys

def main():
    level = get_level()
    score = 0

    while True:
        try:
            for _ in range(10):
                a = generate_integer(level)
                b = generate_integer(level)
                ans = str(a + b)

                for _ in range(3):
                    guess = input(f"{a} + {b} = ")
                    if guess.isdigit() is False or guess != ans:
                        print("EEE")
                    else:
                        score += 1
                        break

                if guess != ans:
                    print(f"{a} + {b} = {ans}")

            print(f"Score: {score}")
            break

        except ValueError:
            pass

def get_level():
    level = input("Level: ")
    while level.isdigit() is False or level != "1" and level != "2" and level != "3":
        level = input("Level: ")
    return int(level)

def generate_integer(level):
    if level == 1:
        return random.randint(0, 9)
    elif level == 2:
        return random.randint(10, 99)
    else:
        return random.randint(100, 999)

if __name__ == "__main__":
    main()
