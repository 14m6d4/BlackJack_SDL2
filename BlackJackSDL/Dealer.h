
#ifndef DEALER_H
#define DEALER_H

#include"Card.h"

class Dealer {
public:
	Dealer(SDL_Renderer* renderer);
	~Dealer();

	void render(bool is_stand, SDL_Renderer* renderer);
	void takeCard(Card* card);
	void setFrontTopCard();
	void showCard();
	int getScore() { return score; }

	void newTurn();
private:
	int score;
	std::vector<Card*> cards;
};

#endif