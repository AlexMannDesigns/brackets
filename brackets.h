/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   brackets.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:37:56 by amann             #+#    #+#             */
/*   Updated: 2021/12/02 11:12:52 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRACKETS_H
# define BRACKETS_H

# include <stdio.h>
# include <unistd.h>

typedef struct s_list
{
	char			b;
	struct s_list 	*next;
}					t_list;

void	ft_putchar(char c);
void	ft_putstr(char *s);

#endif
