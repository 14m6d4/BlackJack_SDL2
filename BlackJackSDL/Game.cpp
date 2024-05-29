
#include"Game.h"

Game::Game() {
	initSDL(window, renderer);
	std::cout << "Init window and renderer\n";

	game_state = GameState::Play;

	background = loadImage(TABLE_BACKGROUND_PATH, renderer);
	game_lost = loadImage(GAME_LOST_PATH, renderer);
	game_victory = loadImage(GAME_VICTORY_PATH, renderer);
	instructions = loadImage(GAME_INSTRUCTIONS_PATH, renderer);
	new_game = loadImage(NEW_GAME_PATH, renderer);
	tutorial = new Texture(100, 50, 1000, 300);
	tutorial->setImageTexture(TUTORIAL_PATH, renderer);
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


	button_click = loadSound(BUTTON_CLICK);
	flip_card = loadSound(FLIP_CARD);
	music = loadMusic(BACKGROUND_MUSIC);
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
	if (!player->getConfirm()) {
		tutorial->render(renderer);
		SDL_RenderPresent(renderer);
	}
	if (player->getConfirm()) {
		dealer->render(player->getStandButton(), renderer);
	}
	if (game_state == GameState::Over) {
		if (player->getScore() <= 21 && (player->getScore() > dealer->getScore() || dealer->getScore() > 21)) {
			SDL_RenderCopy(renderer, game_victory, NULL, NULL);
			player->remainingCash(true);

		}
		else {
			if (player->getBudget() <= 0) {
				SDL_RenderCopy(renderer, new_game, NULL, NULL);
			}
			else {
				SDL_RenderCopy(renderer, game_lost, NULL, NULL);
			}
			player->remainingCash(false);
			game_state = GameState::Over;

		}

	}
	SDL_RenderPresent(renderer);
	SDL_Delay(50);
}

void Game::running() {
	while (game_state != GameState::Quit) {
		//Game::intro;
		Game::play();
		Game::over();
	}
}

void Game::play() {
	std::cout << "Start playing\n";
	playMusic(music);
	Mix_VolumeMusic(MIX_MAX_VOLUME / 2);
	while (game_state == GameState::Play) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_QUIT) {
				game_state = GameState::Quit;
				break;
			}
			else if (e.type == SDL_MOUSEBUTTONDOWN) {
				Game::intruction();
				Game::confirmCash();
				if (player->getConfirm()) {
					int x, y;
					SDL_GetMouseState(&x, &y);
					if (410 <= y && y <= 460 && x <= 1170 && x >= 960) {
						std::cout << "Take a card\n";
						playSound(button_click);
						player->takeCard(deck->getCurrentCard());
						deck->increaseIndex();
					}
					if (960 <= x && x <= 1170 && y >= 500 && y <= 555) {
						playSound(flip_card);
						player->standButton();
						SDL_Delay(100);
					}
				}
			}
			else {
				;
			}
		}
		while (player->getStandButton() && (dealer->getScore() < player->getScore()) && dealer->getScore() < 21) {
			dealer->takeCard(deck->getCurrentCard());
			deck->increaseIndex();
		}
		if (player->getStandButton() || player->isBusted()) {
			game_state = GameState::Over;
			std::cout << "Game Over!\n";
			break;
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
				if (x >= 490 && x <= 560 && 340 <= y && y <= 390) {
					playSound(button_click);
					game_state = GameState::Play;
					newTurn();
					break;
				}
				if (610 <= x && x <= 680 && y >= 340 && y <= 390) {
					playSound(button_click);
					game_state = GameState::Quit;
					break;
				}
			}
		}
		render();
	}
}

void Game::newTurn() {
	if (player->getBudget() <= 0) {
		player->newGame();
	}
	else {
		player->newRound();
	}
	dealer->newTurn();
	deck->newTurn();

	player->takeCard(deck->getCurrentCard());
	deck->increaseIndex();
	player->takeCard(deck->getCurrentCard());
	deck->increaseIndex();
	std::cout << "New Round\n";
	dealer->takeCard(deck->getCurrentCard());
	deck->increaseIndex();
	dealer->takeCard(deck->getCurrentCard());
	deck->increaseIndex();
	std::cout << "Set front card\n";
	dealer->setFrontTopCard();
	std::cout << "New Dealer\n";
}

void Game::intruction() {
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (0 <= x && x <= 80 && 0 <= y && y <= 100) {
		playSound(button_click);
		game_state = GameState::Instructions;
	}
	else return;
	while (game_state == GameState::Instructions) {
		while (SDL_PollEvent(&e)) {
			if (e.type == SDL_MOUSEBUTTONDOWN) {
				SDL_GetMouseState(&x, &y);
				if (0 <= y && y <= 80 && x >= SCREEN_WIDTH - 80 && x <= SCREEN_WIDTH) {
					playSound(button_click);
					game_state = GameState::Play;
					break;
				}

			}
		}
		SDL_RenderClear(renderer);
		SDL_RenderCopy(renderer, instructions, NULL, NULL);
		SDL_RenderPresent(renderer);
		SDL_Delay(30);
	}
}

void Game::confirmCash() {
	if (player->getConfirm()) return;
	player->betCash(button_click);
	if (player->getCash() <= 0) return;
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (90 <= x && x <= 270 && 410 <= y && y <= 460) {
		playSound(button_click);
		player->confirmCash();
	}
}