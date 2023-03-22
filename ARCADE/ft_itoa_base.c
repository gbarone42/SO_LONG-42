/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                      :+:      :+:    :+:  */
/*                                                    +:+ +:+         +:+     */
/*   By: gbarone <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/15 15:57:38 by gbarone           #+#    #+#             */
/*   Updated: 2023/03/15 15:57:40 by gbarone          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*
#include "so_long.h"

int		ft_abs(int nb)
{
	if (nb < 0)
		nb = -nb;
	return (nb);
}

char	*ft_itoa_base(char *value,long unsigned int base)
{
	char	*str;
	int		size;
	char	*tab;
	int		flag;
	int		tmp;
	flag = 0;
	size = 0;
	tab = "0123456789ABCDEF";
	if (base < 2 || base > 16)
		return (0);
	if (value < 0 && base == 10)
		flag = 1;
	tmp = value;
	while (tmp /= base)
		size++;
	size = size + flag + 1;
	str = (char *)malloc(sizeof(char) * size  + 1);
	str[size] = '\0';
	if (flag == 1)
		str[0] = '-';
	while (size > flag)
	{
		str[size - 1] = tab[ft_abs(value % base)];
		size--;
		value /=base;
	}
	return (str);
}



void	fck_line(t_program *p, void *spr, int x)
{
	int	i;

	i = p->num.pos_x;
	mlx_put_image_to_window(p->mlx, p->win.win, spr, i * SIZE - x, 20);
}

void	ft_destroy_num(t_program *p)
{
	mlx_destroy_image(p->mlx, p->num.zero);
	mlx_destroy_image(p->mlx, p->num.one);
	mlx_destroy_image(p->mlx, p->num.two);
	mlx_destroy_image(p->mlx, p->num.three);
	mlx_destroy_image(p->mlx, p->num.four);
	mlx_destroy_image(p->mlx, p->num.five);
	mlx_destroy_image(p->mlx, p->num.six);
	mlx_destroy_image(p->mlx, p->num.seven);
	mlx_destroy_image(p->mlx, p->num.eight);
	mlx_destroy_image(p->mlx, p->num.nine);
}

void	ft_number_sprite(t_program *p)
{
	static int	x = 7;
	static int	y = 10;

	p->num.zero = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/0.xpm",
			&x, &y);
	p->num.one = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/1.xpm",
			&x, &y);
	p->num.two = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/2.xpm",
			&x, &y);
	p->num.three = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/3.xpm",
			&x, &y);
	p->num.four = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/4.xpm",
			&x, &y);
	p->num.five = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/5.xpm",
			&x, &y);
	p->num.six = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/6.xpm",
			&x, &y);
	p->num.seven = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/7.xpm",
			&x, &y);
	p->num.eight = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/8.xpm",
			&x, &y);
	p->num.nine = mlx_xpm_file_to_image(p->mlx, "./Textures/Num/9.xpm",
			&x, &y);
}

void	ft_put_num(t_program *p, int count, float x)
{
	if (count == 0)
		fck_line(p, p->num.zero, x);
	else if (count == 1)
		fck_line(p, p->num.one, x);
	else if (count == 2)
		fck_line(p, p->num.two, x);
	else if (count == 3)
		fck_line(p, p->num.three, x);
	else if (count == 4)
		fck_line(p, p->num.four, x);
	else if (count == 5)
		fck_line(p, p->num.five, x);
	else if (count == 6)
		fck_line(p, p->num.six, x);
	else if (count == 7)
		fck_line(p, p->num.seven, x);
	else if (count == 8)
		fck_line(p, p->num.eight, x);
	else if (count == 9)
		fck_line(p, p->num.nine, x);
}

void	ft_count_move(t_program *p)
{
	static int	count = 0;

	count++;
	if (count <= 9)
		ft_put_num(p, count, 25.5);
	else if (count <= 99)
	{
		ft_put_num(p, count % 10, 25.5);
		ft_put_num(p, count / 10, 33);
	}
	else if (count <= 999)
	{
		ft_put_num(p, count % 10, 25.5);
		ft_put_num(p, count / 10 % 10, 34);
		ft_put_num(p, count / 100, 41);
	}
}
*/
