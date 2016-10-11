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
int msh_mkdir(char **args);
int msh_ls(char **args);
int msh_help(char **args);
int msh_exit(char **args);

// list of builtin commands :
char *builtin_str[] = {
    "cd",
    "mkdir",
    "ls",
    "help",
    "exit"
};

int (*builtin_func[]) (char **) = {
    &msh_cd,
    &msh_mkdir,
    &msh_ls,
    &msh_help,
    &msh_exit
};

int msh_num_builtins() {
    return sizeof(builtin_str) / sizeof(char *);
}

// builtin commands implementations :

// look up
int msh_ls(char **args) {
    if (args[1] == NULL) {
        system("ls -al");
    } else {
        char buff[1024];
        sprintf(buff, "ls -al %s", args[1]);
        system(buff);
    }

    return 1;
}

// make directory
int msh_mkdir(char **args) {
    if (args[1] == NULL) {
        fprintf(stderr, "msh: expected argument to \"mkdir\"\n");
    } else {
        char buff[1024];
        sprintf(buff, "mkdir %s", args[1]);
        system(buff);
    }

    return 1;
}

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
    printf("touyou's MSH");
    return 1;
}

// exit
int msh_exit(char **args) {
    return 0;
}

// launch
int msh_launch(char **args) {
    pid_t pid;
    int status;

    pid = fork();
    if (pid == 0) {
        if (execvp(args[0], args) == -1) {
            perror("msh");
        }
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        perror("msh");
    } else {
        do {
            waitpid(pid, &status, WUNTRACED);
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }

    return 1;
}

int msh_execute(char **args) {
    int i;

    if (args[0] == NULL) {
        return 1;
    }
    for (i = 0; i < msh_num_builtins(); i++) {
        if (strcmp(args[0], builtin_str[i]) == 0) {
            return (*builtin_func[i])(args);
        }
    }

    return msh_launch(args);
}

#define MSH_RL_BUFSIZE 1024

char *msh_read_line(void) {
    int bufsize = MSH_RL_BUFSIZE;
    int position = 0;
    char *buffer = malloc(sizeof(char) * bufsize);
    int c;

    if (!buffer) {
        fprintf(stderr, "msh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    while (1) {
        c = getchar();

        if (c == EOF || c == '\n') {
            buffer[position] = '\0';
            return buffer;
        } else {
            buffer[position] = c;
        }
        position++;

        if (position >= bufsize) {
            bufsize += MSH_RL_BUFSIZE;
            buffer = realloc(buffer, bufsize);
            if (!buffer) {
                fprintf(stderr, "msh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }
    }
}

#define MSH_TOK_BUFSIZE 64
#define MSH_TOK_DELIM " \t\r\n\a"

char **msh_split_line(char *line) {
    int bufsize = MSH_TOK_BUFSIZE, position = 0;
    char **tokens = malloc(bufsize * sizeof(char*));
    char *token, **tokens_backup;

    if (!tokens) {
        fprintf(stderr, "msh: allocation error\n");
        exit(EXIT_FAILURE);
    }

    token = strtok(line, MSH_TOK_DELIM);
    while (token != NULL) {
        tokens[position] = token;
        position++;

        if (position >= bufsize) {
            bufsize += MSH_TOK_BUFSIZE;
            tokens_backup = tokens;
            tokens = realloc(tokens, bufsize * sizeof(char*));
            if (!tokens) {
                free(tokens_backup);
                fprintf(stderr, "msh: allocation error\n");
                exit(EXIT_FAILURE);
            }
        }

        token = strtok(NULL, MSH_TOK_DELIM);
    }
    tokens[position] = NULL;
    return tokens;
}

void msh_loop(void) {
    char *line;
    char **args;
    int status;

    do {
        printf("$ ");
        line = msh_read_line();
        args = msh_split_line(line);
        status = msh_execute(args);

        free(line);
        free(args);
    } while (status);
}

int main(int argc, char **argv) {
    msh_loop();

    return EXIT_SUCCESS;
}
