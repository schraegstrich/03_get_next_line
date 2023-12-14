/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkirillo <lkirillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:28:44 by lkirillo          #+#    #+#             */
/*   Updated: 2023/12/14 21:28:44 by lkirillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	need_to_free(t_list **list, t_list *clean_node, char *buffer)
{
	t_list	*temp;

	if (*list == NULL)
		return ;
	while (*list)
	{
		temp = (*list)->next;
		free((*list)->str_buffer);
		free(*list);
		*list = temp;
	}
	*list = NULL;
	if (clean_node->str_buffer[0])
		*list = clean_node;
	else 
	{
		free(buffer);
		free(clean_node);
	}
}

void	clean_the_static(t_list **list)
{
	t_list	*last_node;
	t_list	*clean_node;
	int		i;
	int		j;
	char	*buffer;

	buffer = malloc(BUFFER_SIZE + 1);
	clean_node = malloc(sizeof(t_list));
	if (buffer == NULL || clean_node == NULL)
		return ;
	last_node = is_last_node(*list);
	i = 0;
	j = 0;
	while (last_node->str_buffer[i] && last_node->str_buffer[i] != '\n')
		++i;
	while (last_node->str_buffer[i] && last_node->str_buffer[++i])
		buffer[j++] = last_node->str_buffer[i];
	buffer[j] = '\0';
	clean_node->str_buffer = buffer;
	clean_node->next = NULL;
	need_to_free(list, clean_node, buffer);
}

char    *line_plus_plus(t_list *list)
{
    int     new_str_len;
    char    *next_str;

    if (list == NULL)
        return (NULL);
    new_str_len = len_till_newline(list);
    next_str = malloc(new_str_len + 1);
    if (next_str == NULL)
        return (NULL);
    copy_str(list, next_str);
    return (next_str);

}

void	create_list(t_list **list, int fd)
{
	int		is_read;
	char	*buffer;

	while (!is_new_line(*list))
	{
		buffer = malloc(BUFFER_SIZE + 1);
		if (buffer == NULL)
			return ;
		is_read = read(fd, buffer, BUFFER_SIZE);
		if (!is_read)
		{
			free(buffer);
			return ;
		}
		buffer[is_read] = '\0';
		add_the_node(list, buffer);
	}
}

char	*get_next_line(int fd)
{
    static t_list   *static_list = NULL;
    char            *next_line;

    if (fd < 0 || BUFFER_SIZE <= 0 || read (fd, &next_line, 0) < 0)
    {
        if (static_list != NULL)
        {
            free(static_list->str_buffer);
            static_list->str_buffer = NULL;
        }
        free(static_list);
        static_list = NULL;
        return (NULL);
    }
    create_list(&static_list, fd);
    if (static_list == NULL)
        return (NULL);
    next_line = line_plus_plus(static_list);
    clean_the_static(&static_list);
    return (next_line);
} 