/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/13 12:03:03 by ybourais          #+#    #+#             */
/*   Updated: 2023/07/14 20:03:20 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

t_env *change_env(t_env *head, char *new, char *old)
{
    t_env *tmp;
    tmp = head;

    while (tmp)
    {
        if (compare(tmp->key, old))
        {
            free(tmp->value);
            tmp->value = ft_strdup(new);
        }
        tmp = tmp->next;
    }
    return head;
}

void cd(char **tab, t_env *head) 
{

    char cwd[1024];
    if(tab[0] && !tab[1])
    {
        head = change_env(head, getcwd(cwd, sizeof(cwd)), "OLDPWD");
        chdir(getenv("HOME"));
        head = change_env(head, getcwd(cwd, sizeof(cwd)), "PWD");
        exist_status = 0;
    }
    else if(tab[1])
    {
        if(!access(tab[1], F_OK))
        {
            head = change_env(head, getcwd(cwd, sizeof(cwd)), "OLDPWD");
            chdir(tab[1]);
            head = change_env(head, getcwd(cwd, sizeof(cwd)), "PWD");
            exist_status = 0;
        }
        else
        {
            write(2, "my_Shell: ", 10);
            write(2, tab[1], ft_strlen(tab[1]));
            write(2, " : No such file or directory\n", 29);
            exist_status = 1;
        }
    }
}
