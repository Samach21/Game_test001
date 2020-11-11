#include "Player.h"


void Player::initVariables()
{
	this->movementSpeed = 10.f;
	this->preWidth = 11.f;
	this->preHeight = 177.f;
	this->width = 39.f;
	this->height = 55.f;
	this->moving = false;
	this->standNum = 1;
	this->moveNum = 1;
	this->turnLeft = false;
}

void Player::initSprite()
{
	if (!this->texture.loadFromFile("preEllie.png"))
	{
		cout << "ERROR" << "\n";
	}
	this->currentFrame = IntRect(this->preWidth, this->preHeight, this->width, this->height);
	this->sprite.setTexture(this->texture);
	this->sprite.setTextureRect(this->currentFrame);
	this->sprite.scale(3.f, 3.f);
	this->sprite.setPosition(0.f, 0.f);
}

void Player::initAnimetion()
{
	this->aniTime.restart();
}

Player::Player()
{
	this->initVariables();
	this->initSprite();
	this->initAnimetion();
}

Player::~Player()
{
}

void Player::updateInput()
{
	if (Keyboard::isKeyPressed(Keyboard::A))
	{
		this->sprite.move(-this->movementSpeed, 0.f);
		this->moving = true;
		this->turnLeft = true;
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			this->sprite.move(0.f, -this->movementSpeed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			this->sprite.move(0.f, this->movementSpeed);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::D))
	{
		this->sprite.move(this->movementSpeed, 0.f);
		this->moving = true;
		this->turnLeft = false;
		if (Keyboard::isKeyPressed(Keyboard::W))
		{
			this->sprite.move(0.f, -this->movementSpeed);
		}
		else if (Keyboard::isKeyPressed(Keyboard::S))
		{
			this->sprite.move(0.f, this->movementSpeed);
		}
	}
	else if (Keyboard::isKeyPressed(Keyboard::W))
	{
		this->sprite.move(0.f, -this->movementSpeed);
		this->moving = true;
	}
	else if (Keyboard::isKeyPressed(Keyboard::S))
	{
		this->sprite.move(0.f, this->movementSpeed);
		this->moving = true;
	}
	else
	{
		this->moving = false;
	}
}

void Player::updateAnimation()
{
	if (this->standNum >= 4)
	{
		this->standNum = 1;
	}
	if (this->moveNum >= 5)
	{
		this->moveNum = 1;
	}
	if (this->aniTime.getElapsedTime().asSeconds() >= 0.1f)
	{
		if (this->moving == false)
		{
			this->moveNum = 1;
			this->preHeight = 177.f;
			this->width = 39.f;
			switch (this->standNum)
			{
			case 1: this->preWidth = 59.f;
				break;
			case 2: this->preWidth = 110.f;
				break;
			case 3: this->preWidth = 11.f;
				break;
			default:
				break;
			}
			this->standNum++;
		}
		else if (this->moving == true)
		{
			this->standNum = 3;
			this->preHeight = 257.f;
			this->width = 52.f;
			switch (this->moveNum)
			{
			case 1: this->preWidth = 8.f;
				break;
			case 2: this->preWidth = 65.f;
				break;
			case 3: this->preWidth = 143.f;
				break;
			case 4: this->preWidth = 202.f;
				break;
			default:
				break;
			}
			this->moveNum++;
		}
		if (this->turnLeft == false)
		{
			this->currentFrame = IntRect(this->preWidth, this->preHeight, this->width, this->height);
		}
		else if (this->turnLeft == true)
		{
				this->currentFrame = IntRect(this->preWidth + this->width, this->preHeight, -this->width, this->height);
		}
		this->sprite.setTextureRect(this->currentFrame);
		this->aniTime.restart();
	}
}

void Player::update(RenderTarget* target)
{
	this->updateInput();
	this->updateAnimation();
}

void Player::render(RenderTarget* target)
{
	target->draw(this->sprite);
}
