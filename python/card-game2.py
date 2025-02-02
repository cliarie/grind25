import random
from enum import Enum

# Enum for Suit
class Suit(Enum):
    CLUBS = "♣"
    DIAMONDS = "♦"
    HEARTS = "♥"
    SPADES = "♠"

# Enum for Rank
class Rank(Enum):
    TWO = 2
    THREE = 3
    FOUR = 4
    FIVE = 5
    SIX = 6
    SEVEN = 7
    EIGHT = 8
    NINE = 9
    TEN = 10
    JACK = 11
    QUEEN = 12
    KING = 13
    ACE = 14

# Card class representing a card with a suit and rank
class Card:
    def __init__(self, suit, rank):
        self.suit = suit
        self.rank = rank

    def __str__(self):
        return f"{self.rank.name.capitalize()}{self.suit.value}"

    def __lt__(self, other):
        return self.rank.value < other.rank.value

    def __gt__(self, other):
        return self.rank.value > other.rank.value

# Deck class to represent a shuffled deck of 52 cards
class Deck:
    def __init__(self):
        self.cards = [Card(suit, rank) for suit in Suit for rank in Rank]

    # Shuffle the deck
    def shuffle(self):
        random.shuffle(self.cards)

    # Draw a card from the deck
    def draw(self):
        return self.cards.pop()

# Player class representing a player with a hand of cards
class Player:
    def __init__(self, name):
        self.name = name
        self.hand = []

    # Draw 5 cards from the deck to create a hand
    def draw_hand(self, deck):
        self.hand = [deck.draw() for _ in range(5)]
        self.sort_hand()

    # Sort the player's hand by card rank
    def sort_hand(self):
        self.hand.sort(key=lambda card: card.rank.value)

    # Get the highest card in the hand
    def get_highest_card(self):
        return max(self.hand, key=lambda card: card.rank.value)

    # Display the player's hand
    def print_hand(self):
        hand_str = ', '.join(str(card) for card in self.hand)
        print(f"{self.name}'s hand: {hand_str}")

# Function to determine the winner by comparing the highest card from both players
def determine_winner(player1, player2):
    p1_highest = player1.get_highest_card()
    p2_highest = player2.get_highest_card()

    print(f"\n{player1.name}'s highest card: {p1_highest}")
    print(f"{player2.name}'s highest card: {p2_highest}")

    if p1_highest > p2_highest:
        print(f"{player1.name} wins!")
    elif p2_highest > p1_highest:
        print(f"{player2.name} wins!")
    else:
        print("It's a tie!")

# Main function to run the game
def main():
    # Initialize the deck and shuffle it
    deck = Deck()
    deck.shuffle()

    # Create two players
    player1 = Player("Player 1")
    player2 = Player("Player 2")

    # Each player draws a hand of 5 cards
    player1.draw_hand(deck)
    player2.draw_hand(deck)

    # Print each player's hand
    player1.print_hand()
    player2.print_hand()

    # Determine the winner based on the highest card
    determine_winner(player1, player2)

if __name__ == "__main__":
    main()
