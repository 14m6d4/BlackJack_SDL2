
#include"Game.h"

Game::Game() {
	initSDL(window, renderer);
	std::cout << "Init window and renderer\n";

	game_state = GameState::Play;

	background = loadImage(TABLE_BACKGROUND_PATH, renderer);
	game_lost = loadImage(GAME_LOST_PATH, renderer);
	game_victory = loadImage(GAME_VICTORY_PATH, renderer);
	deck = new Deck(renderer);
	std::cout << "Init deck\n";

	player = new Player(renderer);
	player->takeCard(deck->getCurrentCard());
	deck->increaseIndex();
	player->takeCard(deck->getCurrentCard());
	deck->increaseIndex();
	std::cout << "Init player\n";
	dealer = new Dealer(renderer);
	dealer->takeCard(deck->getCurrentCard());
	deck->increaseIndex();
	dealer->takeCard(deck->getCurrentCard());
	deck->increaseIndex();
	dealer->setFrontTopCard();

	std::cout << "Init game\n";
}

Game::~Game() {
	delete player;
	delete deck;
	delete dealer;
	quitSDL(window, renderer);
}

void Game::render() {
	SDL_RenderClear(renderer);
	SDL_RenderCopy(renderer, background, NULL, NULL);

	player->render(renderer);
	dealer->render(player->getStandButton(), renderer);
	if (game_state == GameState::Over) {
		if (player->getScore() > dealer->getScore() && player->getScore() <= 21) {
			SDL_RenderCopy(renderer, game_victory, NULL, NULL);
		}
		else if (dealer->getScore() <= 21 || player->isBusted()) {
			SDL_RenderCopy(renderer, game_lost, NULL, NULL);
			game_state = GameState::Over;
		}
	}
	SDL_RenderPresent(renderer);
	SDL_Delay(20);
}

void Game::running() {
	while (game_state != GameState::Quit) {
		//Game::intro;
		Game::play();
		Game::over();
	}
}

void Game::play() {
	std::cout << "play\n";
	while (game_state == GameState::Play) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				game_state = GameState::Quit;
				break;
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN) {
				int x, y;
				SDL_GetMouseState(&x, &y);
				if (410 <= y && y <= 460 && x <= 1170 && x >= 960) {
					std::cout << "take a card\n";
					player->takeCard(deck->getCurrentCard());
					deck->increaseIndex();
				}
				if (960 <= x && x <= 1170 && y >= 500 && y <= 555) {
					//dealer->showCard();
					player->standButton();
					SDL_Delay(100);
				}
			}
			else {
				;
			}
		}
		if (player->getStandButton() || player->isBusted()) {
			game_state = GameState::Over;
			std::cout << "Game over\n";
			break;
		}
		while (player->getStandButton() && dealer->getScore() <= player->getScore()) {
			dealer->takeCard(deck->getCurrentCard());
			deck->increaseIndex();
		}
		render();
	}
}

void Game::over() {
	while (game_state == GameState::Over) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				game_state = GameState::Quit;
				break;
			}
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				int x, y;
				SDL_GetMouseState(&x, &y);
				if (x >= 530 && x <= 580 && 380 <= y && y <= 410) {
					game_state = GameState::Play;
					newTurn();
					break;
				}
				if (620 <= x && x <= 670 && y >= 380 && y <= 410) {
					game_state = GameState::Quit;
					break;
				}
			}
		}
		render();
	}
}

void Game::newTurn() {
	player->newTurn();
	dealer->newTurn();
	deck->newTurn();

	player->takeCard(deck->getCurrentCard());
	deck->increaseIndex();
	player->takeCard(deck->getCurrentCard());
	deck->increaseIndex();
	std::cout << "New player\n";

	dealer->takeCard(deck->getCurrentCard());
	deck->increaseIndex();
	std::cout << "dealer take card\n";
	dealer->takeCard(deck->getCurrentCard());
	deck->increaseIndex();
	std::cout << "Set front card\n";
	dealer->setFrontTopCard();
	std::cout << "New dealer\n";
}