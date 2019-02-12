/*
   _____   ____     ___           ___    ____    ___   ____ 
  / ___/  / __ \   /   |         |__ \  / __ \  <  /  / __ \
  \__ \  / / / /  / /| |         __/ / / / / /  / /  / /_/ /
 ___/ / / /_/ /  / ___ |        / __/ / /_/ /  / /   \__, / 
/____/  \____/  /_/  |_|       /____/ \____/  /_/   /____/  
Instituto Tecnológico de Costa Rica
Maestría en Computación
Sistemas Operativos Avanzados
Prof: Francisco Torres Rojas, PHD.
Integrantes: Fabiola Espinoza
			 Nathalia Gonzalez
			 Manuel Figueroa 
			 José Somarribas
			 Esteban Leandro
Tarea Corta 1: Rastreador de System Calls                                                            
*/

#include <stdio.h>
#include <unistd.h>
#include <conio.h>

int main(int argc, char *argv[])
{
	printf("Hello World");
	int opt;
	while ((opt = getopt(argc, argv, "vV::")))
	{
		switch (opt)
		{
		case 'v':
			printf("Selected option: v");
			break;
		case 'V':
			while (!kbhit())
			{
				printf("You haven't pressed a key.\n");
			}
			printf("Selected option: V");
			break;
		default:
			printf("Default case");
			break;
		}

		if (opt == -1)
		{
			break; // Exit while loop
		}
	}
}