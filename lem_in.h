/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem-in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: opanchen <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/30 13:56:49 by opanchen          #+#    #+#             */
/*   Updated: 2017/08/09 04:36:14 by opanchen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H
# include "get_next_line.h"

int				is_number(char *line);
int				count_ants(char *line);
int				test_str(char *s);
int				where_start(char *line);
char			*strm(char *line);
int				check_rm(char *line);
long long int	my_atoi(const char *str);
int				wtf(char *line);
char			*add_room(char *line, char *rooms);
int				add_start(char *line, char **s);
int				add_end(char *line, char **s);
int				check_dubl(char *rm, char **st_ed);
int				**set_conect(char *rooms, int **con);
int				add_conect(char *line, int **con, char *rooms);
int				is_con(char *line);
int				**setin(char **zv, char **s, int **con);
int				*solve(char *rooms, int **conect, char **to_st_ed);
void			cleaner(int **c, int y, int a1, int a2);
int				max_in(int **c, int y);
int				find_x(int **c, int p, int y, int j);
void			find_y(int **c, int y);
void			pr(int *a, char *ro, char *t);
int				check_empty(int o, int p, int **c, int y);
int				number(char *line, char **t, int *i, char **s);
int				lol(char **t, char *y, int ***u, char *i);
int				kik(char *line, char **y);
int				last(int **r, char *h, char **y, char *s);
int				lem(char *line, char *rooms, char **to_st_ed, int **t);
int				con(char **t, char *r, int ***o, char *l);
int				starty(char *l, char ***y, int i, int u);
int				roomy(int **c, char *l, char **r, int i);
int				nano(char **s);
void			st_ed(int *y, char **u, char **t);
int				*algo(int *yij, int **c, int *a, int *k);
void			popo(int **c, int *a, int *l, int max);
char			*riri(char *rooms, int *i, char *line);
char			*roro(int *i, char *line, char *rooms);
char			*kom(int *i, char *room, char *line);
char			*kim(int *i, char *line, char *x);
char			*kum(int *i, char *line, char *y);
int				sk(char **s, char **zv, int **con);
void			pr2(int **p, int max, int *a, int num);
int				is_max(int *a, int num);
void			print(int max, char *number, char **t, int **p);
int				wot(char *line);
int				uou(char *line);
int				yy(int *i, char *line);
char			*koko(char *line, char *s);
int				gg(char **s, char *line);
void			ft_putstr_c(char *s);
void			ft_putchar_g(char c);
void			ft_putstr_m(char *s);
int				is_ed(int o, int p, int **c, int y);
int				iyy(int ou, int cu, int **c, int y);
#endif
