/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   norm_helpers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gguiulfo <gguiulfo@student.42.us.org>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/18 06:48:32 by gguiulfo          #+#    #+#             */
/*   Updated: 2017/06/18 10:04:29 by gguiulfo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NORM_HELPERS_H
# define NORM_HELPERS_H

# define WH_ERR_1 "Input audio file has [%d] bits per sample instead of 16\n"
# define WH_ERR_2 "Input audio file has compression [%d] and not required PCM\n"
# define WH_ERR_3_1 "Input audio file has [%d]"
# define WH_ERR_3_2 "channels, expected single channel mono\n"
# define WH_ERR_4_1 "Input audio file has sample rate"
# define WH_ERR_4_2 "[%d], but decoder expects [%d]\n"
# define MP3_ERR_1 "Can not decode mp3 files, convert input file"
# define MP3_ERR_2 "to WAV 16kHz 16-bit mono before decoding.\n"

typedef struct	s_norm_ints
{
	int32		sf;
	int32		ef;
	int32		pprob;
}				t_norm_ints;

typedef struct	s_recognize_h
{
	const char	*hyp;
	int16		adbuf[2048];
	int32		k;
	uint8		utt_started;
	uint8		in_speech;
	int32		print_times;
}				t_recognize_h;

#endif
