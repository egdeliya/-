#pragma once

#ifndef _HEADER_H
#define _HEADER_H

#include "Header.h"
#endif

#include "Card.h"

class Hand {
	public:
		Hand();
		virtual ~Hand();

		// добавляет карту в руку
		void add(Card* card);

		// очищает руку от карт
		void clear();

		// получает сумму очков карт в руке
		int getTotal() const;
	protected:
		vector<Card*> cards_;
};

inline Hand::Hand() {
	cards_.reserve(4);
}

inline Hand::~Hand() {
	clear();
}

inline void Hand::add(Card* card) {
	cards_.push_back(card);
}

inline void Hand::clear() {
	vector<Card*>::iterator iter;
	for (iter = cards_.begin(); iter != cards_.end(); ++iter) {
		delete *iter;
		*iter = nullptr;
	}
	cards_.clear();
}

// TODO 
inline int Hand::getTotal() const {
	if (cards_.empty())
		return 0;

	// если у карты нулевое значение, то она лежит рубашкой вверх, нужно вернуть 0
	if (cards_[0]->getValue() == 0)
		return 0;


}



