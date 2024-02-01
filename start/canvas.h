// canvas.h

#ifndef CANVAS_H
#define CANVAS_H

#include <canvas.h>
#include <text.h>




class Canvas: public Entity
{
public:
	Canvas();
	virtual ~Canvas();
	virtual void update(float deltaTime);
    Text* score1;
	Text* score2;
private:
	/* add your private declarations */
	
};

#endif /* CANVAS_H */
