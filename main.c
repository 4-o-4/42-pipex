#include "ft_pipex.h"

int main(int argc, char **argv, char **envp) {
    char *path = find_cmd_in_env("grep", envp);
    if (path == NULL)
        return EXIT_FAILURE;
    return EXIT_SUCCESS;
}
