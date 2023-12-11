// joystick.h

#ifndef JOYSTICK_H
#define JOYSTICK_H

#include <rt2d/entity.h>

class JoyStick: public Entity
{
public:
	JoyStick();
	virtual ~JoyStick();

	virtual void update(float deltaTime);
private:
	/* add your private declarations */
};

#endif /* JOYSTICK_H */
