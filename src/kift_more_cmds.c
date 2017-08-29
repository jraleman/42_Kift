/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kift_more_cmds.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 10:25:58 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/18 22:21:11 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kift.h>

/*
** These functions do one of the following:
**   - Show the active programs
**   - Search
**   - Hide hidden files
**   - Show hidden files
**   - Sleep
*/

static void	control_finder_extension(int *ret, char *cmd, t_server *server)
{
	if (!strcmp(cmd, "SHOW HIDDEN FILES"))
	{
		*ret = system("defaults write com.apple.finder AppleShowAllFiles YES \
		&& killall Finder '/System/Library/CoreServices/Finder.app'");
		ft_putbuf("Showing hidden files...", server);
	}
	else if (!strcmp(cmd, "SLEEP"))
	{
		*ret = system("osascript -e 'tell application \"Finder\" to sleep'");
		ft_putbuf("Entering sleep mode...", server);
	}
}

int			control_finder(char *cmd, t_server *server)
{
	int		ret;

	ret = 0;
	if (!strcmp(cmd, "SHOW"))
	{
		ret = system("osascript -e 'tell application \"System Events\"' \
		-e 'key code 160' -e 'end tell'");
		ft_putbuf("Showing active programs...", server);
	}
	else if (!strcmp(cmd, "DO NOT SHOW HIDDEN FILES"))
	{
		ret = system("defaults write com.apple.finder AppleShowAllFiles NO \
		&& killall Finder '/System/Library/CoreServices/Finder.app'");
		ft_putbuf("Hiding hidden files...", server);
	}
	else
		control_finder_extension(&ret, cmd, server);
	return (ret);
}

int			control_history(char *cmd, t_server *server)
{
	int		ret;

	ret = 0;
	if (!strcmp(cmd, "HISTORY"))
	{
		ret = system("open ./kevin_log.txt");
		ft_putbuf("Check out our history...", server);
	}
	return (ret);
}

int			control_web(char *cmd, t_server *server)
{
	int		ret;

	ret = 0;
	if (!strcmp(cmd, "SEARCH THE WEB FOR TERM") ||
		!strcmp(cmd, "SEARCH THE WEB FOR TERM IN PARENTHESES"))
	{
		ft_putbuf("Searching the web for term. Sorry, I just found spiders...",
				server);
	}
	return (ret);
}

int			control_user(char *cmd, t_server *server)
{
	FILE	*fp;
	char	path[1024];
	int		ret;

	ret = 0;
	if (!strcmp(cmd, "WHO IS CONNECTED"))
	{
		fp = popen("/usr/bin/whoami", "r");
		if (fp == NULL)
			return (ERROR);
		if (fgets(path, sizeof(path) - 1, fp) != NULL)
			ft_putbuf(path, server);
		pclose(fp);
	}
	else if (!strcmp(cmd, "WHERE"))
	{
		fp = popen("/bin/hostname", "r");
		if (fp == NULL)
			return (ERROR);
		if (fgets(path, sizeof(path) - 1, fp) != NULL)
			ft_putbuf(path, server);
		pclose(fp);
	}
	return (ret);
}
