
#ifndef GAME_H
#define GAME_H

#include"Common.h"
#include"Player.h"
#include"Dealer.h"

class Game {
public:
	Game();
	~Game();
	void render();

	void running();
	void play();
	//void intro();
	void over();

	void newTurn();
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event e;
	GameState game_state;

	SDL_Texture* game_lost;
	SDL_Texture* game_victory;

	SDL_Texture* background;
	Player* player;
	Dealer* dealer;
	Deck* deck;
};


#endif 