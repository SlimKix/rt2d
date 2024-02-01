// button.cpp

#include "button.h"

Button::Button():Entity()
{
	this->addSprite("assets/button.tga");
	this->sprite()->color = BLUE;
	text = new Text();
	this->addChild(text);
}

Button::~Button()
{

}

void Button::update(float deltatime) 
{
	
}