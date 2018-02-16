/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rfautier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 19:31:52 by rfautier          #+#    #+#             */
/*   Updated: 2017/11/18 13:29:12 by rfautier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_strclr(char *s)
{
	int		i;

	if (!s)
		return ;
	i = 0;
	while (s[i])
	{
		s[i] = '\0';
		i++;
	}
}
