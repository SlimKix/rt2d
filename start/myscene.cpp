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
	controller1 = new Controller(KeyCode::Up, KeyCode::Left, KeyCode::Down, KeyCode::Right);
	
	this->addChild(controller1);
	controller1->position = Point2(SWIDTH/4*3, SHEIGHT/4*3);

	controller2 = new Controller(KeyCode::W, KeyCode::A, KeyCode::S, KeyCode::D);

	this->addChild(controller2);
	controller2->position = Point2(SWIDTH / 4, SHEIGHT / 4 * 3);
	

	
	//initialSpeed = 300;
	//speedx = initialSpeed;
	//speedy = initialSpeed;


	
	// This was added since the child pos was 0
	//controller1->getChild(0)->position = controller1->position;
	


	beyBlade = new BeyBlade();
	beyBlade->position = Point2(SWIDTH / 3 *2.5, SHEIGHT / 2);
	this->addChild(beyBlade);
	controller1->SetBeyBlade(beyBlade);
	beyBlade->sprite()->color = RED;


	beyBlade1 = new BeyBlade();
	beyBlade1->position = Point2(SWIDTH / 3, SHEIGHT / 2);
	this->addChild(beyBlade1);
	controller2->SetBeyBlade(beyBlade1);
	beyBlade1->sprite()->color = BLUE;

	Vector2 diff;

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

	Vector2	diff = beyBlade->position - beyBlade1->position;

	float distance = diff.getLength();
	Vector2 bsize = beyBlade->sprite()->size;

	if (distance < bsize.y / 2) {
		beyBlade->velocity *= -1;
		beyBlade1->velocity *= -1;
		beyBlade->rotationSpeed -= 0.1;
		beyBlade1->rotationSpeed -= 0.1;


	}

	// Supposed to make beybade go in a random direction in the beginning 
	/*beyBlade->position.x += speedx * cos(angle) * deltaTime;
	beyBlade->position.y += speedy * sin(angle) * deltaTime;*/

	// beyBlade becomes smaller while hovering over it

	/*int mousex = input()->getMouseX() + camera()->position.x - SWIDTH / 2;
	int mousey = input()->getMouseY() + camera()->position.y - SHEIGHT / 2;
	Point2 mouse = Point2(mousex, mousey);
	
	Vector2 diff = mouse - beyBlade->position;
	float distance = diff.getLength();

	beyBlade->scale = Vector2(1.0f, 1.0f);
	Vector2 bsize = beyBlade->sprite()->size;

	if (distance < bsize.y/2)
	{
		beyBlade->scale = Vector2(0.5f, 0.5f);
	}*/


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

	//if (controller1->increaseRotation) 
	//{
	//	beyBlade->rotationSpeed += 0.001;
	//}


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