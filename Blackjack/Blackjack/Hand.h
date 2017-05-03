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

		// ��������� ����� � ����
		void add(Card* card);

		// ������� ���� �� ����
		void clear();

		// �������� ����� ����� ���� � ����
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

	// ���� � ����� ������� ��������, �� ��� ����� �������� �����, ����� ������� 0
	if (cards_[0]->getValue() == 0)
		return 0;


}



