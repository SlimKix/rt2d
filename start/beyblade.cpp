/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "beyblade.h"


 BeyBlade::BeyBlade() : Entity()
{
	 this->addSprite("assets/square.tga");

	Vector2 bSize = this->sprite()->size;

	 srand(time(0));
	 int x = (rand() % SWIDTH * 2) - SWIDTH;
	 int y = (rand() % SHEIGHT * 2) - SHEIGHT;
	 velocity = Vector2(x, y);
	 rotationSpeed = 10.0f;
	 friction = -0.1;
	 
}
 

BeyBlade::~BeyBlade()
{
	
}

void BeyBlade::update(float deltaTime)
{
	this->rotation.z += HALF_PI * rotationSpeed * deltaTime;
	rotationSpeed += friction *deltaTime;
	if (rotationSpeed <= 0) {
		rotationSpeed = 0;
	}

	this->position += velocity * deltaTime;


	if(this->position.x >= SWIDTH - (bSize.x/2)) {
		velocity.x *= -1;
		rotationSpeed -= 0.1f;
	}
	if (this->position.x <= 0 + (bSize.x / 2)) {
		velocity.x *= -1;
		rotationSpeed -= 0.1f;
	}
	if (this->position.y >= SHEIGHT - (bSize.x / 2)) {
		velocity.y *= -1;
		rotationSpeed -= 0.1f;
	}
	if (this->position.y <= 0 + (bSize.x / 2)) {
		velocity.y *= -1;
		rotationSpeed -= 0.1f;
	}
}
	






