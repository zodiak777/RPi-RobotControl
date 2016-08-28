#ifndef MOVEMENT_H
#define MOVEMENT_H

typedef enum{
	FORWARD = 1,
	LEFT,
	RIGHT,
	BACKWARD
} rDirection;

extern rDirection rD;

void roboMove(int range, rDirection d);
void roboTurn(int angle, rDirection d);

#endif