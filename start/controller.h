// controller.h

#ifndef CONTROLLER_H
#define CONTROLLER_H

#include <rt2d/entity.h>
#include "joystick.h"
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#include <glm/gtx/norm.hpp>
#include <rt2d/vectorx.h>
#include "beyblade.h"
#include "collider.h"


class Controller: public Entity
{


public:
	Controller(KeyCode upKey, KeyCode leftKey, KeyCode downKey, KeyCode rightKey);
	virtual ~Controller();

	bool increaseRotation;

	float angle;
	float joySpeed;



	
	virtual void update(float deltaTime);

	void SetBeyBlade(BeyBlade* bb);

private:
	float acceleration;

	/* add your private declarations */
	Controller* controller;
	JoyStick* joyStick;
	BeyBlade* beyBlade;

	KeyCode upKey_;
	KeyCode leftKey_;
	KeyCode downKey_;
	KeyCode rightKey_;
};

#endif /* CONTROLLER_H */
