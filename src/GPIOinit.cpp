#include <wiringPi.h>
#include <stdio.h>
/*
Da beim Raspberry pi nicht alle GPIO Pins default auf output sind sondern einige
auf input habe ich diese Methode geschrieben die sicher stellt das die Pins die
ich verwende alle auf output sind.
*/
void initPorts()
{
	int GPIO_Port[] = {
		0,	//
		1,	//
		2,	//
		3	//
	};

	for(int i = 0; i < 4; i++)
	{
		pinMode(GPIO_Port[i], OUTPUT); //setzt den Pin auf output
		printf("\033[0;32m[INFO]:\033[0m GPIO port %d set to output\n", GPIO_Port[i]);
		if(digitalRead(GPIO_Port[i]) == 1){ //Kurzer check ob der pin auf HIGH steht
			digitalWrite(GPIO_Port[i], LOW); // Wenn auf HIGH, dann auf LOW setzen
			printf("\033[0;32m[INFO]:\033[0m GPIO port %d set to LOW\n", GPIO_Port[i]);
		}else if (digitalRead(GPIO_Port[i]) == 0){ // Wenn nicht, nichts weiter machen
			printf("\033[0;32m[INFO]:\033[0m GPIO port %d already LOW\n", GPIO_Port[i]);
		}else{ // Einfach nur falls es ein Gehler gibt und der Status eines Pins nicht ermittelt werden kann
			printf("\033[0;31m[ERROR]:\033[0m can't define state of GPIO port %d", GPIO_Port[i]);
		}
		delay(200);
	}
}