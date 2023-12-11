#include "controller.h"

float maxSpeed = 300.0f;
Vector2 joyPos;
float maxPos = 150.f;
Vector2 yAccel = Vector2(0, 400.0f);
Vector2 xAccel = Vector2(400.0f, 0);


Controller::Controller() : Entity()
{
	
	Line c1;
	c1.createCircle(50, 18);
	this->addLine(&c1);
	
	joyStick = new JoyStick;
	this->addChild(joyStick);
	joyStick->scale = Point2(1, 1);

}

Controller::~Controller()
{

}

void Controller::update(float deltaTime)
{

    if (yAccel.getLength() > maxSpeed) {
        yAccel = yAccel.getNormalized() * maxSpeed;
    }

    if (xAccel.getLength() > maxSpeed) {
        xAccel = xAccel.getNormalized() * maxSpeed;
    }

    // Handling user input
    if (input()->getKey(KeyCode::Up)) {
        joyStick->position -= yAccel * deltaTime;
    }
    if (input()->getKey(KeyCode::Left)) {
        joyStick->position -= xAccel * deltaTime;
    }
    if (input()->getKey(KeyCode::Down)) {
        joyStick->position += yAccel * deltaTime;
    }
    if (input()->getKey(KeyCode::Right)) {
        joyStick->position += xAccel * deltaTime;
    }

    joyPos = joyStick->position;

    
    // Limit the ball to a square collider

    if (joyPos.y >= maxPos)
    {
        joyStick->position.y = maxPos;
    }
    if (joyPos.y <= -maxPos)
    {
        joyStick->position.y = -maxPos;
    }
    if (joyPos.x >= maxPos)
    {
        joyStick->position.x = maxPos;
    }
    if (joyPos.x <= -maxPos)
    {
        joyStick->position.x = -maxPos;
    }


    // Supposed to increase rotationSpeed while joyStick is within set limits
    Vector2 diff = joyStick->position - Point2(0,0);
    float distance = diff.getLength();

    increaseRotation = false;

    if (distance <= 64)
    {
        increaseRotation = true;
      
    }


    // Ball goes random direction constantly
   angle = static_cast<float>(rand()) / RAND_MAX * 2 * PI;


    joyStick->position.x += 3000 * cos(angle) * deltaTime;
    joyStick->position.y += 3000 * sin(angle) * deltaTime;





    //collider shapes

    //Circle circ1 = Circle(this->position.x, this->position.y, 64);
    //Circle circ2 = Circle(joyStick->position.x, joyStick->position.y, 50);

   
    //if (Collider::circle2circle(circ1, circ2)) {
   //     std::cout << "wtf";
    //}

    


    
  //  std::cout << joyStick->position ;
	
}


	