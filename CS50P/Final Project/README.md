# **BlackJack Challenge**

## Description
This software is a simple text-based the Blackjack card game. User will play against the computer (dealer). The player and the computer will take turns drawing cards, trying to get as close to 21 as possible without exceeding it. The software will display the current hands and scores after each action.


## Documentation of each function(function_name(parameter))
### -Card Dealing (deal_card())
The game begins by dealing cards to both the player and the computer. The deal_card function is responsible for this by selecting a card from a list of possible values. These values are typically representative of a deck of cards in Blackjack, where the face cards (Jack, Queen, King) are worth 10 points, and an Ace is worth either 1 or 11 points.



### -Score Calculation (calculate_score(cards))
The score calculation is at the core of Blackjack. The calculate_score function takes a list of cards and computes the total score. If the sum equals 21 with only two cards, this is considered a "Blackjack," and a score of 0 is a win. When the player has an Ace card, the sum of cards is more than 21, the Ace card will automatically change the value from 11 to 1, which can help prevent busting (going over 21). The function handles these rules to ensure the score reflects the correct game rules.



### -Comparing Scores (compare(user_score, computer_score))
Once the game ends, the compare function is used to determine the winner by comparing the player's and the computer’s scores. Several outcomes are handled, such as both the player and the computer going over 21 (busting), the player getting a Blackjack, or ties. The function returns appropriate messages like "You win!" or "You lose ;(" based on the results of the comparison.



### -Player’s Turn (play_player_turn(user_cards, computer_cards))
In the play_player_turn function, the player is prompted to either draw another card or pass. This continues until the player either goes over 21, gets a Blackjack, or decides to stop drawing cards. The function ensures that only valid inputs (either 'y' for "yes" to draw a card, or 'n' for "no" to stop) are accepted. The game loop checks the player’s current score after each decision to determine if the game should end.



### -Computer’s Turn (play_computer_turn(computer_cards))
The computer, acting as the dealer, plays its turn according to specific rules. The play_computer_turn function ensures that the computer keeps drawing cards until its score reaches at least 17. If the computer’s score is less than 17, it draws another card. The computer’s turn ends when its score is 17 or higher, or it busts by exceeding 21.



### -Game Flow (play_game())
The play_game function orchestrates the entire game. It initiates by dealing two cards to both the player and the computer, and then it proceeds with the player's turn and the computer’s turn. After both have finished their turns, the final scores are displayed, and the compare function is called to determine the winner.



