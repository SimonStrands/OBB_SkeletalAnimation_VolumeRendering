#include "Game.h"

int main() {
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
	srand((unsigned int)time(0));
	DeltaTime dt;
	Game* game = new Game();
	bool gameOver = false;
	while (!gameOver) {
		dt.restartClock();
		gameOver = game->Update((float)dt.dt());
		game->Render();
		game->HandleEvents();
	}
	delete game;
	return 0;
}