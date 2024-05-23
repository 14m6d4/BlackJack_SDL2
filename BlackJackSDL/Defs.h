
#ifndef DEFS_H
#define DEFS_H

#include<string>
#include"Common.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;

const std::string WINDOW_TITLE = "BlackJack";
const std::string FONT_PATH = "BAUHS93.TTF";

const SDL_Color RED_COLOR = { 255, 0, 0 };
const SDL_Color LIGHT_BLUE_COLOR = { 0, 255, 255 };
const SDL_Color BLACK_COLOR = { 0, 0, 0 };

const std::string GAME_LOST_PATH = "./Image\\Lost.png";
const std::string GAME_VICTORY_PATH = "./Image\\Won.png";
const std::string TABLE_BACKGROUND_PATH = "Image\\table-background.png";
const int CENTERX = SCREEN_WIDTH / 2;
const int CENTERY = SCREEN_HEIGHT / 2;
/// CARD

const std::string BACK_CARD_PATH = "./Image\\back-card.png";
const int CARD_SIZE = 52;
const int CARD_WIDTH = 100;
const int CARD_HEIGHT = 140;


enum Suit {
    CLUBS = 1,
    DIAMONDS,
    HEARTS,
    SPADES
};

/// Player

const int TIME_NEXT_HIT = 250;


enum class GameState {
    Intro,
    Play,
    Over,
    Quit,
};

#endif 