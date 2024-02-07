#include <sys/utsname.h>
#include <sys/types.h>
#include "pwd.h"
#include <stdio.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>


void exit_on_err(char *txt);

void get_user_data();

char *full_name;
char *login;
char *shell;


int main(int argc, char *argv[]) {
    char computer[255];
    struct utsname uts;

    if (gethostname(computer, 255) != 0 || uname(&uts) < 0) {
        exit_on_err("could not get computer info");
    }

    get_user_data();

    printf("Hello, %s\n", full_name);

    printf("Computer %s\n", computer);
    printf("Machine: %s\n", uts.machine);
    printf("Node Name: %s\n", uts.nodename);
    printf("Release: %s\n", uts.release);
    printf("Sys Name: %s\n", uts.sysname);
    printf("Version: %s\n", uts.version);


    return 0;
}

void exit_on_err(char *txt) {
    int errno_c = errno;
    char *err = strerror(errno_c);
    fprintf(stderr, "%s - %s\n", txt, err);
    exit(1);
}

void get_user_data() {
    uid_t user_id = getuid();
    struct passwd *pwd = getpwuid(user_id);

    if (pwd == NULL) exit_on_err("could not get user data");

    full_name = pwd->pw_gecos;
    shell = pwd->pw_shell;
    login = pwd->pw_name;
}

