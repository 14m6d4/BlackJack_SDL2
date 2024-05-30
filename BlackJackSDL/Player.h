
#ifndef PLAYER_H
#define PLAYER_H

#include"Card.h"
#include<vector>
#include"Texture.h"


class Player {
public:
	Player(SDL_Renderer* renderer);
	~Player();

	void render(SDL_Renderer* renderer); //Ve tat ca cac texture
	void takeCard(Card* card);
	void standButton() { stand_button = true; }
	bool getStandButton() { return stand_button; }

	void cooldown();
	int getTimeNextHit() { return time_next_hit; }
	bool isBusted() { return score > 21; }
	int getScore() { return score; }
	int getBudget() { return budget; }
	int getCash() { return cash; }

	void betCash(Mix_Chunk* button_click);
	void remainingCash(bool is_victory); 
	void confirmCash() { confirm = true; }
	bool getConfirm() { return confirm; }

	void newRound();
	void newGame();
private:
	bool stand_button = false;
	int score, round;
	int time_next_hit;
	int number_ace, cash, budget;
	bool confirm = false;

	std::vector<Card*> cards;
	Texture* hit;
	Texture* stand;
	Texture* Cash;
	Texture* Budget;
	Texture* Round;
};


#endif 