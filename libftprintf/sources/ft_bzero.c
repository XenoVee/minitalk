/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rmaes <rmaes@student.codam.nl>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 16:41:29 by rmaes             #+#    #+#             */
/*   Updated: 2022/06/13 17:17:39 by rmaes            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft.h"

void	*ft_bzero(void *e, size_t len)
{
	size_t	a;

	a = 0;
	while (a < len)
	{
		((char *)e)[a] = 0;
		a++;
	}
	return (e);
}
