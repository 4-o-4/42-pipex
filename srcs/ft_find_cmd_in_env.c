#include "../includes/ft_pipex.h"

static char *get_env_var(char *name, char **envp) {
    if (name == NULL || envp == NULL)
        return NULL;
    size_t name_len = strlen(name);
    for (int i = 0; envp[i] != NULL; i++)
        if (strncmp(envp[i], name, name_len) == 0 && envp[i][name_len] == '=')
            return envp[i] + name_len + 1; // Возвращаем значение после '='
    return NULL;
}

static char *verify_file_existence(char *path) {
    if (access(path, F_OK) == 0)
        return path;
    free(path);
    return NULL;
}

static char *find_cmd_in_path(const char *path, const char *cmd, size_t length_path) {
    size_t length = length_path + 1 + strlen(cmd);
    char *directory = (char *) malloc(length + 1);
    if (directory == NULL) {
        perror("[ Ошибка при выделении памяти ]");
        return NULL;
    }
    strncpy(directory, path, length_path);
    directory[length_path] = '/';
    directory[length_path + 1] = '\0';
    return verify_file_existence(strcat(directory, cmd));
}

char *find_cmd_in_env(const char *cmd, char **envp) {
    const char *path;
    const char *end;
    char *found_path;

    path = get_env_var("PATH", envp);
    if (path == NULL) {
        perror("[ Переменная PATH не найдена ]");
        return NULL;
    }
    while ((end = strchr(path, ':')) != NULL) {
        found_path = find_cmd_in_path(path, cmd, end - path);
        if (found_path == NULL)
            path = end + 1;
        else
            return found_path;
    }
    found_path = find_cmd_in_path(path, cmd, strlen(path));
    if (found_path == NULL)
        perror("[ Ошибка: команда не найдена ]");
    return found_path;
}
