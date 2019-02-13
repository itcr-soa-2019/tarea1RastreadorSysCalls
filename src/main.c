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
#include <ncurses.h>
#include <stdlib.h>


void getSystemCall(int optind, int argc, char *argv[])
{
	nodelay(stdscr, FALSE);
    int i;
	int arraySize = (argc - optind) + 4;
	char *straceArgs[arraySize];
	straceArgs[0] = "strace";
	/**
	 * According to strace's manual page 
	 * http://man7.org/linux/man-pages/man1/strace.1.html
	*/
	straceArgs[1] = "-f";
	straceArgs[2] = "-c";
	int argIndex = 3;
    for (i = optind; i < argc; i++)
    {
	 	straceArgs[argIndex] = argv[i];
		argIndex++;        
    }
	straceArgs[arraySize-1] = NULL;
	execvp("strace", straceArgs);
}

/**
 *  Main method
*/
int main(int argc, char *argv[])
{
	
	int opt;
	extern char *optarg;
	extern int optind;
	extern int optopt;
	extern int opterr;

	initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
	// Process the options 
	while ((opt = getopt(argc, argv, "+v::V::")))
	{
		switch (opt)
		{
		case 'v':
			break;
		case 'V':
				printf("Please press any key to continue\n\n");
				getchar();
			break;
		case '?':
		default:
			/* TODO PRINT HELP*/
			break;
		}

		if (opt == -1)
		{
			break; // Exit while loop
		}
	}
	endwin();	// End curses mode restore stdout formats
	getSystemCall(optind, argc, argv);
	
	exit(0);
}