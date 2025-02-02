import random
from enum import Enum

class Suit(Enum):
    CLUBS = 0
    DIAMONDS = 1
    HEARTS = 2
    SPADES = 3

class Card:
    def __init__(self, suit, value):
        self.suit = suit
        self.value =  value

    def __str__(self):
        suits = ["Clubs", "Diamonds", "Hearts", "Spades"]
        return f"{suits[self.suit.value]}{self.value}"

    def __gt__(self, other):
        return self.value > other.value

class Deck:
    def __init__(self):
        self.cards = [Card(suit, value) for suit in Suit for value in range(1, 14)]

    def shuffle(self):
        random.shuffle(self.cards)

    def draw(self):
        return self.cards.pop()

class Player:
    def __init__(self, name):
        self.name = name
        self.hand = []
        self.points = 0

    def sort_hand(self):
        self.hand.sort(key=lambda card: (card.suit.value, card.value))

    def print_hand(self):
        for card in self.hand:
            print(card)

    # play card of current suit if available, otherwise play highest card
    def play_card(self, current_suit):
        cards_of_suit = [card for card in self.hand if card.suit == current_suit]
        if cards_of_suit:
            card_to_play = max(cards_of_suit, key=lambda card: card.value)
        else:
            card_to_play = max(self.hand, key=lambda card: card.value)
        self.hand.remove(card_to_play)
        return card_to_play

    @staticmethod
    def get_points(card):
        if card.value in [5, 10, 13]:
            return card.value
        return 0

def main():
    # generate 52 cards, 13 ranks in each of the four suits
    # implement draw cards function and shuffle
    # deck of 52 cards is dealt to 4 players
    # each player sorts cards according to suit

    # each player takes turns to play cards according to suit
    # player with largest card will play first in the next round

    # scoring: 5, 10, 13 are the cards with largest points, player with most points after all cards are played will be counted
    deck = Deck()
    deck.shuffle()

    players = [Player(f"Player {i + 1}") for i in range(4)]

    for i in range(52):
        players[i % 4].hand.append(deck.draw())

    for player in players:
        player.sort_hand()

    for player in players:
        print(f"{player.name}'s hand: ")
        player.print_hand()
        print()

    cur_player = 0
    # suits = [Suit.CLUBS, Suit.DIAMONDS, Suit.HEARTS, Suit.SPADES] # available suits

    for round in range(13):
        # cur_suit = random.choice(suits) # randomly pick a suit for the round
        first_player = players[cur_player]
        first_card = first_player.play_card(None) # first player plays any card
        cur_suit = first_card.suit
        print(f"--ROUND {round + 1}--")

        round_cards = [(first_card, cur_player)]
        round_points = Player.get_points(first_card)
        for i in range(1, 4):
            playeri = (cur_player + i) % 4
            played_card = players[playeri].play_card(cur_suit)
            print(f"Player {playeri + 1} plays: {played_card}")
            round_cards.append((played_card, playeri))
            round_points += Player.get_points(played_card)

        valid_cards = [(card, player) for card, player in round_cards if card.suit == cur_suit]
        if valid_cards:
            winning_card, winner = max(valid_cards, key=lambda x: x[0].value)
        else:
            winning_card, winner = max(round_cards, key=lambda x: x[0].value)

        print(f"Player {players[winner].name} wins the round and takes {round_points} points! \n")

        players[winner].points += round_points

        cur_player = winner

    print("--FINAL SCORES--")
    for player in players:
        print(f"{player.name}: {player.points} points")

    max_score = max(player.points for player in players)
    winners = [player.name for player in players if player.points == max_score]
    if len(winners) == 1:
        print(f"{winners[0]} wins the game!")
    else:
        print(f"{', '.join(winners)} tie for the win")

if __name__ == "__main__":
    main()
