
#include"Player.h"

Player::Player(SDL_Renderer* renderer) {
	score = 0;
	time_next_hit = TIME_NEXT_HIT;
	hit = new Texture(1025, 425, 80, 30);
	hit->setText("HIT", RED_COLOR, FONT_PATH, renderer);
	stand = new Texture(1025, 510, 80, 40);
	stand->setText("STAND", RED_COLOR, FONT_PATH, renderer);
}

Player::~Player() {
	/*int size = cards.size();
	for (int i = 0; i < size; i++) {
		delete cards[i];
		cards[i] = nullptr;
	}*/
}

void Player::render(SDL_Renderer* renderer) {
	hit->render(renderer);
	stand->render(renderer);
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
	time_next_hit = TIME_NEXT_HIT;
	int score_card = calculateScore(card->getRank());
	if (score_card == 1) {
		if (score + 11 <= 21) {
			score += 11;
		}
		else {
			score += 1;
		}
		return;
	}
	score += score_card;
}

void Player::cooldown() {
	if (time_next_hit > 0) {
		time_next_hit--;
	}
}

void Player::newTurn() {
	stand_button = false;
	score = 0;
	cards.clear();
	std::cout << "clear player\n";
	/*for (int i = 0; i < cards.size(); ++i) {
		cards[i] = nullptr;
	}*/
}