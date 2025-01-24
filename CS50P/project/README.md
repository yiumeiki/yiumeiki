    # ** BlackJack Challenge **
    #### Video Demo:  <URL HERE>
    #### Description: This program is
1. Card Dealing (deal_card Method)
The game begins by dealing cards to both the player and the computer. The deal_card method is responsible for this by selecting a card from a predefined list of possible values. These values are typically representative of a deck of cards in Blackjack, where the face cards (Jack, Queen, King) are worth 10 points, and an Ace is worth either 1 or 11 points.

2. Score Calculation (calculate_score Method)
The score calculation is at the core of Blackjack. The calculate_score method takes a list of cards and computes the total score. If the sum equals 21 with only two cards, this is considered a "Blackjack," and a score of 0 is returned to signify an automatic win. If the player has an Ace and their score exceeds 21, the Ace’s value is reduced from 11 to 1, which can help prevent busting (going over 21). The method handles these rules to ensure the score reflects the correct game rules.

3. Comparing Scores (compare Method)
Once the game ends, the compare method is used to determine the winner by comparing the player's and the computer’s scores. Several outcomes are handled, such as both the player and the computer going over 21 (busting), the player getting a Blackjack, or ties. The method returns appropriate messages like "You win!" or "You lose ;(" based on the results of the comparison.

4. Player’s Turn (play_player_turn Method)
In the play_player_turn method, the player is prompted to either draw another card or pass. This continues until the player either goes over 21, gets a Blackjack, or decides to stop drawing cards. The method ensures that only valid inputs (either 'y' for "yes" to draw a card, or 'n' for "no" to stop) are accepted. The game loop checks the player’s current score after each decision to determine if the game should end.

5. Computer’s Turn (play_computer_turn Method)
The computer, acting as the dealer, plays its turn according to specific rules. The play_computer_turn method ensures that the computer keeps drawing cards until its score reaches at least 17. If the computer’s score is less than 17, it draws another card. The computer’s turn ends when its score is 17 or higher, or it busts by exceeding 21.

6. Game Flow (play_game Method)
The play_game method orchestrates the entire game. It initiates by dealing two cards to both the player and the computer, and then it proceeds with the player's turn and the computer’s turn. After both have finished their turns, the final scores are displayed, and the compare method is called to determine the winner.
