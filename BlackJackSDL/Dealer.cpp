
#include"Dealer.h"

Dealer::Dealer(SDL_Renderer* renderer) {
	score = 0;
	number_ace = 0;
}

Dealer::~Dealer() {
	cards.clear();
}

void Dealer::render(bool is_stand, SDL_Renderer* renderer) {
	int size = cards.size();
	if (size < 2) {
		return;
	}
	if (is_stand) {
		showCard();
		int width = CARD_WIDTH / 2 * (size + 1);
		int posX = CENTERX - width / 2;
		for (int i = 0; i < size; ++i) {
			cards[i]->setPosition(posX + i * (CARD_WIDTH / 2), 50);
			cards[i]->render(renderer);
		}
	}
	else {
		int posX = CENTERX - CARD_WIDTH * 3 / 4;
		for (int i = 0; i < 2; ++i) {
			cards[i]->setPosition(posX + i * (CARD_WIDTH / 2), 50);
			cards[i]->render(renderer);
		}
	}

}

void Dealer::takeCard(Card* card) {
	card->setBack();
	cards.push_back(card);
	if (card->getRank() == Rank::ACE) number_ace++;
	score += calculateScore(card->getRank());
	if (score > 21) {
		while (number_ace > 0) {
			score -= 10;
			number_ace--;
			if (score <= 21)
				break;
		}
	}
}

void Dealer::showCard() {
	for (size_t i = 0; i < cards.size(); ++i) {
		cards[i]->setFront();
	}
}

void Dealer::newTurn() {
	number_ace = 0;
	score = 0;
	cards.clear();
}

void Dealer::setFrontTopCard() { //Lat la bai dau len, luc dau up ca 2 la
	int size = cards.size();
	if (size < 1) return;
	cards[0]->setFront();
}
