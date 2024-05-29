#ifndef DEFS_H
#define DEFS_H

#include<string>
#include"Common.h"

const int SCREEN_WIDTH = 1200;
const int SCREEN_HEIGHT = 600;

const std::string WINDOW_TITLE = "Blackjack";
const std::string FONT_PATH = "Saddlebag-Black.ttf";

const SDL_Color RED_COLOR = { 255, 0, 0 };
const SDL_Color LIGHT_BLUE_COLOR = { 0, 255, 255 };
const SDL_Color BLACK_COLOR = { 0, 0, 0 };

const std::string GAME_LOST_PATH = "./Image\\Lost.png";
const std::string GAME_VICTORY_PATH = "./Image\\Won.png";
const std::string GAME_INSTRUCTIONS_PATH = "./Image\\Instructions.png";
const std::string TABLE_BACKGROUND_PATH = "Image\\table_background.png";
const std::string NEW_GAME_PATH = "Image\\NewGame.png";
const std::string TUTORIAL_PATH = "./Image\\Tutorial.png";
const int CENTERX = SCREEN_WIDTH / 2;
const int CENTERY = SCREEN_HEIGHT / 2;

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

const int TIME_NEXT_HIT = 250;


enum class GameState {
    Play,
    Instructions,
    Over,
    Quit,
};


const std::string FLIP_CARD = "./Sound\\flipCard.mp3";
const std::string BUTTON_CLICK = "./Sound\\buttonClick.wav";
const std::string BACKGROUND_MUSIC = "./Sound\\Sabbath.mp3";

#endif 