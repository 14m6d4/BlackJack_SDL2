
#include"Texture.h"

Texture::~Texture() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

Texture::Texture(int _x, int _y, int _w, int _h) {
	coordinates.x = _x;
	coordinates.y = _y;
	coordinates.w = _w;
	coordinates.h = _h;
}

void Texture::setImageTexture(std::string imagePath, SDL_Renderer* renderer) {
	texture = loadImage(imagePath, renderer);
}

void Texture::setText(const std::string text, const SDL_Color color, const std::string fontPath, SDL_Renderer* renderer) {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
	texture = loadText(text, color, fontPath, renderer);
}

void Texture::render(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, NULL, &coordinates);
}

void Texture::move(int x, int y) {
	coordinates.x -= x;
	coordinates.y -= y;
}
