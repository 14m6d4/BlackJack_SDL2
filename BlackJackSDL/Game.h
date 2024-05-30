
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
	void intruction();
	void over();
	void confirmCash();
	void newTurn();
private:
	//TEN CAC BIEN THANH PHAN
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_Event e;
	GameState game_state;
	Mix_Chunk* flip_card;
	Mix_Chunk* button_click;
	Mix_Music* music;

	SDL_Texture* game_lost;
	SDL_Texture* game_victory;
	SDL_Texture* instructions;
	SDL_Texture* new_game;
	Texture* tutorial;
	SDL_Texture* background;
	Player* player;
	Dealer* dealer;
	Deck* deck;
};


#endif 