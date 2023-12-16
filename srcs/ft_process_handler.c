#include "../includes/ft_pipex.h"

static int execute_cmd(const char *path, char **args) {
    if (execve(path, args, NULL) == -1) {
        perror("[ Ошибка при выполнении execve ]");
        return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

static void execute_command(char *cmd, char **envp) {
    char **args = ft_split(cmd, ' ');
    if (args == NULL)
        exit(EXIT_FAILURE);
    char *path = find_cmd_in_env(args[0], envp);
    if (path == NULL)
        exit(EXIT_FAILURE);
    if (execute_cmd(path, args))
        exit(EXIT_FAILURE);
}

void parent_process_handler(int *pipe_fd, char **argv, char **envp) {
    wait(NULL);
    close(pipe_fd[1]);
    int fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (check_fd(fd))
        exit(EXIT_FAILURE);
    if (check_parent_dup2(fd, pipe_fd))
        exit(EXIT_FAILURE);
    execute_command(argv[3], envp);
    exit(EXIT_SUCCESS);
}

void child_process_handler(int *pipe_fd, char **argv, char **envp) {
    close(pipe_fd[0]);
    int fd = open(argv[1], O_RDONLY);
    if (check_fd(fd))
        exit(EXIT_FAILURE);
    if (check_child_dup2(fd, pipe_fd))
        exit(EXIT_FAILURE);
    execute_command(argv[2], envp);
    exit(EXIT_SUCCESS);
}
