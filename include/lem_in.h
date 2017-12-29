/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tdenion <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 09:07:56 by tdenion           #+#    #+#             */
/*   Updated: 2016/11/13 12:05:06 by tdenion          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "../lib/includes/ft_printf.h"
# include "../lib/includes/get_next_line.h"

typedef struct		s_link
{
	char			*name;
	int				x;
	int				y;
	int				isfourmis;
	int				ispass;
	struct s_link	*next;
	struct s_child	*child;
}					t_link;

typedef struct		s_child
{
	int				mark;
	struct s_link	*node;
	struct s_child	*next;
}					t_child;

typedef struct		s_road
{
	int				roadlen;
	struct s_link	*node;
	struct s_road	*next_node;
	struct s_road	*next_road;
}					t_road;

typedef struct		s_fms
{
	int				num;
	int				move;
	struct s_road	*location;
	struct s_fms	*next;
}					t_fms;

typedef struct		s_env
{
	struct s_link	*room;
	struct s_link	*path;
	struct s_road	*road;
	struct s_fms	*f;
	char			*start;
	char			*end;
	char			*parse;
	int				add;
	int				nb_fourmis;
	int				rebuilted;
}					t_env;

t_link				*init_room(char *s);
t_env				*init_env(t_env *l);
t_child				*init_child();
t_road				*init_road();
t_fms				*init_fms(int n, t_road *r);
t_env				*init_move(t_env *l);
t_env				*create_tree(t_env *l, char **link);
void				destroy_all(t_env *l);
void				destroy_node(t_link *l);
void				destroy_child(t_child *l);
void				destroy_p(char **tmp);
void				destroy_fms(t_fms *f);
t_env				*find_link(t_env *l, char **link);
t_env				*add_link(t_link *start, t_link *end, t_env *l);
t_child				*add_to_last(t_child *s, t_child *n);
t_env				*parse_map(t_env *l);
t_env				*parse_room(t_env *l, char *ret);
t_env				*parse_link(t_env *l, char *ret);
void				put_error();
int					check_spaces(char *s);
int					check_int(char *s);
int					check_mid(char*s);
int					islink(t_env *l, char *s);
t_env				*rebuilt_link(t_env *l);
t_env				*build_start(t_env *l, t_link *start);
t_env				*build_end(t_env *l, t_link *end);
t_env				*build_roads(t_env *l, t_link *node, t_road *r);
t_env				*parse_com(t_env *l, char *s);
int					road_len(t_env *l, t_road *r);
t_env				*calc_all_lenroad(t_env *l);
t_road				*take_best_road(t_env *l);
t_env				*put_fms_start(t_env *l, t_road *r);
t_road				*search_best(t_env *l, int n);
t_env				*move_fms(t_env *l);
t_fms				*reset_move(t_fms *fms);
int					is_last(t_fms *f);
void				print_fourmis(t_env *l);
int					can_move(t_env *l, t_fms *fs);
int					check_end_fms(t_env *l);
t_link				*reset_mark(t_link *room, t_road *road);
t_child				*search_next_child(t_child *c);
t_road				*behind_last(t_road *road, t_road *last);
t_child				*find_last(t_child *child, t_road *road);
t_road				*reset(t_road *road, t_road *last);

#endif
