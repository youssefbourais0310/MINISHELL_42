/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ybourais <ybourais@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/30 17:44:20 by ybourais          #+#    #+#             */
/*   Updated: 2022/10/23 17:17:43 by ybourais         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int str)
{
	if ((str >= '0' && str <= '9') || (str >= 'A' && str <= 'Z') || (str >= 'a'
			&& str <= 'z'))
		return (1);
	return (0);
}
