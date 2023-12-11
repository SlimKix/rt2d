/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include <string>
#include "myscene.h"



MyScene::MyScene() : Scene()
{


	// start the timer.
	t.start();
	float newWidth = SWIDTH;
	std::cout << "Player clicks: " << newWidth << std::endl;
	controller1 = new Controller;
	Line c1;
	c1.createCircle(128, 18);
	controller1->addLine(&c1);
	this->addChild(controller1);
	controller1->position = Point2(SWIDTH/4*3, SHEIGHT/4*3);

	

	
	//initialSpeed = 300;
	//speedx = initialSpeed;
	//speedy = initialSpeed;


	
	// This was added since the child pos was 0
	//controller1->getChild(0)->position = controller1->position;
	


	

	

	beyBlade = new BeyBlade();
	beyBlade->position = Point2(SWIDTH / 3 *2.5, SHEIGHT / 2);
	this->addChild(beyBlade);
	//angle = static_cast<float>(rand()) / RAND_MAX * 2 * PI;

}	



MyScene::~MyScene()
{


	// deconstruct and delete the Tree
	this->removeChild(beyBlade);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete beyBlade;
}

void MyScene::update(float deltaTime)
{


	// Supposed to make beyblade go in a random direction in the beginning 
	/*beyBlade->position.x += speedx * cos(angle) * deltaTime;
	beyBlade->position.y += speedy * sin(angle) * deltaTime;*/

	// beyBlade becomes smaller while hovering over it

	int mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	int mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mouse = Point2(mousex, mousey);
	
	Vector2 diff = mouse - beyBlade->position;
	float distance = diff.getLength();

	beyBlade->scale = Vector2(1.0f, 1.0f);
	Vector2 bsize = beyBlade->sprite()->size;

	if (distance < bsize.y/2)
	{
		beyBlade->scale = Vector2(0.5f, 0.5f);
	}

	std::cout <<"Hi" << SWIDTH << SHEIGHT<< "Hi";

	// Beyblade Bounces against walls

	/*if (beyBlade->position.x >= SWIDTH - (bsize.y / 2)) {
		speedx = -initialSpeed;
	}
	if (beyBlade->position.x <= 0 + (bsize.y / 2)) {
		speedx = initialSpeed;
	}
	if (beyBlade->position.y >= SHEIGHT - (bsize.y/2)) {
		speedy = -initialSpeed;
	}
	if (beyBlade->position.y <= 0 + (bsize.y / 2)) {
		speedy = initialSpeed;
	}*/


	// Increases rotation speed of beyblade when ball is inside the circle

	/*int posX = beyBlade->scale.x;
	int posY = beyBlade->scale.y;*/

	if (controller1->increaseRotation) 
	{
		beyBlade->rotationSpeed += 0.001;
	}
	std::cout << beyBlade->rotationSpeed;


//	Vector2 diff2 = c->position - this->position;
	//float distance = diff.getLength();

	//if (distance >= 64)
	//{
	//}
	//beyblade->sprite(size)
	//std::cout <<  mouse << std::endl;


	/*Vector2 diff1 = controller1->getChild(0)->position - controller1->position;
	float distance1 = diff1.getLength();
	std::cout <<"Hello1" << controller1->getChild(0)->position;
	std::cout << "Hello2" << controller1->position;

	
	if (distance1 <= 64)
		{
		beyBlade->rotationSpeed += 0.2;
		std::cout << "Hello World";
		}*/
	
}