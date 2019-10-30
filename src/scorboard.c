/*
** EPITECH PROJECT, 2018
** MUL_my_defender_2018
** File description:
** scoreboard function
*/

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include "get_next_line.h"
#include "game.h"

int my_strlen(char *str)
{
    int count = 0;

    if (str == NULL)
        return (0);
    while (str[count] != '\0') {
        count = count + 1;
    }
    return (count);
}

int create_scorboard(void)
{
    int new_fd = open("scorboard.txt", O_CREAT, S_IRWXU);

    return (new_fd);
}

char **scorboard_obtain(void)
{
    int fd = open("scorboard.txt", O_RDONLY);
    char **tab = malloc(sizeof(char *) * (12));
    int count = 0;

    if (fd == -1) {
        fd = create_scorboard();
    } else {
        while ((tab[count] = get_next_line(fd)) != NULL) {
            count = count + 1;
        }
    }
    close(fd);
    return (tab);
}

int add_score(char *player, char *score)
{
    int fd = open("scorboard.txt", O_CREAT | O_WRONLY | O_APPEND, S_IRUSR | S_IWUSR);
    char *temp = my_str_c_dup(player, "...");

    temp = my_str_c_dup(temp, score);
    temp = my_str_c_dup(temp, "\n");
    if (fd == -1)
        return (84);
    while (get_next_line(fd) != NULL);
    if (write(fd, temp, my_strlen(temp)) == -1)
        return (-1);
    free(temp);
    return (0);
}

