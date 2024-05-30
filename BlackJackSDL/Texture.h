
#ifndef SUPPORT_H
#define SUPPORT_H

#include"Common.h"
#include"Defs.h"
#include<vector>
#include<fstream>
#include<sstream>

class Texture {
public:
	Texture(int _x, int _y, int _w, int _h);
	~Texture();
	void render(SDL_Renderer* renderer);

	void setCoordinates(int x, int y) { coordinates.x = x, coordinates.y = y; } //Toa do cua vat the
	void setImageTexture(std::string imagePath, SDL_Renderer* renderer); //Them anh
	void setText(const std::string text, const SDL_Color color, const std::string fontPath, SDL_Renderer* renderer); //Them chu

	SDL_Rect getCoordinates() { return coordinates; }
	SDL_Point getPosition() { return { coordinates.x, coordinates.y }; }

private:
	SDL_Rect coordinates;
	SDL_Texture* texture;

};

#endif 