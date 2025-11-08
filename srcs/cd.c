/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/22 20:48:31 by nmasuda           #+#    #+#             */
/*   Updated: 2025/11/08 20:47:24 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "builtin.h"

// static void	t_pwd_free(t_pwd *pwd, char *mess)
// {
// 	if (pwd->new_pwd)
// 		free(pwd->new_pwd);
// 	if (pwd->old_pwd)
// 		free(pwd->old_pwd);
// 	if (mess)
// 	{
// 		if (pwd->new_ev)
// 			free_all(pwd->new_ev);
// 		error(NULL, mess, NULL, 1);
// 	}
// }

// static void	input(t_pwd *pwd, int i)
// {
// 	// int	j;

// 	// j = pwd->f_new_pwd + i;
// 	// if (pwd->f_new_pwd)
// 	// {
// 	// 	pwd->new_ev[j] = ft_strjoin("PWD=", pwd->new_pwd);
// 	// 	if (!pwd->new_ev[j])
// 	// 		t_pwd_free(pwd, "cd_strjoin_error\n");
// 	// }
// 	// j += pwd->f_old_pwd;
// 	// if (pwd->f_old_pwd)
// 	// {
// 	// 	pwd->new_ev[j] = ft_strjoin("OLD_PWD=", pwd->old_pwd);
// 	// 	if (!pwd->new_ev[j])
// 	// 		t_pwd_free(pwd, "cd_strjoin_error\n");
// 	// }
// }

// static char	**enpty_pwd_check(t_pwd *pwd)
// {
// 	// char	**new_ev;
// 	// int		i;

// 	// i = 0;
// 	// // pwd->f_new_pwd = 1;
// 	// // pwd->f_old_pwd = 1;
// 	// // while (pwd->ev[i])
// 	// // {
// 	// // 	if (!ft_strncmp(pwd->ev[i], "PWD=", 4))
// 	// // 		pwd->f_new_pwd--;
// 	// // 	else if (!ft_strncmp(pwd->ev[i], "OLDPWD=", 7))
// 	// // 		pwd->f_old_pwd--;
// 	// // 	i++;
// 	// // }
// 	// new_ev = malloc(sizeof(char *) * (i + 1 + pwd->f_old_pwd + pwd->f_new_pwd));
// 	// if (!new_ev)
// 	// 	t_pwd_free(pwd, "cd_malloc_error\n");
// 	// pwd->new_ev = new_ev;
// 	// // input(pwd, i);
// 	// return (new_ev);
// }

// static char	**change_pwd(t_pwd *pwd)
// {
// 	// int	i;

// 	// i = 0;
// 	// enpty_pwd_check(pwd);
// 	// pwd->f_new_pwd = 0;
// 	// pwd->f_old_pwd = 0;
	
// 	// while (pwd->ev[i])
// 	// {
// 	// 	if (!ft_strncmp(pwd->ev[i], "PWD=", 4))
// 	// 		pwd->new_ev[i] = ft_strjoin("PWD=", pwd->new_pwd);
// 	// 	else if (!ft_strncmp(pwd->ev[i], "OLDPWD=", 7))
// 	// 		pwd->new_ev[i] = ft_strjoin("OLDPWD=", pwd->old_pwd);
// 	// 	else
// 	// 	pwd->new_ev[i] = ft_strdup(pwd->ev[i]);
// 	// 	if (!pwd->new_ev[i])
// 	// 		t_pwd_free(pwd, "cd_getpwd_error\n");
// 	// 	i++;
// 	// }
// 	// pwd->new_ev[i + pwd->f_new_pwd + pwd->f_old_pwd] = NULL;
// 	// t_pwd_free(pwd, NULL);
// 	// return (pwd->new_ev);
// }

// char	**c_cd(char **line, char **ev)
// {
// 	// char	*chpath;
// 	// t_pwd	pwd;

// 	// ft_memcpy(&pwd, &(t_pwd){0}, sizeof(t_pwd));
// 	// pwd.ev = ev;
// 	// if (line[CMD + 2] && line[CMD + 1])
// 	// 	error(line[0], ": cd: too many arguments\n", NULL, 1);
// 	// if (line[CMD + 1] == NULL || ft_strncmp(line[CMD + 1], "~", 2) == 0)
// 	// 	chpath = getenv("HOME");
// 	// else
// 	// 	chpath = line[CMD + 1];
// 	// pwd.old_pwd = getcwd(NULL, 0);
// 	// if (!pwd.old_pwd)
// 	// 	error(NULL, "cd_getpwd_error\n", NULL, 1);
// 	// if (chdir(chpath) == -1)
// 	// {
// 	// 	free(pwd.old_pwd);
// 	// 	error(line[0], ": cd: /home/uea: No such file or directory\n", NULL, 1);
// 	// }
// 	// pwd.new_pwd = getcwd(NULL, 0);
// 	// if (!pwd.new_pwd)
// 	// 	t_pwd_free(&pwd, "cd_getpwd_error\n");
// 	// return (change_pwd(&pwd));
// }
