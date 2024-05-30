
#include"Player.h"

Player::Player(SDL_Renderer* renderer) {
	score = 0;
	round = 1;
	number_ace = 0, cash = 0;
	time_next_hit = TIME_NEXT_HIT;
	hit = new Texture(1025, 425, 80, 30);
	hit->setText("HIT", RED_COLOR, FONT_PATH, renderer);
	stand = new Texture(1025, 510, 80, 40);
	stand->setText("STAND", RED_COLOR, FONT_PATH, renderer);
	Cash = new Texture(140, 425, 70, 33);
	Cash->setText(" $" + std::to_string(cash) + "  ", RED_COLOR, FONT_PATH, renderer);
	budget = 1000;
	Budget = new Texture(138, 283, 70, 33);
	Budget->setText("$" + std::to_string(budget), RED_COLOR, FONT_PATH, renderer);
	Round = new Texture(10, 560, 90, 30);
	Round->setText("Round: " + std::to_string(round), RED_COLOR, FONT_PATH, renderer);
}

Player::~Player() {
	cards.clear();
	delete hit;
	delete stand;
}

void Player::render(SDL_Renderer* renderer) {
	hit->render(renderer); //Goi ham ve cua texture
	stand->render(renderer);
	if (confirm) {
		Cash->setText("$" + std::to_string(cash), RED_COLOR, FONT_PATH, renderer);
		Cash->render(renderer);
	}
	else {
		Cash->setText("$" + std::to_string(cash), BLACK_COLOR, FONT_PATH, renderer);
		Cash->render(renderer);
	}
	Budget->setText("$" + std::to_string(budget), RED_COLOR, FONT_PATH, renderer);
	Budget->render(renderer);
	Round->setText("Round: " + std::to_string(round), RED_COLOR, FONT_PATH, renderer);
	Round->render(renderer);
	if (!confirm) return;
	int size = cards.size();
	int width = CARD_WIDTH / 2 * (size + 1);
	int posX = CENTERX - width / 2;
	for (int i = 0; i < size; ++i) {
		if (cards[i] != nullptr) {
			cards[i]->setPosition(posX + i * (CARD_WIDTH / 2), 450);
			cards[i]->render(renderer);
		}
	}
}

void Player::takeCard(Card* card) {
	card->setFront();
	cards.push_back(card);
	if (card->getRank() == Rank::ACE) number_ace++;
	time_next_hit = TIME_NEXT_HIT;
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

void Player::cooldown() {
	if (time_next_hit > 0) {
		time_next_hit--;
	}
}

void Player::newRound() {
	round++;
	confirm = false;
	score = 0;
	number_ace = 0;
	stand_button = false;
	cards.clear();
}

void Player::betCash(Mix_Chunk* button_click) {
	int x, y;
	SDL_GetMouseState(&x, &y);
	if (y >= 500 && y <= 555) {
		if (85 <= x && x <= 140) {
			playSound(button_click);
			if (cash >= 100) {
				cash -= 100;
				budget += 100;
			}
		}
		if (210 <= x && x <= 260) {
			playSound(button_click);
			if (budget >= 100) {
				cash += 100;
				budget -= 100;
			}
		}
	}
}

void Player::remainingCash(bool is_victory) {
	if (is_victory) {
		budget += 2 * cash;
	}
	cash = 0;
}

void Player::newGame() {
	round = 0;
	budget = 1000;
	newRound();
}