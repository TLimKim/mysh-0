#include <unistd.h>
#include <stdio.h>
#include "commands.h"
#include <string.h>

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
