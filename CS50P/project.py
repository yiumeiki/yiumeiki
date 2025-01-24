import random

class Player:

    def deal_card(self):
        cards = [11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10, 10]
        return random.choice(cards)

    def calculate_score(self, cards):
        if sum(cards) == 21 and len(cards) == 2:
            return 0
        if 11 in cards and sum(cards) > 21:
            cards.remove(11)
            cards.append(1)
        return sum(cards)

    def compare(self, user_score, computer_score):
        if user_score > 21 and computer_score > 21:
            return "Both bust... You lose..."
        if user_score == computer_score:
            return "Draw"
        elif computer_score == 0:
            return "Lose;( Comptuer got Blackjack"
        elif user_score == 0:
            return "Blackjack! You win!!"
        elif user_score > 21:
            return "You bust... You lose"
        elif computer_score > 21:
            return "Computer bust. You win!!"
        elif user_score > computer_score:
            return "You win!!"
        else:
            return "You lose;("

    def play_player_turn(self, user_cards, computer_cards):
        is_game_over = 0

        while is_game_over != 1:
            user_score = self.calculate_score(user_cards)
            computer_score = self.calculate_score(computer_cards)

            print(f"Your cards: {user_cards}, current score: {user_score}")
            print(f"Computer's first card: {computer_cards[0]}\n")

            if user_score == 0 or computer_score == 0 or user_score > 21:
                is_game_over = 1
            else:
                _continue = input("Type 'y' to get another card, type 'n' to pass: ")
                if _continue == "y":
                    print()
                    user_cards.append(self.deal_card())
                elif _continue == "n":
                    is_game_over = 1
                else:
                    print("please input y or n only\n")
                    is_game_over = 0

        return user_cards

    def play_computer_turn(self, computer_cards):
        computer_score = self.calculate_score(computer_cards)
        while computer_score != 0 and computer_score < 17:
            computer_cards.append(self.deal_card())
            computer_score = self.calculate_score(computer_cards)
        return computer_cards

    def play_game(self):
        user_cards = []
        computer_cards = []
        for _ in range(2):
            user_cards.append(self.deal_card())
            computer_cards.append(self.deal_card())

        user_cards = self.play_player_turn(user_cards, computer_cards)
        computer_cards = self.play_computer_turn(computer_cards)

        user_score = self.calculate_score(user_cards)
        computer_score = self.calculate_score(computer_cards)

        print(f"Your final hand: {user_cards}, final score: {user_score}")
        print(f"Computer's final hand: {computer_cards}, final score: {computer_score}")
        print(self.compare(user_score, computer_score))

def main():
    player = Player()
    print("Let's play Blackjack\n")
    player.play_game()

if __name__ == "__main__":
    main()

