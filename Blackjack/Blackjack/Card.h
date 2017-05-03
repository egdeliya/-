#pragma once

#ifndef _HEADER_H
#define _HEADER_H

#include "Header.h"
#endif

class Card {
	public:
		enum rank {
			ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN,
			JACK, QUEEN, KING
		};
		enum suit {
			CLUBS, DIAMONDS, HEARTS, SPADES
		};
		
		friend ostream& operator<<(ostream& os, const Card& card);
		explicit Card(rank r=ACE, suit s=SPADES, bool ifu=true);
		
		// возвращает значение карты
		int getValue() const;

		// переворачивает карту 
		void flip();
	private:
		rank rank_;
		suit suit_;
		bool is_face_up_;
};

inline Card::Card(rank r, suit s, bool ifu) : rank_(r), suit_(s), is_face_up_(ifu) {}

inline void Card::flip() {
	is_face_up_ = !(is_face_up_);
}

inline int Card::getValue() const {
	// если карта перевернута лицом вниз, то её значение нулевое
	auto value = 0;
	if (is_face_up_) {
		value = rank_;

		// у короля, вольта и дамы значение равно 10
		if (value > 10)
			value = 10;
	}
	return value;
}


