/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   a_export.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nmasuda <nmasuda@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 16:06:28 by nmasuda           #+#    #+#             */
/*   Updated: 2025/11/08 21:06:01 by nmasuda          ###   ########.fr       */
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

size_t	ev_strncmp(char *line1, char *line2)
{
	int	i;

	i = 0;
	while (line1[i] == line2[i])
	{
		if (line1[i] == '=')
			return (0);
		i++;
	}
	return (1);
}

size_t	double_check(char **line, char **ev)
{
	int	i;
	int	j;
	int	cnt;

	(void)ev;
	cnt = 0;
	i = CMD + 1;
	while (line[i])
	{
		j = i +1;
		while (line[j])
		{
			cnt += ev_strncmp(line[j], line[i]);
			j++;
		}
		j = 0;
		while (ev[j])
		{
			if(!ft_strncmp(ev[j], line[i],ev_strlen(line[i])))
			{
				// if(cnt > 0)
				// 	cnt--;
			}
			j++;
		}
		i++;
	}
	if(cnt < 0)
		cnt = 0;
	printf("j evcnt:%d\n",j);
	printf("cnt 追加するcnt:%d\n",cnt);
	return (j +cnt);
}

char	**c_export(char **line, char **ev)
{
	char	**new_ev;

	size_t i = 0;
	new_ev = NULL;
	printf("%zu\n", double_check(line, ev) - i);
	return (new_ev);
}
