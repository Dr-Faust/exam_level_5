#include <stdlib.h>
#include <unistd.h>

char	*ft_set_mem(void)
{
	char	*buf;
	int		i;

	i = 0;
	buf = (char *)malloc(sizeof(char) * 2048);
	while (i < 2048)
		buf[i++] = '\0';
	return (buf);
}

void	ft_start(char *src, char *buf, int *i, int j)
{
	int     flag;

	flag = 1;
	if (src[(*i)] == '[' && !buf[j])
	{
		while (flag)
		{
			(*i)++;
            if (src[(*i)] == '[')
                flag++;
        	else if (src[(*i)] == ']')
				flag--;
		}
	}
}

void	ft_end(char *src, char *buf, int *i, int j)
{
	int flag;

	flag = 1;
	if (src[(*i)] == ']' && buf[j])
	{
		while (flag)
		{
			(*i)--;
            if (src[(*i)] == ']')
				flag++;
        	else if (src[(*i)] == '[')
			    flag--;
		}
	}
}

void    ft_brainfuck(char *src, char *buf, int i, int j)
{
	while (src[i])
	{
		if (src[i] == '>')
			j++;
    	else if (src[i] == '<')
			j--;
		else if (src[i] == '+')
			buf[j]++;
    	else if (src[i] == '-')
			buf[j]--;
		else if (src[i] == '.')
			write(1, &buf[j], 1);
		else if (src[i] == '[')
			ft_start(src, buf, &i, j);
		else if (src[i] == ']')
			ft_end(src, buf, &i, j);
		i++;
	}
}

int		main(int argc, char **argv)
{
	int		i;
	int		j;
	char	*buf;

	i = 0;
	j = 0;
	buf = ft_set_mem();
	if (argc == 2)
		ft_brainfuck(argv[1], buf, i, j);
	else
		write(1, "\n", 1);
	return (0);
}
