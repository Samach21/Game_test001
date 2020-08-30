#include "Game.h"
//private
void Game::initVariables()
{
	this->window = nullptr;
}

void Game::innitWindow()
{
	this->videomode.height = 1080;
	this->videomode.width = 1920;
	this->window = new RenderWindow(this->videomode, "Test game", Style::Titlebar | Style::Close);
}

//public
Game::Game()
{
	this->initVariables();
	this->innitWindow();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvent()
{
	while (this->window->pollEvent(this->ev))
	{
		switch (this->ev.type)
		{
		case Event::Closed:
			this->window->close();
			break;
		case Event::KeyPressed:
			if (this->ev.key.code == Keyboard::Escape)
			{
				this->window->close();
			}
			break;
		default:
			break;
		}
	}
}

void Game::update()
{
	this->pollEvent();
}

void Game::render()
{
	this->window->clear();
	// draw game here
	this->window->display();
}
