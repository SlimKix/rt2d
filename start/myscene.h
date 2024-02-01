/**
 * Copyright 2015 Your Name <you@yourhost.com>
 *
 * @file myscene.h
 *
 * @brief description of MyScene behavior.
 */

#ifndef MYSCENE_H
#define MYSCENE_H

#include <vector>
#include <rt2d/scene.h>
#include "beyblade.h"
#include "controller.h"
#include "collider.h"
#include "joystick.h"
#include "canvas.h"
#include "menu.h"





/// @brief The MyScene class is the Scene implementation.
class MyScene : public Scene
{
public:
	/// @brief Constructor
	MyScene();
	/// @brief Destructor
	virtual ~MyScene();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

	bool isPaused;


protected:
	//unsigned int top_layer;
	//std::vector<MyEntity*> layers;
	float angle;

private:
	/// @brief the rotating square in the middle of the screen
	BeyBlade* beyBlade;
	BeyBlade* beyBlade1;
	Controller* controller1;
	Controller* controller2;
	Canvas* score;
	Menu* menu;
	
	
	int p1Score;
	int p2Score;


	/// @brief a Timer to rotate the color every n seconds
	Timer t;
};

#endif /* SCENE00_H */
