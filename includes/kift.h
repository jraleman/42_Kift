/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kift.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/06 01:50:55 by jkalia            #+#    #+#             */
/*   Updated: 2017/06/18 22:19:03 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KIFT_H
# define KIFT_H

# include <libft.h>
# include <pocketsphinx.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define BUFFER 1024
# define ERROR	(-1)

typedef struct	s_server
{
	char		recognized[BUFFER];
	int			recognized_len;
	char		response[BUFFER];
	int			response_len;
	char		send[BUFFER * 12];
	int			send_len;
}				t_server;

int				init_pocketsphinx(t_server *server);
void			kift_log(char *recognized, char *response);
void			run_commands(char *cmd, t_server *server);
int				check_wav_header(char *header, int expected_sr);
void			ft_putbuf(const char *str, t_server *server);

/*
**	Kift Commands
*/

int				control_finder(char *cmd, t_server *server);
int				control_history(char *cmd, t_server *server);
int				control_misc(char *cmd, t_server *server);
int				control_user(char *cmd, t_server *server);

#endif
