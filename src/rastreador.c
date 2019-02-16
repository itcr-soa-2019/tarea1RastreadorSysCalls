/* 
   ____    ____     ___           ___    ____    ___   ____
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
#include <sys/types.h>
#include <unistd.h>


/**
 * @brief  Call the strace utility command to get the information about the system calls. 
 * @param  optind: The index of the first non argument option
 * @param  argc: The amount of arguments in the argv array
 * @param  *argv[]: The current argv array 
 * @retval None
 */
void getSystemCall(int optind, int argc, char *argv[])
{
	endwin();	// End curses mode restore stdout formats
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
 * @brief  Print in stdout the help information of this command. 
 * @retval None
 */
void usage() {
	endwin();	// End curses mode restore stdout formats
	nodelay(stdscr, FALSE);
	printf("*************************************************************************\n");
	printf("* usage: rastrador [-vVh] PROG [ARGS]                                   *\n");
	printf("* Options:                                                              *\n");
	printf("*    -v Shows a message every time it detects a system call.            *\n");
	printf("*    -V dentical to -v but it makes a pause until the user press a key. *\n");
	printf("*************************************************************************\n");
}

/**
 *  Main method
*/
int main(int argc, char *argv[])
{
	if (argv[1] == NULL) { // no args present when calling rastreador
    	usage();
    	exit(0);
    }

    // used by getopt function
	int opt;
	extern char *optarg; // if opt takes a value, it is stored in this pointer.
	extern int optind; // is the index of the next element to be processed in the args array argv
	extern int optopt; // if an unrecognized option is used, then it is stored in this var.
	extern int opterr; // If the value is set to nonzero then getopt prints an error msg to stdout

	// ncurses initialization
	initscr();
    cbreak();
    noecho();
    nodelay(stdscr, TRUE);
	int shouldRun = 0; // Indicates if getSystemCalls should be called.
	// Process the options
	while ((opt = getopt(argc, argv, "+v::V::h::"))!= -1)
	{
		switch (opt)
		{
		case 'v':
            printf("v option.");
			break;
		case 'V':
            printf("V option. Please press any key to continue\n");
			getchar();
			break;
		case 'h':
		case '?':
           	usage();
			shouldRun = -1;
			break;
		default:
			// Do nothing
			break;
		}
	}

	if(shouldRun > -1){
		// Get the system calls information
		getSystemCall(optind, argc, argv);
	}

	exit(0);
}
