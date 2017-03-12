/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opodolia <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:45:54 by opodolia          #+#    #+#             */
/*   Updated: 2017/01/24 14:48:46 by opodolia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>

int		ft_size(long val, int base)
{
	int size;

	size = 1;
	if (val < 0 && base == 10)
		size++;
    val = (val < 0) ? -val : val;
	while (val >= base)
	{
		val /= base;
		size++;
    }
	return (size);
}

char	*ft_itoa_base(int value, int base)
{
    char	*bs;
    char	*str;
    int     size;
    long    val;

    val = value;
    bs = "0123456789ABCDEF";
    size = ft_size(val, base);
    str = (char *)malloc(sizeof(char) * (size + 1));
    str[size] = '\0';
    printf("size %d\n", size);
    val = (val < 0) ? -val : val;
    if (val == 0)
        str[0] = '0';
    while (val > 0)
    {
        str[--size] = bs[val % base];
        val /= base;
    }
	str[0] = (str[0]) ? str[0] : '-';
	return (str);
}

int		main(void)
{
	printf("%s\n", ft_itoa_base(10, 10));
	return (0);
}
