#ifndef PIPEX_H
#define PIPEX_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *find_cmd_in_env(const char *cmd, char **envp);

#endif
