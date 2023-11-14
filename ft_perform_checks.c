#include "ft_pipex.h"

int check_fd(int fd) {
    if (fd == -1) {
        perror("[ Ошибка при открытии файла ]");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int check_child_dup2(int fd, int *pipe_fd) {
    if (dup2(fd, STDIN_FILENO) == -1 || dup2(pipe_fd[1], STDOUT_FILENO) == -1) {
        perror("[ Dup2 - Дочерний процесс ]");
        close(fd);
        close(pipe_fd[1]);
        return EXIT_FAILURE;
    }
    close(fd);
    close(pipe_fd[1]);
    return EXIT_SUCCESS;
}

int check_parent_dup2(int fd, int *pipe_fd) {
    if (dup2(pipe_fd[0], STDIN_FILENO) == -1 || dup2(fd, STDOUT_FILENO) == -1) {
        perror("[ Dup2 - Родительский процесс ]");
        close(fd);
        close(pipe_fd[0]);
        return EXIT_FAILURE;
    }
    close(fd);
    close(pipe_fd[0]);
    return EXIT_SUCCESS;
}
