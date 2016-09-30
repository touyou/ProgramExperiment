/**
 * https://github.com/brenns10/lsh/blob/master/src/main.c
 * の発展
 * my shell
 */
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// shell commands :
int msh_cd(char **args);
int msh_help(char **args);
int msh_exit(char **args);

// list of builtin commands :
char *builtin_str[] = {
    "cd",
    "help",
    "exit"
};

int (*builtin_func[]) (char **) = {
    &msh_cd,
    &msh_help,
    &msh_exit
};

int msh_num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

// builtin commands implementations :

// change directory
int msh_cd(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "msh: expected argument to \"cd\"\n");
    } else {
        if (chdir(args[1]) != 0) {
            perror("lsh");
        }
    }

    return 1;
}

// print help
int msh_help(char **args) {
    int i;
    return 1;
}
