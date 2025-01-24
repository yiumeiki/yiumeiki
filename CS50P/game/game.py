import random
import sys

while True:
    level = input("Level: ")
    while level.isdigit() is False or level == "0" or level == "1" :
        level = input("Level: ")
    answer = random.randint(1, int(level))

    guess = 0
    while guess != answer:
        guess = input("Guess: ")
        while guess.isdigit() is False:
            guess = input("Guess: ")
        guess = int(guess)

        if guess < answer:
            print("Too small!")
        else:
            print("Too large!")


    print("Just right!")
    sys.exit()
