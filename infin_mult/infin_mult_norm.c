/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/02/07 10:46:02 by exam              #+#    #+#             */
/*   Updated: 2017/02/07 12:03:27 by exam             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "infin.h"

static int	ft_strlen(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

static void	ft_zero(char *str, t_mult *mult, int mode)
{
	int		i;

	i = 0;
	if (mode == 0)
		while (i < mult->res_len)
		{
			str[i] = 0;
			i++;
		}
	else
		while (i < mult->res_len)
		{
			str[i] += '0';
			i++;
		}
}

static char	*ft_add(t_mult *mult)
{
	int		tmp;

	tmp = mult->res_len;
	while (--tmp >= 0)
		while (mult->res[tmp] > 9)
		{
			mult->res[tmp - 1] += mult->res[tmp] / 10;
			mult->res[tmp] = mult->res[tmp] % 10;
		}
	return (mult->res);
}

static char	*ft_calculate(t_mult *mult)
{
	int		i;
	int		j;
	int		k;

	ft_zero(mult->res, mult, 0);
	i = mult->len_2 - 1;
	while (i >= 0 && mult->n_2[i] != '-')
	{
		k = mult->res_len + i - mult->len_2;
		j = mult->len_1 - 1;
		while (j >= 0 && mult->n_1[j] != '-')
		{
			mult->res[k] += (mult->n_1[j] - '0') * (mult->n_2[i] - '0');
			mult->res = ft_add(mult);
			k--;
			j--;
		}
		i--;
	}
	ft_zero(mult->res, mult, 1);
	return (mult->res);
}

int			main(int argc, char **argv)
{
	t_mult		mult;

	if (argc == 3)
	{
		if (argv[1][0] == '0' || argv[2][0] == '0')
		{
			write(1, "0\n", 2);
			return (0);
		}
		mult.n_1 = argv[1];
		mult.n_2 = argv[2];
		mult.len_1 = ft_strlen(mult.n_1);
		mult.len_2 = ft_strlen(mult.n_2);
		mult.res_len = mult.len_1 + mult.len_2;
		mult.res = (char *)malloc(sizeof(char) * mult.res_len);
		mult.res = ft_calculate(&mult);
		if ((mult.n_1[0] == '-' && mult.n_2[0] != '-') ||
				(mult.n_1[0] != '-' && mult.n_2[0] == '-'))
			write(1, "-", 1);
		mult.point = -1;
		while (mult.res[mult.point + 1] == '0')
			mult.point++;
		while (++mult.point < mult.res_len)
			write(1, &(mult.res[mult.point]), 1);
		write(1, "\n", 1);
		free(mult.res);
	}
	return (0);
}
