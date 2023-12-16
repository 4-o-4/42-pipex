#ifndef FT_PIPEX_H
#define FT_PIPEX_H

#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

char *find_cmd_in_env(const char *cmd, char **envp);

int check_fd(int fd);
int check_child_dup2(int fd, int *pipe_fd);
int check_parent_dup2(int fd, int *pipe_fd);

void child_process_handler(int *pipe_fd, char **argv, char **envp);
void parent_process_handler(int *pipe_fd, char **argv, char **envp);

#endif
