/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amann <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 15:35:12 by amann             #+#    #+#             */
/*   Updated: 2021/12/02 17:42:53 by amann            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "brackets.h"

//should handle multiple strings, output newline if no args
//if good: OK\n if bad: Error\n
//Brackets, square brackets and braces should be considered brackets
//A string with no brackets is ok

int		check_and_update_previous(char *s, char a, int i)
{
	while (i >= 0)
	{	
		if (a == ')')
		{
			if (s[i] == '(')
			{
				s[i] = 'a';
				return (1);
			}
			else if (s[i] == '{' || s[i] == '[')
				return (0);
		}
		else if (a == ']')
		{
			if (s[i] == '[')
			{
				s[i] = 'a';
				return (1);
			}
			else if (s[i] == '(' || s[i] == '{')
				return (0);
		}
		else if (a == '}')
		{
			if (s[i] == '{')
			{	
				s[i] = 'a';
				return (1);
			}
			else if (s[i] == '(' || s[i] == '[')
				return (0);
		}
		i--;
	}
	return (0);
}

int		ft_strlen(char *str)
{
	int i = 0;
	while (str[i] != '\0')
	   i++;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

int		checkbrackets(char *str)
{
	int i;
	char a;
 	char s[ft_strlen(str)];
	
	ft_strcpy(s, str);
	i = 0;
	while (s[i] != '\0')
	{
		a = s[i];
		if (a == ')' || a == ']' || a == '}')
		{
			if (!check_and_update_previous(s, a, i))
				return (0);
		}
		i++;
	}
	i = 0;
	while (s[i] != '\0')
	{
		a = s[i];
		if (a == '(' || a == '[' || a == '{')
			return (0);
		i++;
	}
	return (1);
}	

void	checkbrackets_control(char **argv)
{
	int i;

	i = 0;
	while (argv[i])
	{
		if (checkbrackets(argv[i]))
			ft_putstr("OK\n");
		else
			ft_putstr("Error\n");
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc != 1)
		checkbrackets_control(argv + 1);
	else
		ft_putchar('\n');
	return (0);
}
