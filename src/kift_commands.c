/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kift_commands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaleman <jaleman@student.42.us.org>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/11 02:21:22 by jaleman           #+#    #+#             */
/*   Updated: 2017/06/18 20:29:47 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kift.h>

/*
** This function copies str to appropriate buffer in server struct
*/

void		ft_putbuf(const char *str, t_server *server)
{
	if (server->response_len != 0)
		return ;
	server->response_len = strlen(str);
	strncpy(server->response, str, server->response_len);
	printf("%s\n", str);
}

/*
** This function do one of the following:
**   - Invert the creen colors.
**   - Brightness display to 100%
**   - Brightness display to 5%
*/

static int	control_display(char *cmd, t_server *server)
{
	int		ret;

	ret = 0;
	if (!strcmp(cmd, "INVERT COLORS"))
	{
		ret = system("osascript -e 'tell application \"System Events\"' \
		-e 'key code 28 using {control down, option down, command down}' \
		-e 'end tell'");
		ft_putbuf("Inverting colors...", server);
	}
	else if (!strcmp(cmd, "LIGHTS ON"))
	{
		ret = system("osascript -e 'tell application \"System Events\"' \
		-e 'repeat 16 times' -e 'key code 144' -e 'end repeat' -e 'end tell'");
		ft_putbuf("Turning lights on...", server);
	}
	else if (!strcmp(cmd, "LIGHTS OFF"))
	{
		ret = system("osascript -e 'tell application \"System Events\"' \
		-e 'repeat 16 times' -e 'key code 145' -e 'end repeat' -e 'end tell'");
		ft_putbuf("Turning lights off...", server);
	}
	return (ret);
}

/*
** This function do one of the following:
**   - Mute the sound.
**   - Unmute the sound.
*/

static int	control_sound(char *cmd, t_server *server)
{
	int		ret;

	ret = 0;
	if (!strcmp(cmd, "VOLUME OFF"))
	{
		ret = system("osascript -e 'set volume with output muted'");
		ft_putbuf("Turning volume off...", server);
	}
	else if (!strcmp(cmd, "VOLUME ON"))
	{
		ret = system("osascript -e 'set volume without output muted'");
		ft_putbuf("Turning volume on...", server);
	}
	else if (!strcmp(cmd, "PLAY MUSIC"))
	{
		ret = system("osascript -e 'tell application \"Spotify\"' \
		-e 'play track \"spotify:track:51pQ7vY7WXzxskwloaeqyj\"' \
		-e 'end tell'");
		ft_putbuf("Playing the only music that exists.", server);
	}
	return (ret);
}

/*
** This function do one of the following:
**   - Takes a screenshot of the whole screen.
**   - Takes a screenshot of just a section of the screen.
*/

static int	control_screenshot(char *cmd, t_server *server)
{
	int		ret;

	ret = 0;
	if (!strcmp(cmd, "SCREENSHOT"))
	{
		ret = system("screencapture ~/Desktop/$(date +%Y%m%d%H%M%S).png");
		ft_putbuf("Taking screenshot...", server);
	}
	else if (!strcmp(cmd, "CAPTURE"))
	{
		ret = system("screencapture -i ~/Desktop/$(date +%Y%m%d%H%M%S).png");
		ft_putbuf("Taking screencapture...", server);
	}
	return (ret);
}

/*
** Run a specific command if it matches the words.
*/

void		run_commands(char *cmd, t_server *server)
{
	if (strncmp("KEVIN", cmd, 5))
	{
		ft_putbuf("name missing", server);
		return ;
	}
	if (control_finder(&cmd[6], server) == ERROR)
		ft_putbuf("something went wrong!", server);
	if (control_display(&cmd[6], server) == ERROR)
		ft_putbuf("something went wrong!", server);
	if (control_sound(&cmd[6], server) == ERROR)
		ft_putbuf("something went wrong!", server);
	if (control_screenshot(&cmd[6], server) == ERROR)
		ft_putbuf("something went wrong!", server);
	if (control_history(&cmd[6], server) == ERROR)
		ft_putbuf("something went wrong!", server);
	if (control_user(&cmd[6], server) == ERROR)
		ft_putbuf("something went wrong!", server);
	if (control_misc(&cmd[6], server) == ERROR)
		ft_putbuf("something went wrong!", server);
	ft_putbuf("command not recognized", server);
}
