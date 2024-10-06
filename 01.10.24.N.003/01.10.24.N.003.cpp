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

int draw = 0;

bool playBlackJack(array<Card, 52>& deck) {
	cout << "\nshuffled" << endl;
	shuffleDeck(deck);
	printDeck(deck);
	int cardPtr = 0;
	int dealer = 0;
	int player = 0;

	int dw = 0;
	int pw = 0;

	cout << "\ndealer got: ";
	printCard(deck[cardPtr]);
	cout << endl;
	dealer += getCardValue(deck[cardPtr]);
	cout << "dealer: " << dealer;

	cout << "\nplayer got: ";
	printCard(deck[cardPtr]);
	cardPtr++;
	player += getCardValue(deck[cardPtr]);
	cout << " ";
	printCard(deck[cardPtr]);
	cardPtr++;
	player += getCardValue(deck[cardPtr]);

	cout << "\ndealer: " << dealer;
	cout << "\nplayer: " << player;
	int turn = 1;
	int checker = 0;

	while (turn < 2) {
		for (int prob = 0; prob < 50; prob++) {
			cout << endl;
		}
		cout << "\n\n###PLAYERS TURN###";
		cout << "\ndealer: " << dealer;
		cout << " - player: " << player;
		int ans = 0;
		cout << "\nhit-1\nstand-2\nenter number: ";
		cin >> ans;

		if (ans == 1) {
		
			cardPtr++;
			player += getCardValue(deck[cardPtr]);
			if (getCardValue(deck[cardPtr]) == 11) {
				int tuzz = 0;
				cout << "\nplayer got: " << player << endl;
				cout << "you want tuz to be 1 or 11?" << endl;
				cin >> tuzz;
				if (tuzz == 1) {
					player - 10;
				}
			}

			if (player > 21) {
				cout << "\nplayer got: " << player << endl;
				cout << "YOU GOT MORE THAN 21\n";
				return false;
				turn++;
			}
			else if (player == 21) {
				cout << "\nBLACKJACK";
				pw += 2;
				turn++;
			}
			else {
				cout << "\nplayer got: " << player << endl;
			}
		}
		else if (ans == 2) {
			turn++;
		}

	}
	cout << "\n###DEALERS TURN###";
	cout << "\ndealer: " << dealer;
	cout << " - player: " << player << endl;

	do {
		cardPtr++;
		dealer += getCardValue(deck[cardPtr]);
		cout << "Dealer got: " << dealer << endl;
	} while (dealer < 17);

	if (dealer == 21) {
		cout << "\nBLACKJACK";
	}
	else if (dealer > 21) {
		cout << "\nDEALER GOT TO MUCH";
		return true;
	}

	cout << "\ndealer: " << dealer;
	cout << " - player: " << player << endl;

	if (dealer > player) {
		return false;
	}
	else if (dealer == player) {
		draw++;
		return true;
	}
	else {
		return true;
	}

	/*if (dw < pw) {
		return true;
	}
	if (pw < dw) {
		return false;
	}
	if (dealer == player) {
		draw++;
		return true;
	}*/
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
	int playy = 0;
	while (playy != 2) {
		for (int prob = 0; prob < 50; prob++) {
			cout << endl;
		}
		playy = 0;			
		cout << "\nPlay-1\nExit-2\n\nEnter answer: ";
		cin >> playy;
		if (playy == 1) {
			if (playBlackJack(deck)) {
				if (draw != 0) {
					cout << "\nDRAW";
				}
				else {
					cout << "\nPLAYER WON!";
				}
			}
			else {
				cout << "\nDEALER WON!";
			}
		}
	}



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
