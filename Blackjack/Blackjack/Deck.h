#pragma once

#ifndef _HEADER_H
#define _HEADER_H

#include "Header.h"
#include <complex>
#endif

#ifndef _HAND_H
#define _HAND_H
#include "Hand.h"
#endif

#include "GenericPlayer.h"

// колода карт
class Deck: public Hand {
	public:
		Deck();
		virtual ~Deck();

		// создаёт стандартную колоду из 52 карт
		void populate();

		// тасует карты
		void shuffle();

		// раздаёт одну карту в руку
		void deal(Hand& hand);

		// даёт дополнительные карты игроку
		void additionalCards(GenericPlayer& generic_player);
};

inline Deck::Deck() {
	cards_.reserve(52);
	populate();
}

inline Deck::~Deck() {}

inline void Deck::populate() {
	clear();
	// создаёт стандартную колоду
	for (size_t s = Card::CLUBS; s <= Card::SPADES; s++) 
		for (size_t r = Card::ACE; r <= Card::KING; r++) 
			add(new Card(static_cast<Card::rank>(r), static_cast<Card::suit>(s)));
}

inline void Deck::shuffle() {
	random_shuffle(cards_.begin(), cards_.end());
}

inline void Deck::deal(Hand& hand) {
	if (!cards_.empty()) {
		hand.add(cards_.back());
		cards_.pop_back();
	} else {
		cout << "Out of cards. Unable to deal\n";
	}
}

inline void Deck::additionalCards(GenericPlayer& generic_player) {
	cout << endl;
	// продолжает раздавать карты до тех пор, пока у 
	// игрока не случится перебор или он откажется брать карты
	while (!generic_player.isBusted() && generic_player.isHitting()) {
		deal(generic_player);
		cout << generic_player << endl;
		if (generic_player.isBusted())
			generic_player.Bust();
	}
}





