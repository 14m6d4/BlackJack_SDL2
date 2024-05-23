
#ifndef CARD_H
#define CARD_H

#include"Defs.h"
#include"Common.h"
#include<vector>

class Card {
public:
	Card(int _suit, int _rank, const std::string& image_path, SDL_Renderer* renderer);
	~Card();
	void render(SDL_Renderer* renderer);

	void setBack() { front = false; }
	void setFront() { front = true; }
	void setPosition(int x, int y) { position.x = x, position.y = y; }
	SDL_Rect getPosition() { return position; }
	Suit getSuit() { return suit; }
	Rank getRank() { return rank; }

private:
	bool front;
	Suit suit;
	Rank rank;
	SDL_Texture* back_card = nullptr;
	SDL_Texture* front_card = nullptr;
	SDL_Rect position;
};

class Deck {
public:
	Deck(SDL_Renderer* renderer);
	void shuffle();
	std::string getPath(int r, int s);
	Card* getCurrentCard();
	void increaseIndex();
	void newTurn();
private:
	int current_card = 0;
	std::vector <Card*> cards;
};

#endif