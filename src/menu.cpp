#include <stdio.h>

/*
Simple sache, das ding hier printet das Menü. Und es ist farbig! 
*/
void menu(){
	printf("\033[1;30m#######################################################\033[0m\n");
	printf("\033[1;30m#\033[0m                                                     \033[1;30m#\033[0m\n");
	printf("\033[1;30m#\033[0m                    Menu:                            \033[1;30m#\033[0m\n");
	printf("\033[1;30m#\033[0m                                                     \033[1;30m#\033[0m\n");
	printf("\033[1;30m#\033[0m   forward = 1                                       \033[1;30m#\033[0m\n");
	printf("\033[1;30m#\033[0m   left = 2                                          \033[1;30m#\033[0m\n");
	printf("\033[1;30m#\033[0m   right = 3                                         \033[1;30m#\033[0m\n");
	printf("\033[1;30m#\033[0m   backward = 4                                      \033[1;30m#\033[0m\n");
	printf("\033[1;30m#\033[0m   Clear console = 5                                 \033[1;30m#\033[0m\n");
	printf("\033[1;30m#\033[0m   Exit = 6                                          \033[1;30m#\033[0m\n");
	printf("\033[1;30m#\033[0m                                                     \033[1;30m#\033[0m\n");
	printf("\033[1;30m#######################################################\033[0m\n");
}