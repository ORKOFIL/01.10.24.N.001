//14:30
//
#include <iostream>
#include <string>
#include <array>
#include <algorithm>
#include <cstdlib>

using namespace std;

int getRandomNumber(int min, int max)
{
	static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0);
	return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}

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

void swapCard(int a, int b, array<Card, 52>& deck) {
	swap(deck[a].card, deck[b].card);
	swap(deck[a].suit, deck[b].suit);
}

void shuffleDeck(array<Card, 52>& deck) {
	for (int i = 0; i < 51; i++) {
		int r = getRandomNumber(0, 51);
		swapCard(r, i, deck);
	}
}

int getCardValue(const Card& card) {
	switch (card.card) {
	case two: return 2; break;
	case three: return 3; break;
	case four: return 4; break;
	case five: return 5; break;
	case six: return 6; break;
	case seven: return 7; break;
	case eight: return 8; break;
	case nine: return 9; break;
	case ten: return 10; break;
	case valet: return 10; break;
	case dama: return 10; break;
	case korol: return 10; break;
	case tuz: return 11; break;
	}
}

int main() {
	srand(static_cast<unsigned int>(time(0)));
	rand();
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
	//shuffleDeck(deck);

	/*int i = 0;
	for (const auto& card : deck) {
		cout<<getCardValue(card);
		cout << " ";
		i++;
		if (i % 13 == 0)
			cout << endl;
	}*/

	/*int index = 1;
	cout<<"fff" << getCardValue(deck[index]);*/

}
