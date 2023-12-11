/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myentity.h
 *
 * @brief description of MyEntity behavior.
 */

#ifndef BEYBLADE_H
#define BEYBLADE_H

#include <rt2d/entity.h>

/// @brief The MyEntity class is the Entity implementation.
class BeyBlade : public Entity
{
public:
	/// @brief Constructor
	BeyBlade();
	/// @brief Destructor
	virtual ~BeyBlade();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);
	//float angle;
	float rotationSpeed;
	float friction;
	Vector2 velocity;
	Vector2 bSize;


private:
	/* add your private declarations */
};

#endif /* MYENTITY_H */
