/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/15 11:00:07 by ybourais          #+#    #+#             */
/*   Updated: 2023/07/10 19:22:08 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

#include <fcntl.h> /* open */
# include <stdio.h> /* printf strerror perror*/
#include <readline/readline.h> /* redline */
#include <readline/history.h> /* redline */
#include <stdlib.h> /* malloc, free getenv */
#include <unistd.h> /* access, fork, getcwd, chdir, unlink execve dup dup2 pipe isatty ttyname ttyslot*/
#include <sys/wait.h> /* waitpid */
#include <sys/stat.h> /* stat */
#include <dirent.h> /* opendir readdir closedir*/
#include <sys/ioctl.h> /* ioctl */
#include <termios.h> /* tcsetattr */
#include <termcap.h> /* tgetent */
#include <string.h>
#include "Libft/libft.h"

typedef struct  node 
{
    char *var;
    struct node *next;
} t_node;

typedef struct  s_list 
{
    char *key;
    char *value;
    struct s_list *next;
} t_env;

typedef enum e_type
{
    QUOT = '\'',
    D_QUOT = '\"',
    S_SPACE = ' ',
    VAR = '$',
    PIPE = '|',
    R_OUT = '>',
    R_IN = '<',
    EXIT_S = '?',
    WORD,
    DR_IN,
    DR_OUT,
} t_type;

typedef enum e_state
{
    IN_QUOT,
    IN_D_QUOT,
    NORMAL,
} t_state;

typedef struct  s_info 
{
    char *content;
    t_type type;
    t_state state;
    struct s_info *next;
} t_info;

typedef struct  s_rd
{
    char *file;
    int type;
    struct s_rd *next;
} t_rd;

typedef struct  s_cmd
{
    char **full_cmd;
    int nbr_arg;
    t_rd *rd;
} t_cmd;

int is_space(char c);
int special_char(char c);
t_info *creat_node(t_info *head, char *content, t_type type, t_state state);
t_env *creat_liste(t_env *head, char *env);
t_env *ft_env(char **tab);
char *set_value(char *str);
char *set_variables(char *str);
t_info *remove_and_expand(t_info *info, t_env *env);
t_info *join_content(t_info *info);
t_info *remove_quots(t_info *info);
t_info* delete_node(t_info* head, t_info* to_delete);
int cheak_quoting(t_info *info);
t_info *set_state(t_info *info);
void free_list(t_info *head);
void print_list(t_info *head);
char *get_state(t_state state);
char *get_type(t_type type);
t_info *lexer(t_info *info, char *line);
int compare(char *s1, char *s2);
int cheak_pipes(t_info *info);
int cheack_red(t_info *info);
int cheack_syntax(t_info *info);
t_cmd *parss_red(t_info *info);

/*minishell*/
t_node *commands(char **tab, t_node *head, int *arr);
t_node *creat_env(t_node *head, char **env);
char **var_expantion(int *arr, char **tab, t_node *head, int h);
char *find_value_dollar(t_node *head, char *str);
char **resize_and_find(char **tab, t_node *head, int i);
char **from_list_to_tab(t_node *head);
char *find_path(char **env, int j, char *str);

/*builtin*/
void echo (char **tab);
void echo_n (char **tab);
void env(t_node *head);
void print_export(char *str);
t_node *unset(char **tab, t_node *head);
t_node *ft_export(char **tab, t_node *head);
void pwd(t_node *head);
void cd(char **tab, t_node *head);

/*builtin_utils*/
t_node *replace_nNOode(t_node *head, char *new_str, char *to_delete);
t_node *search_list(t_node *head, char *str, int *p);
t_node *creat_list(t_node *head, char *env);
t_node *unset_node(t_node *head, char *to_delete);
int find_value(t_node *head, char *str);

/*parssing*/
void ft_error(int n);
int valid_dollar(char *str);
int arr_dollar(int *arr, int quote, int indice);
int *check_quoting(char *str);
void modification(char **tab, int n, int t);

/*parssing_tools*/
void free_tab(char **tab);
int slen(char *str);
int nbr_words(char *str, char c);
int word_len(char *str, char c);
char **split(char *s, char c);

/*tools*/
void copy_str(char *dst, char *src);
int copy_tab(char **tab1, char **tab2);
char *join(char *s1, char *s2);
int is_alphanumeric(char *str);
int without_equal(char *str);

/*tools_2*/
int search(char *str, char c);
int strchrch(char *str, char c);
int compare_len(char *to_delete, char *list_var);
int compare_until(char *s1, char *s2, int n);
int compare(char *s1, char *s2);

#endif