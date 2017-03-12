//
// Created by Rodion Volovik on 2/18/17.
//
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>

#define BUF_SIZE 1000000

int    ft_validator(char *buf)
{
    int		len;
    int		count;

    len = 0;
    count = 0;
    while (buf[len] != '\n')
        len++;
    while (buf)
    {
        if (*buf != '\n' && *buf != '\0' && (*buf == 'X' || *buf == '.'))
            count++;
        else if (*buf == '\n' || *buf == '\0')
        {
            if (count != len)
                return (0);
            count = 0;
        }
        buf++;
        if (*buf == '\0')
            return (1);
    }
    return (1);
}

void    ft_put_island(char *buf, int len, int index)
{
    if (*buf == 'X')
    {
        *buf = index + '0';
        if (buf + len + 1 && *(buf + len + 1) == 'X')
            ft_put_island(buf + len + 1, len, index);
        if (buf - 1 && *(buf - 1) == 'X')
            ft_put_island(buf - 1, len, index);
        if (buf + 1 && *(buf + 1) == 'X')
            ft_put_island(buf + 1, len, index);
        if (buf - len - 1 && *(buf - len - 1) == 'X')
            ft_put_island(buf - len - 1, len, index);
    }
}

int    ft_count_island(char *buf)
{
    int     len;
	int		index;
    char    *str;

	len = 0;
	index = 0;
    str = buf;
    if (!ft_validator(buf))
        return (0);
    while (buf[len] != '\n')
        len++;
    while (*buf != '\0')
    {
        if (*buf == 'X')
        {
            ft_put_island(buf, len, index);
            index++;
        }
        buf++;
    }
    while (*str != '\0')
        write(1, str++, 1);
    return (1);
}

int     main(int argc, char **argv)
{
	int		fd;
	int		ret;
    char	buf[BUF_SIZE + 1];

    if (argc == 2)
    {
        fd = open(argv[1], O_RDONLY);
        ret = read(fd, buf, BUF_SIZE);
		buf[ret] = '\0';
        if (!ft_count_island(buf))
        {
            write(1, "\n", 1);
            return (0);
        }
        close(fd);
    }
    else
        write(1, "\n", 1);
    return (0);
}
