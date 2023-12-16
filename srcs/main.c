#include "../includes/ft_pipex.h"

static int create_pipe(int *pipe_fd) {
    if (pipe(pipe_fd) == -1) {
        perror("[ Ошибка при создании канала ]");
        return -1;
    }
    return 0;
}

static pid_t create_process() {
    pid_t pid = fork();
    if (pid == -1) {
        perror("[ Ошибка при вызове fork ]");
        return pid;
    }
    return pid;
}

int main(int argc, char **argv, char **envp) {
    int pipe_fd[2];
    pid_t pid;

    if (argc != 5) {
        perror("[ Ошибка: неверное количество аргументов ]");
        return EXIT_FAILURE;
    }
    if (create_pipe(pipe_fd) == -1)
        exit(EXIT_FAILURE);
    pid = create_process();
    if (pid == -1)
        exit(EXIT_FAILURE);
    else if (pid == 0)
        child_process_handler(pipe_fd, argv, envp);
    else
        parent_process_handler(pipe_fd, argv, envp);
    return EXIT_SUCCESS;
}
