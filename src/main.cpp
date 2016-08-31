#include "movement.h"
#include "menu.h"
#include "GPIOinit.h"
#include <wiringPi.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>

using namespace std;

/*
Ich hab ums verrecken keinen zufriedenstellenden Weg gefunden die Länge eines
int Arrays zu ermitteln, also habe ich mir kurzehand eine eigene Methode
geschrieben.
*/
int size(int Array[]){
	int i = 0;
	while( Array[i] != '\0')
		i++;
	
	return i;
}

int main(){
	// Setup für die GPIO pims, damit sie angesprochen werden können
	if(wiringPiSetup() == -1)
		return 1;

	system("clear"); // Damit die einträge, die vor dem Programmstart in der console (von z.b. putty) waren, verschwinden
	initPorts(); // GPIO Pins werden hier auf output gesetzt.
	
	// Eine simple while Schleife die das Programm am laufen hällt bis ich es beende.
	bool running = true;
	while(running)
	{
		menu();
		
		/*
		Auswahl welche option(en) durchgeführt werden sollen.
		Mehrere optionen sind möglich (1234 für vor, links, rechts, zurück)
		*/
		printf("Enter key[s]: ");
		char* sInput;
		cin >> sInput;
		printf("\n"); // Es ist einfach hässlich dierekt nach dem "Enter key[s]: " die erste ausgabe zu haben!
		
		// Wandelt die char* Variable vom input in int* Zahlen um.
		int iInput[strlen(sInput)];
		for(int i = 0; i < strlen(sInput); i++){
			iInput[i] = sInput[i] - '0';
		}
		
		// Geht jede, vom input angegebene, zahl durch um das entsprechende auszuführen.
		for(int i = 0; i < size(iInput); i++){
			switch(iInput[i]){
				case 1:
					roboMove(900, FORWARD); //bewegt den robo 900 mm vor
					break;
				case 2:
					roboTurn(90, LEFT); //bewegt den robo 90° nach links
					break;
				case 3:
					roboTurn(90, RIGHT); //bewegt den robo 90° nach rechts
					break;
				case 4:
					roboMove(900, BACKWARD); //bewegt den robo 900 mm zurück
					break;
				case 5:
					system("clear");
					printf("\033[2J");
					break;
				case 6:
					running = false;
					break;
				default:
					printf("\033[0;31m[ERROR]:\033[0m %d unknown option\n", iInput[i]);
			}
		}
		
		// Säubert die Konsole, ist sonst echt unschön
		system("clear");
		printf("\033[2J");
	}
}
