#include <unistd.h>

void    ft_print(unsigned const char *tab, size_t *i, size_t j, size_t size)
{
    const char *base;
    int         k;

    base = "0123456789abcdef";
    (*i) = 0;
    while ((*i) < 16 && (*i) + j < size)
    {
        k = tab[(*i) + j];
        write(1, &base[(k >> 4) % 16], 1);
        write(1, &base[k % 16], 1);
        if ((*i) % 2)
            write(1, " ", 1);
        (*i)++;
    }
    while ((*i) < 16)
    {
        write(1, "  ", 2);
        if ((*i) % 2)
            write(1, " ", 1);
        (*i)++;
    }
}

void    print_memory(const void *addr, size_t size)
{
    unsigned const char *tab;
    size_t              i;
    size_t              j;
    int                 k;

    j = 0;
    tab = addr;
    while (j < size)
    {
        ft_print(tab, &i, j, size);
        i = 0;
        while (i < 16 && i + j < size)
        {
            k = tab[i + j];
            if (k >= 32 && k <= 126)
                write(1, &k, 1);
            else
                write(1, ".", 1);
            i++;
        }
        j += 16;
        write(1, "\n", 1);
    }
}

int     main(void)
{
    int     tab[10] = {0, 23, 150, 255, 12, 16, 21, 42};

    print_memory(tab, sizeof(tab));
    return (0);
}
