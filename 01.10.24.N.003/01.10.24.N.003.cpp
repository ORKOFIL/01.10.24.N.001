//14:30
//
#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

enum Cards {
	two,
	three,
	four,
	five,
	six,
	seven,
	eight,
	nine,
	ten,
	valet,
	dama,
	korol,
	tuz,
	totalCards
};
enum Suits {
	cherva,
	pika,
	bubna,
	hresta,
	totalSuits
};

struct Card {
	Suits suit;
	Cards card;
};

void printCard(const Card& card) {
	switch (card.card) {
	case two: cout << "2"; break;
	case three: cout << "3"; break;
	case four: cout << "4"; break;
	case five: cout << "5"; break;
	case six: cout << "6"; break;
	case seven: cout << "7"; break;
	case eight: cout << "8"; break;
	case nine: cout << "9"; break;
	case ten: cout << "10"; break;
	case valet: cout << "VAL"; break;
	case dama: cout << "DAM"; break;
	case korol: cout << "KOR"; break;
	case tuz: cout << "TUZ"; break;
	}

	switch (card.suit) {
	case cherva: cout << "CH"; break;
	case pika: cout << "PIK"; break;
	case bubna: cout << "BUB"; break;
	case hresta: cout << "HR"; break;
	}

}

void printDeck(const array<Card, 52>& deck) {
	int i = 0;
	for (const auto& card : deck) {
		printCard(card);
		cout << " ";
		i++;
		if (i % 13 == 0) {
			cout << endl;
		}
	}

}

int main() {
	array<Card, 52> deck;

	int card = 0;
	for (int s = 0; s < totalSuits; s++) {
		for (int c = 0; c < totalCards; c++) {
			deck[card].suit = static_cast<Suits>(s);
			deck[card].card = static_cast<Cards>(c);
			card++;
		}
	}
	printDeck(deck);



}
