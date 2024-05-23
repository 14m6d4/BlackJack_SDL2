
#include"Dealer.h"

Dealer::Dealer(SDL_Renderer* renderer) {
	score = 0;
}

Dealer::~Dealer() {
	/*int size = cards.size();
	for (int i = 0; i < size; i++) {
		delete cards[i];
		cards[i] = nullptr;
	}*/
	;
}

void Dealer::render(bool is_stand, SDL_Renderer* renderer) {
	int size = cards.size();
	if (size < 2) {
		std::cout << "size of cards of dealer < 2\n";
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
	if (score + calculateScore(card->getRank()) <= 21) {
		int score_card = calculateScore(card->getRank());
		if (score_card == 1) {
			if (score + 11 <= 21) {
				score += 11;
			}
			else {
				score += 1;
			}
		}
		else {
			score += score_card;
		}
		card->setBack();
		cards.push_back(card);
	}
}

void Dealer::showCard() {
	for (size_t i = 0; i < cards.size(); ++i) {
		cards[i]->setFront();
	}
}

void Dealer::newTurn() {
	score = 0;
	cards.clear();
	std::cout << "Clear dealer\n";
	/*for (int i = 0; i < cards.size(); ++i) {
		cards[i] = nullptr;
	}*/
}

void Dealer::setFrontTopCard() {
	int size = cards.size();
	if (size < 1) return;
	cards[0]->setFront();
}