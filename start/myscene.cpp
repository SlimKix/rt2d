/**
 * This class describes MyScene behavior.
 *
 * Copyright 2015 Your Name <you@yourhost.com>
 */

#include <fstream>
#include <sstream>
#include <string>
#include "myscene.h"
#include <cmath>



MyScene::MyScene() : Scene()
{



	/*this->addSprite("assets/bg1.tga");
	this->sprite()->pivot = Point2(0,0);*/

	// start the timer.
	t.start();
	controller1 = new Controller(KeyCode::Up, KeyCode::Left, KeyCode::Down, KeyCode::Right, RED);
	
	this->addChild(controller1);
	controller1->position = Point2(SWIDTH/4*3, SHEIGHT/4*3);

	controller2 = new Controller(KeyCode::W, KeyCode::A, KeyCode::S, KeyCode::D, BLUE);

	this->addChild(controller2);
	controller2->position = Point2(SWIDTH / 4, SHEIGHT / 4 * 3);

	isPaused = false;

	/*score1 = new Text();
	this->addChild(score1);
	score1->position.x = SWIDTH / 2;
	score1->position.y += 30;
	score1->position.z -= 30;

	score1->message("0");*/
	
	//initialSpeed = 300;
	//speedx = initialSpeed;
	//speedy = initialSpeed;
	// 
	// This was added since the child pos was 0
	//controller1->getChild(0)->position = controller1->position;
	
	beyBlade = new BeyBlade(KeyCode::Up, KeyCode::Left, KeyCode::Down, KeyCode::Right);
	beyBlade->position = Point2(SWIDTH / 3 * 2.5, SHEIGHT / 2);

	
	controller1->SetBeyBlade(beyBlade);
	beyBlade->addSprite("assets/beyblade2.tga");

	beyBlade1 = new BeyBlade(KeyCode::W, KeyCode::A, KeyCode::S, KeyCode::D);
	beyBlade1->position = Point2(SWIDTH / 3, SHEIGHT / 2 - 100);
	
	controller2->SetBeyBlade(beyBlade1);
	beyBlade1->addSprite("assets/beyblade3.tga");
	Vector2 diff;

	score = new Canvas();
	this->addChild(score);
	score->score1->position.x = SWIDTH / 2 +50;
	score->score1->position.y += 30;
	p1Score = 0;
	score->score1->message(std::to_string(p1Score));
	score->score2->position.x = SWIDTH / 2-50;
	score->score2->position.y += 30;
	p2Score = 0;
	score->score2->message(std::to_string(p2Score));
	//angle = static_cast<float>(rand()) / RAND_MAX * 2 * PI;

	menu = new Menu();
	this->addChild(menu);

}	



MyScene::~MyScene()
{
	// deconstruct and delete the Tree
	this->removeChild(beyBlade);
	this->removeChild(beyBlade1);
	this->removeChild(controller1);
	this->removeChild(controller2);
	this->removeChild(menu);

	// delete myentity from the heap (there was a 'new' in the constructor)
	delete beyBlade;
	delete beyBlade1;
	delete controller1;
	delete controller2;
	delete menu;
}

void MyScene::update(float deltaTime)
{
	int mousex = input()->getMouseX();
	int mousey = input()->getMouseY();
	Point2 mouse = Point2(mousex, mousey);

	Vector2 difference = mouse - menu->getChild(0)->position;

	float length = difference.getLength();

	if (input()->getMouseDown(0))
	{
		if (length < 64)
		{
			isPaused = false;
			std::cout << "start button clicked" << "-" << isPaused << std::endl;
			if (menu) {
				
				this->addChild(beyBlade);
				this->addChild(beyBlade1);
				this->removeChild(menu);
			}
		}
	}
	
//	std::cout << isPaused << ": " << mouse << " - " << length << std::endl;
	
		Vector2	diff = beyBlade->position - beyBlade1->position;

		float distance = diff.getLength();
		Vector2 bsize = beyBlade->sprite()->size;

		if (distance < bsize.y) 
		{
			Vector2 impulse = beyBlade1->velocity - beyBlade->velocity;

			beyBlade->velocity += impulse;
			beyBlade1->velocity -= impulse;

			beyBlade->rotationSpeed -= 0.1;
			beyBlade1->rotationSpeed -= 0.1;

			std::cout << "Collision occurred, velocities transferred." << std::endl;
		}

		if (beyBlade->rotationSpeed <= 0)
		{
			p2Score += 1;
			score->score2->message(std::to_string(p2Score));
			beyBlade->rotationSpeed = 100.0f;
			beyBlade1->rotationSpeed = 100.0f;
			//isPaused = true;
		}

		if (beyBlade1->rotationSpeed <= 0)
		{
			p1Score += 1;
			score->score1->message(std::to_string(p1Score));
			beyBlade->rotationSpeed = beyBlade->initialRotationSpeed;
			beyBlade1->rotationSpeed = beyBlade->initialRotationSpeed;
			//isPaused = true;
		}

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
	
