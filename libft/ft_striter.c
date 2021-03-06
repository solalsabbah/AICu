/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 20:23:16 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/18 13:28:01 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_striter(char *s, void (*f)(char *))
{
	int i;

	if (!s)
		return ;
	if (!f)
		return ;
	i = 0;
	while (s[i])
	{
		(*f)(&s[i]);
		i++;
	}
}
