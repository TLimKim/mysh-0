#include <unistd.h>
#include <stdio.h>
#include "commands.h"
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

int do_cd(int argc, char** argv) {

  if (!validate_cd_argv(argc, argv))
    return -1;
  else if (chdir(argv[1]))
      return 1;
  return 0;
}

int do_pwd(int argc, char** argv) {
  if (!validate_pwd_argv(argc, argv))
    return -1;

  char bufpwd[255];

  getcwd(bufpwd, 254);
  printf("%s \n", bufpwd);

  return 0;
}

int validate_cd_argv(int argc, char** argv) {

    if (!(strcmp(argv[0], "cd")) && argc == 2) {
    /*
	int n1 = access(argv[1], F_OK);
	int n2 = access(argv[1], R_OK);

	printf("n1: %d, n2: %d ", n1, n2);

	if (n1 == 0 && n2 == 0) {
	    printf("n1: %d, n2: %d ", n1, n2);
	    struct stat str;
	    stat(argv[1], &str);
	    if (S_ISDIR(str.st_mode)) {
		return 1;
	    }
	}*/
	return 1;
    }
    else
	return 0;
}

int validate_pwd_argv(int argc, char** argv) {

    if (strcmp(*argv, "pwd") == 0 && argc == 1){
	return 1;
    }
    else if (strcmp(*argv, "pwd") != 0) {

	return 0;
    }
    else if (strcmp(argv[0], "pwd") == 0 && argv[1] != '\0') {
	return 0;
    }
}
