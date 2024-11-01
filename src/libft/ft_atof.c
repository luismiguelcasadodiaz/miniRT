/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luicasad <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/01 10:35:43 by luicasad          #+#    #+#             */
/*   Updated: 2024/11/01 10:35:54 by luicasad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* my_isspace checks for white-space characters.                           */
/*                                                                         */
/*  In "C" and "POSIX" locales, these  are: space (' '), form-feed ('\f')  */
/*  newline ('\n'), carriage return ('\r'), horizontal tab ('\t'), and     */
/*  vertical tab ("\v")                                                    */
/*                                                                         */
/* RETURNS:                                                                */
/*  0 (false) if c is not an space                                         */
/*  1 (true)  if c belong to the "space" set                               */
/*                                                                         */
static int	my_isspace(int c)
{
	int	result;

	result = ((char)c == ' ');
	result = (result || ((char)c == '\f'));
	result = (result || ((char)c == '\n'));
	result = (result || ((char)c == '\r'));
	result = (result || ((char)c == '\t'));
	result = (result || ((char)c == '\v'));
	return (result);
}

/* ft_atof() converts the INITIAL portion of the string pointed to by nptr to */
/* int.                                                                       */
/*                                                                            */
/* RETURNS                                                                    */
/* The converted value or 0 on error.                                         */
/*                                                                            */
/* OPERATION                                                                  */
/* 1.-skip leading spaces                                                     */
/* 2.-Sign defaults to positive (= 1).  when signs is negative substract 2    */
/*    from the sing. if sign exists, skip it (idx++).                         */
/* 3. evaluate all consecutive digits                                         */
/* 4. retunr total times sign (+/- 1)                                         */
/*                                                                            */
float	ft_atof(const char *s)
{
	float	entera;
    float   decimal;
	int		len;
	int		idx;
	short	sign;

	sign = 1;
	entera = 0;
    decimal = 0;
	len = ft_strlen(s);
	idx = 0;
	while ((my_isspace(s[idx])) && idx <= len)
		idx++;
	if ((s[idx] == '-') || (s[idx] == '+'))
		sign -= 2 * (s[idx++] == '-');
	while (ft_isdigit(s[idx]))
		entera = entera * 10 + (s[idx++] - '0');
    if ((s[idx] == '.') || (s[idx] == ','))
    {
        idx++;
        while (ft_isdigit(s[idx]) && (idx <= len))
		    decimal = decimal / 10.0 + (s[idx++] - '0');
    }
   	return ((entera + decimal) * sign);
}
