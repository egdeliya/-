#include "Card.h"
#include "Hand.h"
#include "GenericPlayer.h"
#include "Game.h"

ostream& operator<<(ostream& os, const Card& card);
ostream& operator<<(ostream& os, const GenericPlayer& generic_player);

int main() {
	cout << "\n\nWelcome to Blackjack\n\n";
	auto numPlayers = 0;
	while (numPlayers < 1 || numPlayers > 7) {
		cout << "How many players? (1-7)\n";
		cin >> numPlayers;
	}
	vector<string> names;
	string name;
	for (size_t i = 0; i < numPlayers; i++) {
		cout << "Enter player name: ";
		cin >> name;
		names.push_back(name);
		cout << endl;
	}

	
	// игровой цикл
	Game game(names);
	auto again = 'y';
	while (again != 'n' && again != 'N') {
		game.play();
		cout << "\nDo you want to play again? (Y/N): ";
		cin >> again;
		cout << endl;
	}		

	return 0;
}
