// menu.h

#ifndef MENU_H
#define MENU_H

#include <entity.h>
#include <text.h>
#include "button.h"

class Menu: public Entity
{
public:
	Menu();
	virtual ~Menu();
	virtual void update(float deltatime);

	Button* SButton;
	Button* OButton;
	Button* EButton;

private:
	/* add your private declarations */
};

#endif /* MENU_H */
