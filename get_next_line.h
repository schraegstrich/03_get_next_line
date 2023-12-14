/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkirillo <lkirillo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 21:04:56 by lisakirillo       #+#    #+#             */
/*   Updated: 2023/12/14 23:39:31 by lkirillo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10 
# endif

# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_list
{
	char			*str_buffer;
	struct s_list	*next;
}					t_list;

char	*get_next_line(int fd);
void	create_list(t_list **list, int fd);
char	*line_plus_plus(t_list *list);
void	clean_the_static(t_list **list);
void	need_to_free(t_list **list, t_list *clean_node, char *buffer);
void	copy_str(t_list *list, char *str);
int		len_till_newline(t_list *list);
t_list	*is_last_node(t_list *list);
void	add_the_node(t_list **list, char *buffer);
int		is_new_line(t_list *list);

#endif