// canvas.cpp

#include "canvas.h"

Canvas::Canvas() : Entity()
{
	score1 = new Text();
	this->addChild(score1);
	score1->message("0");


	score2 = new Text();
	this->addChild(score2);
	score2->message("0");
	/*score2 = new Text();
	this->addChild(score2);
	score1->message("0");
	score1->position.x = SWIDTH / 2 + 100;
	score1->position.y += 30;

	this->addSprite("assets/square.tga");
	this->sprite()->pivot = Point2(0, 0);*/

}

Canvas::~Canvas()
{

}

void Canvas::update(float deltaTime) 
{

}
