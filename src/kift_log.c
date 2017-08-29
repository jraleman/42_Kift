/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kift_log.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 04:54:07 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/18 17:19:24 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void	kift_log(char *recognized, char *response)
{
	char buf[2048];

	if (strcmp(response, "name missing"))
	{
		sprintf(buf, "echo \"User: '%s'\" >> kevin_log.txt", recognized);
		system(buf);
		sprintf(buf, "echo \"Kevin: '%s'\n\" >> kevin_log.txt", response);
		system(buf);
	}
}
