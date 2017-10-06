#include "utils.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

void mysh_parse_command(const char* command, int *argc, char*** argv)

{
    int i = 0;

    char *temp = (char*)malloc(sizeof(char));
    char *temptok;

    strcpy(temp, command);

    temptok = strtok(temp, " \n\t");

    *argv = (char**)malloc(sizeof(char*)*20);

    if (temptok == NULL) {
	(*argv)[i] = (char*)malloc(sizeof(char)*20);
	strcpy((*argv)[i], "");
	i++;
    } else {
	for (i = 0; temptok != NULL; i++) {
	    
	    (*argv)[i] = (char*)malloc(sizeof(char)*strlen(temptok));
	    
    	    strcpy((*argv)[i], temptok);
	    temptok = strtok(NULL, " \n\t");
	}
    }

    *argc = i;

    free(temp);
}
