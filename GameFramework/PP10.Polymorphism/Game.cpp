#include "Game.h"
#include "GameObject.h"
using namespace std;

bool Game::init(const char* title, int xpos, int ypos,
	int width, int height, bool fullscreen)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		m_pWindow = SDL_CreateWindow(title, xpos, ypos, width, height, SDL_WINDOW_SHOWN);
		if (m_pWindow != 0)
		{
			m_pRenderer = SDL_CreateRenderer(m_pWindow, -1, 0);
		}

		m_bRunning = true;

		//load 부분 대치
        if (!TextureManager::Instance()->load("assets/mario.png", "mario", m_pRenderer))
        {
            return false;
        }
        
        m_monster1 = new Monster(3);
        m_monster2 = new Monster(5);

        m_monster1->load(0, 0, 100, 100, "mario", SDL_FLIP_NONE);
        m_monster2->load(0, 150, 100, 100, "mario", SDL_FLIP_NONE);

        m_gameObjects.push_back(m_monster1);
        m_gameObjects.push_back(m_monster2);
		SDL_SetRenderDrawColor(m_pRenderer, 255, 255,255, 255);
	}
	else
	{
		return false; // sdl could not initialize
	}
	return true;
}

void Game::render()
{
    SDL_RenderClear(m_pRenderer); // clear to the draw colour
    for (vector<GameObject*>::size_type i = 0;
        i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->draw(m_pRenderer);
    }
    SDL_RenderPresent(m_pRenderer); // draw to the screen

}

void Game::clean()
{
	cout << "cleaning game\n";
	SDL_DestroyWindow(m_pWindow);
	SDL_DestroyRenderer(m_pRenderer);
	SDL_Quit();
}

void Game::handleEvents()
{
	SDL_Event event;
	if (SDL_PollEvent(&event))
	{
		switch (event.type)
		{
		case SDL_QUIT:
			m_bRunning = false;
			break;
		default:
			break;
		}
	}
}

void Game::update()
{
    for (vector<GameObject*>::size_type i = 0;
        i != m_gameObjects.size(); i++)
    {
        m_gameObjects[i]->update();
    }
}

Game::Game()
{

}

Game::~Game()
{

}