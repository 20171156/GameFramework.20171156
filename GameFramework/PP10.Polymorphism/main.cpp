#include "Game.h"
#include "Window.h"
#include <SDL.h>

Game* g_game = 0;

int main(int argc, char *argv[])
{
	g_game = new Game();
	g_game->init("Chapter1", WINDOW_X, WINDOW_Y, WINDOW_WIDTH, WINDOW_HEIGHT, false);

	while (g_game->running())
	{
		g_game->handleEvents();
		g_game->update();
		g_game->render();
		SDL_Delay(10);
	}

	g_game->clean();
	return 0;
}