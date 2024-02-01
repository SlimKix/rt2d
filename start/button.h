// button.h

#ifndef BUTTON_H
#define BUTTON_H

#include <entity.h>
#include <text.h>

class Button: public Entity
{
public:
	Button();
	virtual ~Button();
	virtual void update(float deltatime);
	Text* text;

private:
	/* add your private declarations */
};

#endif /* BUTTON_H */
