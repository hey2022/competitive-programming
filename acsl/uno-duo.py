class Card:
    def __init__(self, card):
        self.value = card
        self.uni = (len(card) == 1)
        self.color = ""
        self.number = ""
        self.shape = ""
        if self.uni:
            if card in ["R", "Y", "G", "B"]:
                self.color = card
            elif card in ["X", "O", "S", "T"]:
                self.shape = card
            else:
                self.number = card
        else:
            self.color = card[0]
            self.number = card[1]
            self.shape = card[2]

    def matches(self, other):
        if not (self.uni or other.uni):
            cnt = 0
            if self.color == other.color:
                cnt += 1
            if self.number == other.number:
                cnt += 1
            if self.shape == other.shape:
                cnt += 1
            return cnt == 2
        elif not (self.uni and other.uni):
            return ((self.color and self.color == other.color) or
                    (self.number and self.number == other.number) or
                    (self.shape and self.shape == other.shape))
        else:
            return self.value == other.value

    def __str__(self):
        return self.color + self.number + self.shape


class Cards:
    def __init__(self, cards_str):
        self.cards = []
        if cards_str.strip():
            for s in cards_str.split():
                self.cards.append(Card(s))

    def top(self):
        if not self.cards:
            return None
        return self.cards[-1].value

    def append(self, card):
        self.cards.append(card)

    def pop(self):
        if not self.cards:
            return None
        return self.cards.pop()

    def length(self):
        return len(self.cards)


class Player:
    def __init__(self, hand_str):
        self.cards = Cards(hand_str)

    def round(self, shown, deck):
        pos = 1
        matched = False
        for card in self.cards.cards[:]:
            if card.matches(shown.cards[0]):
                shown.cards.pop(0)
                shown.cards.insert(0, card)
                self.cards.cards.remove(card)
                pos = 0
                matched = True
                break
            elif card.matches(shown.cards[-1]):
                shown.cards.pop()
                shown.cards.append(card)
                self.cards.cards.remove(card)
                pos = -1
                matched = True
                break
        if not matched:
            return False
        if pos == 0:
            while True:
                succ = False
                for card in self.cards.cards[:]:
                    if card.matches(shown.cards[0]):
                        shown.cards.pop(0)
                        shown.cards.insert(0, card)
                        self.cards.cards.remove(card)
                        succ = True
                        break
                if not succ:
                    break
        elif pos == -1:
            while True:
                succ = False
                for card in self.cards.cards[:]:
                    if card.matches(shown.cards[-1]):
                        shown.cards.pop()
                        shown.cards.append(card)
                        self.cards.cards.remove(card)
                        succ = True
                        break
                if not succ:
                    break
        while len(self.cards.cards) < 7 and deck.length() > 0:
            self.cards.cards.append(deck.cards.pop(0))
        return True


if __name__ == "__main__":
    shown = Cards(input())
    player = Player(input())
    deck = Cards(input())
    while True:
        played = player.round(shown, deck)
        if not played:
            break
    print(len(player.cards.cards), shown.cards[0].value, shown.cards[-1].value)
