/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvoronyu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/08/19 14:02:48 by tvoronyu          #+#    #+#             */
/*   Updated: 2018/08/19 14:16:38 by tvoronyu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdio.h>
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include "minilibx_macos/mlx.h"
# include "libft/libft.h"
# include <pthread.h>
//# define CW 700
//# define CH 700
//# define VW 700
//# define VH 700

typedef struct s_coord
{
	double x;
	double y;
	double z;
}       t_coord;

typedef struct s_sphere
{
	t_coord center;
	double r;
	t_coord color;
}       t_sphere;

typedef struct s_struct
{
	t_coord cam;
	t_coord mon;
	t_coord win;
	t_coord D;
	t_coord O;
	t_coord P;
	t_coord R;
	t_coord N;
	t_sphere sfr;
	t_sphere sfr_2;
	t_sphere sfr_3;
	t_coord oc;
	
	double degree;
	
	double  d;
	
	double  t;
	
	double  t1;
	double  t2;
	
	void   *mlx_ptr;
	void   *mlx_win;
	char   *mlx_addr;
	void   *mlx_img;
	
	double it_1;
	double it_2;
	
	double Ch;
	double Cw;
	double Vh;
	double Vw;
	double Vz;
	double Vx;
	double Vy;
	
	double k1;
	double k2;
	double k3;
	
	double inf;
	double sf;
	
	int color;

}  t_struct;


//void    ft_main(t_struct *ptr);
int		exit_x(t_struct *ptr);

#endif