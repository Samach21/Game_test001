#pragma once

#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

using namespace sf;

class Game
{
private:
	RenderWindow* window;
	VideoMode videomode;
	Event ev;
	void initVariables();
	void innitWindow();
public: 
	Game(); 
	virtual ~Game();
	const bool running() const;
	void pollEvent();
	void update();
	void render();
};

