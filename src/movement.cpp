#include <wiringPi.h>
#include <stdio.h>
#include "movement.h"

/*
Folgende zwei Methoden (roboMove und roboTurn) sind für die Bewegung zuständig. sagt
aus auf welchem GPIO pin welches signal ausgegeben werden soll HIGH für 1 bzw. an
und LOW für 0 bzw. aus.
Parameter bei roboMove sind 1. range in Millimeter
und 2. Richtung (Siehe enum rDirection)
Parameter bei roboTurn sind 1. angle in Grad
und 2. Richtung (Siehe enum rDirection)
*/
void roboMove(int range, rDirection d){
	int r = range*1.111111111111111;
	switch(d){
		case FORWARD:
			digitalWrite(1, HIGH);
			digitalWrite(3, HIGH);
			printf("\033[0;32m[INFO]:\033[0m GPIO port's 1 and 3 set to HIGH, %d mm wide\n", range);
			printf("\033[0;32m[INFO]:\033[0m Move forward\n");
			delay(r);
			digitalWrite(1, LOW);
			digitalWrite(3, LOW);
			printf("\033[0;32m[INFO]:\033[0m GPIO port's 1 and 3 set to LOW\n");
			printf("\033[0;32m[INFO]:\033[0m Move stopped\n");
		break;
		case BACKWARD:
			digitalWrite(0, HIGH);
			digitalWrite(2, HIGH);
			printf("\033[0;32m[INFO]:\033[0m GPIO port's 0 and 2 set to HIGH, %d mm wide\n", range);
			printf("\033[0;32m[INFO]:\033[0m Move backward\n");
			delay(r);
			digitalWrite(0, LOW);
			digitalWrite(2, LOW);
			printf("\033[0;32m[INFO]:\033[0m GPIO port's 0 and 2 set to LOW\n");
			printf("\033[0;32m[INFO]:\033[0m Move stopped\n");
		break;
		default:
			printf("\033[0;31m[ERROR]:\033[0m Wrong direction\n");
	}
}
void roboTurn(int angle, rDirection d){
	int a = angle*11.11111111111111;
	switch(d){
		case LEFT:
			digitalWrite(1, HIGH);
			digitalWrite(2, HIGH);
			printf("\033[0;32m[INFO]:\033[0m GPIO port's 1 and 2 set to HIGH, %d degree wide\n", angle);
			printf("\033[0;32m[INFO]:\033[0m Move left\n");
			delay(a);
			digitalWrite(1, LOW);
			digitalWrite(2, LOW);
			printf("\033[0;32m[INFO]:\033[0m GPIO port's 1 and 2 set to LOW\n");
			printf("\033[0;32m[INFO]:\033[0m Move stopped\n");
		break;
		case RIGHT:
			digitalWrite(0, HIGH);
			digitalWrite(3, HIGH);
			printf("\033[0;32m[INFO]:\033[0m GPIO port's 0 and 3 set to HIGH, %d degree wide\n", angle);
			printf("\033[0;32m[INFO]:\033[0m Move right\n");
			delay(a);
			digitalWrite(0, LOW);
			digitalWrite(3, LOW);
			printf("\033[0;32m[INFO]:\033[0m GPIO port's 0 and 3 set to LOW\n");
			printf("\033[0;32m[INFO]:\033[0m Move stopped\n");
		break;
		default:
			printf("\033[0;31m[ERROR]:\033[0m Wrong direction\n");
	}
}