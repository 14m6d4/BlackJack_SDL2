
#include"Common.h"
#include"Game.h"
#include<cstdlib>
#include<ctime>

int main(int argc, char** argv) {
	srand(time(0));
	Game* game = new Game();
	game->render();
	game->running();
	std::cout << "ok success!";
	//waitUntilKeyPressed();
	delete game;
	return 0;
}