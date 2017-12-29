/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 17:56:57 by tdenion           #+#    #+#             */
/*   Updated: 2016/10/13 13:25:53 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 8

# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include "libft.h"

typedef struct		s_gnl
{
	int				fds;
	int				readed_c;
	int				rs;
	char			*saved_readed;
	struct s_gnl	*next;
}					t_gnl;

int					get_next_line(const int fd, char **line);

#endif
