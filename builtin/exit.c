/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 17:34:29 by ybourais          #+#    #+#             */
/*   Updated: 2023/07/14 19:59:43 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int	a_toi(char *str, int *handler)
{
	int		i;
	long	res;
    int signe = 1;

	i = 0;
	res = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '-')
    {
        signe *= -1;
		i++;
    }
	else if (str[i] == '+')
		i++;
	else if (!(str[i] >= '0' && str[i] <= '9'))
		*handler = 0;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
    if(!(str[i] >= '0' && str[i] <= '9') && str[i] != '\0')
        *handler = 0;
	return (res*signe);
}

void ft_exit(char **tab)
{
    int p = 1;

    if(tab[0] && !tab[1])
    {
        write(1, "exit\n", 5);
        exit(exist_status);
    }
    else
    {
        a_toi(tab[1], &p);
        if(p == 1 && tab[2])
        {
            write(1, "exit\n", 5);
            write(2, "my_Shell: exit: too many arguments\n", 35);
            exist_status = 1;
        }
        else if(p == 1 && !tab[2])
        {
            write(1, "exit\n", 5);
            exist_status = a_toi(tab[1], &p);
            exit(exist_status);
        }
        else if(p == 0)
        {
            write(2, ": numeric argument required\n", 28);
            exist_status = 255;
            exit(exist_status);
        }
    }
}
