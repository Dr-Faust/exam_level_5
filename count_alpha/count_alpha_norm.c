#include <unistd.h>

int     ft_end(char *str, int i)
{
    i++;
    while (str[i])
    {
        if (str[i] >= 'a' && str[i] <= 'z')
            return (1);
        i++;
    }
    return (0);
}

void    ft_print(char *str, char c)
{
    int     i;
    int     count;
    char    numb;

    i = 0;
    count = 0;
    while (str[i])
    {
        if (str[i] == c)
        {
            count++;
            str[i] = ' ';
        }
        i++;
    }
    numb = '0' + count;
    write(1, &numb, 1);
    write(1, &c, 1);
}

void    ft_optimize(char *str)
{
    int     i;

    i = 0;
    while (str[i])
    {
        if (str[i] >= 'A' && str[i] <= 'Z')
            str[i] += 32;
        i++;
    }
}

int     main(int argc, char **argv)
{
    char    *str;
    int     i;

    if (argc == 2)
    {
        i = 0;
        str = argv[1];
        ft_optimize(str);
        while (str[i])
        {
            if (str[i] >= 'a' && str[i] <= 'z')
            {
                ft_print(str, str[i]);
                if (ft_end(str, i) != 0)
                    write(1, ", ", 2);
            }
            i++;
        }
    }
    write(1, "\n", 1);
    return (0);
}
