

#include"Animation.h"

Animation::Animation(std::string imagePathLeft, std::string imagePathRight, int _w, int _h, const int frames,
	const int _clips[][4], SDL_Renderer* renderer) {
	current_frame = 0;
	coordinates.x = coordinates.y = 0;
	coordinates.w = _w, coordinates.h = _h;
	texture = loadImage(imagePathLeft, renderer);
	SDL_Rect clip;
	for (int i = 0; i < frames; i++) {
		clip.x = _clips[i][0];
		clip.y = _clips[i][1];
		clip.w = _clips[i][2];
		clip.h = _clips[i][3];
		clips.push_back(clip);
	}
}

Animation::~Animation() {
	if (texture != nullptr) {
		SDL_DestroyTexture(texture);
		texture = nullptr;
	}
}

void Animation::renderAnimation(SDL_Renderer* renderer) {
	SDL_RenderCopy(renderer, texture, &clips[current_frame], &coordinates);
	tick();
}

void Animation::move(int x, int y) {
	coordinates.x -= x;
	coordinates.y -= y;
}