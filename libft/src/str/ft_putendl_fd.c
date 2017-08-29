/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jkalia <jkalia@student.42.us.org>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 17:13:13 by jkalia            #+#    #+#             */
/*   Updated: 2017/03/03 17:14:56 by jkalia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>
#include <unistd.h>

void	ft_putendl_fd(char const *src, int fd)
{
	while (*src)
		write(fd, src++, 1);
	ft_putchar_fd('\n', fd);
}
