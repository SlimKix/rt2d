/**
 * This class describes MyEntity behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include "beyblade.h"


 BeyBlade::BeyBlade(KeyCode upKey, KeyCode leftKey, KeyCode downKey, KeyCode rightKey) : Entity()
{
	

	Vector2 bSize = this->sprite()->size;

	srand(time(0));

	float angle = static_cast<float>(rand() % 70) / 10;
	initialRotationSpeed = 100.0f;
	speed = 1000.0f;
	friction = 1;

	int x = speed * cos(angle);
	int y = speed * sin(angle);

	velocity = Vector2(x, y);
	rotationSpeed = 100.0f;

	upKey_ = upKey;
	leftKey_ = leftKey;
	downKey_ = downKey;
	rightKey_ = rightKey;
}
 

BeyBlade::~BeyBlade()
{
	
}

void BeyBlade::update(float deltaTime)
{
	this->rotation.z += HALF_PI * rotationSpeed * deltaTime;
	rotationSpeed -= friction *deltaTime;
	if (rotationSpeed <= 0) {
		rotationSpeed = 0;
	}

	this->position += velocity * deltaTime;
	this->rotationSpeed -= 0.01;


	if(this->position.x >= SWIDTH - (bSize.x/2)) {
		velocity.x *= -1;
		rotationSpeed -= 0.1f;
		position.x = SWIDTH;
	}
	if (this->position.x <= 0 + (bSize.x / 2)) {
		velocity.x *= -1;
		rotationSpeed -= 0.1f;
		position.x = 0;
	}
	if (this->position.y >= SHEIGHT - (bSize.x / 2)) {
		velocity.y *= -1;
		rotationSpeed -= 0.1f;
		position.y = SHEIGHT;
	}
	if (this->position.y <= 0 + (bSize.x / 2)) {
		velocity.y *= -1;
		position.y = 0;
	}

	if (input()->getKey(upKey_)) {
		this->velocity -= Point2(0, 700) * deltaTime;
	}
	if (input()->getKey(leftKey_)) {
		this->velocity -= Point2(700, 0) * deltaTime;
	}
	if (input()->getKey(downKey_)) {
		this->velocity += Point2(0, 700) * deltaTime;
	}
	if (input()->getKey(rightKey_)) {
		this->velocity += Point2(700, 0) * deltaTime;
	}
}
	






