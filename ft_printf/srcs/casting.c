/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   casting.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ssabbah <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/28 15:49:46 by ssabbah           #+#    #+#             */
/*   Updated: 2018/02/03 16:34:07 by ssabbah          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

long long	signed_cast(long long val, int mod)
{
	if (mod == LL)
		val = (long long)val;
	else if (mod == L)
		val = (long)val;
	else if (mod == HH)
		val = (char)val;
	else if (mod == H)
		val = (short)val;
	else if (mod == J)
		val = (intmax_t)val;
	else if (mod == Z)
		val = (size_t)val;
	else if (mod == -1)
		val = (int)val;
	return (val);
}

long long	unsigned_cast(unsigned long long val, int mod)
{
	if (mod == LL)
		val = (unsigned long long)val;
	else if (mod == L)
		val = (unsigned long)val;
	else if (mod == HH)
		val = (unsigned char)val;
	else if (mod == H)
		val = (unsigned short)val;
	else if (mod == J)
		val = (uintmax_t)val;
	else if (mod == Z)
		val = (size_t)val;
	else if (mod == -1)
		val = (unsigned int)val;
	return (val);
}
