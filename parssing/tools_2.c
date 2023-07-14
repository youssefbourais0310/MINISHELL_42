/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/11 11:23:03 by ybourais          #+#    #+#             */
/*   Updated: 2023/07/14 20:04:46 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void	copy_str(char *dst, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
}

void	print_list(t_info *head)
{
	t_info	*current;

	current = head;
	printf("|   Content   |    Type    |   State   |\n");
	printf("---------------------------------------\n");
	while (current != NULL)
	{
		printf("|  %-10s |  %-8s  |  %-8s |\n", current->content,
			get_type(current->type), get_state(current->state));
		current = current->next;
	}
}

void	free_list(t_info *head)
{
	t_info	*current;
	t_info	*next;

	current = head;
	while (current)
	{
		next = current->next;
		free(current->content);
		free(current);
		current = next;
	}
}

char	*set_variables(char *str)
{
	char	*tab;
	int		i;
	
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	tab = malloc(sizeof(char) * i + 1);
	i = 0;
	while (str[i] && str[i] != '=')
	{
		tab[i] = str[i];
		i++;
	}
	tab[i] = '\0';
	return (tab);
}

char	*set_value(char *str)
{
	char	*tab;
	int		j;
	int		i;

	j = 0;
	i = 0;
	while (str[i] && str[i] != '=')
		i++;
	if (str[i] == '\0')
		return (NULL);
	tab = malloc(sizeof(char) * ft_strlen(str) - i);
	i++;
	while (str[i])
		tab[j++] = str[i++];
	tab[j] = '\0';
	return (tab);
}
