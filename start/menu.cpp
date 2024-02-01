// menu.cpp

#include "menu.h"

Menu::Menu():Entity()
{
	this->addSprite("assets/menuBg.tga");
	this->sprite()->pivot = Point2(-0.1, 0);
	//this->scale = Vector2(1,25, 1);
	
	SButton = new Button();
	this->addChild(SButton); 
	//SButton->scale = Vector2(1.0f, 0.25f);
	SButton->position = Vector2(SWIDTH/2 - 128, SHEIGHT / 5);
	SButton->text->message("Start", BLUE);
	


	OButton = new Button();
	this->addChild(OButton);
	//OButton->scale = Vector2(1.0f, 0.25f);
	OButton->position = Vector2(SWIDTH / 2 - 128, SHEIGHT / 3);
	OButton->text->message("Exit", BLUE);






}

Menu::~Menu()
{

}

void Menu::update(float deltatime) 
{

}
