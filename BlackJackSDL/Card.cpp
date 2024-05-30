
#include"Card.h"

Card::Card(int _suit, int _rank, const std::string& image_path, SDL_Renderer* renderer) {
	front = true;
	front_card = loadImage(image_path, renderer);
	back_card = loadImage(BACK_CARD_PATH, renderer);
	position.x = position.y = -100;
	position.w = 100;
	position.h = 140;

	switch (_suit)
	{
	case 1:
		suit = CLUBS;
		break;
	case 2:
		suit = DIAMONDS;
		break;
	case 3:
		suit = HEARTS;
		break;
	case 4:
		suit = SPADES;
		break;
	default:
		break;
	}
	switch (_rank)
	{
	case 1:
		rank = Rank::ACE;
		break;
	case 2:
		rank = Rank::TWO;
		break;
	case 3:
		rank = Rank::THREE;
		break;
	case 4:
		rank = Rank::FOUR;
		break;
	case 5:
		rank = Rank::FIVE;
		break;
	case 6:
		rank = Rank::SIX;
		break;
	case 7:
		rank = Rank::SEVEN;
		break;
	case 8:
		rank = Rank::EIGHT;
		break;
	case 9:
		rank = Rank::NINE;
		break;
	case 10:
		rank = Rank::TEN;
		break;
	case 11:
		rank = Rank::JACK;
		break;
	case 12:
		rank = Rank::QUEEN;
		break;
	case 13:
		rank = Rank::KING;
		break;
	default:
		break;
	}
}

Card::~Card() {
	if (front_card != nullptr) {
		SDL_DestroyTexture(front_card);
		front_card = nullptr;
	}
	if (back_card != nullptr) {
		SDL_DestroyTexture(back_card);
		back_card = nullptr;
	}
}

void Card::render(SDL_Renderer* renderer) {
	if (front) {
		SDL_RenderCopy(renderer, front_card, NULL, &position);
	}
	else {
		SDL_RenderCopy(renderer, back_card, NULL, &position);
	}
}


Deck::Deck(SDL_Renderer* renderer) {
	for (int s = CLUBS; s <= SPADES; ++s) {
		for (int r = 1; r <= 13; ++r) {
			Card* card = new Card(s, r, getPath(r, s), renderer);
			cards.push_back(card);
		}
	}
	Deck::shuffle();
}

void Deck::shuffle() {
	for (int i = 0; i < CARD_SIZE; ++i) {
		int j = rand() % CARD_SIZE;
		std::swap(cards[i], cards[j]);
	}
}

std::string Deck::getPath(int r, int s) {
	std::string res = "./Image\\";

	switch (r)
	{
	case 1:
		res += "ace";
		break;

	case 2:
	case 3:
	case 4:
	case 5:
	case 6:
	case 7:
	case 8:
	case 9:
	case 10:
		res += std::to_string(r);
		break;
	case 11:
		res += "jack";
		break;
	case 12:
		res += "queen";
		break;
	case 13:
		res += "king";
		break;
	default:
		break;
	}

	res += "_of_";
	switch (s)
	{
	case 1:
		res += "clubs";
		break;
	case 2:
		res += "diamonds";
		break;
	case 3:
		res += "hearts";
		break;
	case 4:
		res += "spades";
		break;
	default:
		break;
	}
	res += ".png";
	return res;
}

Card* Deck::getCurrentCard() { //Xem la bai hien tai la la gi
	return cards[current_card];
}

void Deck::increaseIndex() { 
	if (current_card < CARD_SIZE)
		current_card++;
}

void Deck::newTurn() {
	shuffle();
	current_card = 0;
}