#include <unistd.h>
#include <stdlib.h>

#ifndef INFIN_H
# define INFIN_H

typedef struct	s_mult
{
	char		*n_1;
	char		*n_2;
	int			len_1;
	int			len_2;
	char		*res;
	int			res_len;
	int			point;
}				t_mult;

int		main(int argc, char **argv);

#endif
