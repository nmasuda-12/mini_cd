/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/13 18:43:46 by nmasuda           #+#    #+#             */
/*   Updated: 2025/11/10 03:28:58 by nmasuda          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"

int ev_strlen(char *line)
{
	int i = 0;
	while(line[i] != '=')
		i++;
	return i;
}

bool dup_check(char **line,char **ev,int i)
{
	int j;
	j = 0;

	while (ev[j])
	{
		if (!ft_strncmp(ev[j], line[i], ev_strlen(line[i]) + 1))
			return false;
		j++;
	}
	j = i + 1;
	while (line[j])
	{
		if (!ft_strncmp(line[j], line[i], ev_strlen(line[i]) + 1))
			return false;
		j++;
	}
	return true;
}


size_t	malloc_cnt(char **line, char **ev)
{
	int	i;
	int	cnt;
	size_t ev_cnt;
	
	ev_cnt = 0;
	while(ev[ev_cnt])
		ev_cnt++;
	cnt = 0;
	i = CMD + 1;
	while (line[i])
	{
		if (dup_check(line,ev,i) == true)
			cnt++;
		i++;
	}
	return (ev_cnt + cnt);
}


static char	**chenge(char **new_ev, int i, int j)
{
	char	*tmp;

	tmp = new_ev[j];
	new_ev[j] = new_ev[i];
	new_ev[i] = tmp;
	return (new_ev);
}

static char	**sort(char **new_ev)
{
	int	i;
	int	j;

	i = 0;
	j = i + 1;
	while (new_ev[j] != NULL)
	{
		if (ft_memcmp(new_ev[i], new_ev[j]) > 0)
		{
			new_ev = chenge(new_ev, i, j);
			i = 0;
			j = i + 1;
		}
		else
			(void)(i++, j++);
	}
	return (new_ev);
}


bool dup_check_for_export(char **line, int i)
{
	int j = i + 1;

	while (line[j])
	{
		if (!ft_strncmp(line[j], line[i], ev_strlen(line[i]) + 1))
			return false;
		j++;
	}
	return true;
}

char	**c_export(char **line, char **ev)
{
	char	**new_ev;
	int		i;
	int		j;
	int		ev_cnt;

	ev_cnt = 0;
	while (ev[ev_cnt])
		ev_cnt++;
	new_ev = malloc(sizeof(char *) * (malloc_cnt(line, ev) + 1));
	if (!new_ev)
		error(NULL, "export_newev_malloc_error\n", NULL, 2);

	// 2. evをコピー。ただし上書き対象はスキップする
	j = 0;
    int k = 0;
	while (k < ev_cnt)
	{
		bool skip = false;
		i = CMD + 1;
		while (line[i])
		{
			// 同じキーの変数が新しく渡されていたらスキップ（上書きするから）
			if (!ft_strncmp(ev[k], line[i], ev_strlen(line[i]) + 1))
			{
				skip = true;
				break ;
			}
			i++;
		}
		if (!skip)
		{
			new_ev[j] = ft_export_strjoin("declare -x ", ev[k]);
			if (!new_ev[j])
				error(NULL, "export_ft_strjoin_malloc_error\n", new_ev, 2);
			j++;
		}
        k++;
	}

	// 3. lineにある新しい変数を追加（後方重複だけスキップ）
	i = CMD + 1;
	while (line[i])
	{
		if (dup_check_for_export(line, i) == true)
		{
			new_ev[j] = ft_export_strjoin("declare -x ", line[i]);
			if (!new_ev[j])
				error(NULL, "export_ft_strjoin_malloc_error\n", new_ev, 2);
			j++;
		}
		i++;
	}
	new_ev[j] = NULL;
	new_ev = sort(new_ev);
	c_check(line[0], new_ev);
	return (new_ev);
}
