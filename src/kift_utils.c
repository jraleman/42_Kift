/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kift_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 09:52:04 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/18 10:03:43 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <kift.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <sys/select.h>
#include <sphinxbase/err.h>
#include <sphinxbase/ad.h>
#include "pocketsphinx.h"
#include "norm_helpers.h"

static int	e_error_rtn(char *header, int index, char *error_msg)
{
	E_ERROR(error_msg, header[index]);
	return (0);
}

int			check_wav_header(char *header, int expected_sr)
{
	int sr;

	if (header[34] != 0x10)
		return (e_error_rtn(header, 34, WH_ERR_1));
	if (header[20] != 0x1)
		return (e_error_rtn(header, 20, WH_ERR_2));
	if (header[22] != 0x1)
		return (e_error_rtn(header, 22, WH_ERR_3_1" "WH_ERR_3_2));
	sr = ((header[24] & 0xFF) | ((header[25] & 0xFF) << 8) |
		((header[26] & 0xFF) << 16) | ((header[27] & 0xFF) << 24));
	if (sr != expected_sr)
	{
		E_ERROR(WH_ERR_4_1" "WH_ERR_4_2, sr, expected_sr);
		return (0);
	}
	return (1);
}
