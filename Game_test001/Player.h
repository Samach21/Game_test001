#pragma once
#include<SFML/Graphics.hpp>
#include<SFML/System.hpp>
#include<SFML/Window.hpp>
#include<SFML/Audio.hpp>
#include<SFML/Network.hpp>

#include<iostream>

using namespace std;
using namespace sf;

class Player
{
private:
	RectangleShape shape;
	Sprite sprite;
	Texture texture;

	float movementSpeed;

	void initVariables();
	void initShape();
public:
	Player(float x = 0.f, float y = 0.f);
	virtual ~Player();

	void updateInput();
	void update(RenderTarget* target);
	void render(RenderTarget* target);
};

