#include "Player.h"


void Player::initVariables()
{
	this->movementSpeed = 10.f;
}

void Player::initShape()
{
	if (!this->texture.loadFromFile("the-last-of-us-part-ii-seattle-bank-location.jpg"))
	{
		cout << "ERROR" << "\n";
	}
	this->shape.setFillColor(Color::Red);
	this->shape.setSize(Vector2f(100.f,100.f));
	this->sprite.setScale(Vector2f(10.f, 10.f));
	this->sprite.setTexture(this->texture);
}

Player::Player(float x, float y)
{
	this->shape.setPosition(900.f, 500.f);
	this->sprite.setPosition(x, y);

	this->initVariables();
	this->initShape();
}

Player::~Player()
{
}

void Player::updateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->sprite.move(this->movementSpeed, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->sprite.move(-this->movementSpeed, 0.f);
	}
	else if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->sprite.move(0.f, this->movementSpeed);
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->sprite.move(0.f, -this->movementSpeed);
	}
}

void Player::update(RenderTarget* target)
{
	this->updateInput();
}

void Player::render(RenderTarget* target)
{
	target->draw(this->sprite);
	target->draw(this->shape);
}
