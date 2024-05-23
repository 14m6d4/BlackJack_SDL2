
#ifndef PLAYER_H
#define PLAYER_H

#include"Card.h"
#include<vector>
#include"Texture.h"


class Player {
public:
	Player(SDL_Renderer* renderer);
	~Player();

	void render(SDL_Renderer* renderer);
	void takeCard(Card* card);
	void standButton() { stand_button = true; }
	bool getStandButton() { return stand_button; }
	void cooldown();
	int getTimeNextHit() { return time_next_hit; }
	bool isBusted() { return score > 21; }
	int getScore() { return score; }

	void newTurn();
private:
	bool stand_button = false;
	int score;
	int time_next_hit;
	//bool hit, stand;
	std::vector<Card*> cards;
	Texture* hit;
	Texture* stand;
};


#endif 