/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverb.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddratini <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 03:23:24 by ddratini          #+#    #+#             */
/*   Updated: 2019/07/10 18:48:09 by ddratini         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
void  printb(unsigned char octet)
{
		int i;
		int buf;
			
		i = 128;
	while (i != 0)
	{
			buf = octet & i;
			i /= 2;
			if (buf > 0)
			{
				write(1, "1", 1);
			}
			else if (buf == 0)
			{
				write(1, "0", 1);
			}
	}
}
unsigned int		rev_bit(unsigned char octet)
{
	unsigned char f;
/*	octet = octet << 7 | octet >> 1;
	octet = octet << 6 | octet >> 2;
	octet = oc tet << 5 | octet >> 3;
	octet = octet << 6 | octet >> 2;
//	octet = octet << 7 | octet >> 1;
*/
	f = 0; // \0?
	f += (octet & 1) << 7;
	f += (octet & 2) << 5;
	f += (octet & 4) << 3;
	f += (octet & 8) << 1;
	f += (octet & 16) >> 1;
	f += (octet & 32) >> 3;
	f += (octet & 64) >> 5;
	f += (octet & 128) >> 7;
	printb(octet);
	printf("\n");
	printb(f);
	return(octet);
}/*
int main()
{
	unsigned char a = 23;
	rev_bit(a);
}*/
