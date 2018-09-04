#include "fractol.h"




//void    ft_win(t_struct *ptr)
//{
//	ptr->win.x = (ptr->mon.x * ((double)VW / (double)CW));
//	ptr->win.y = (ptr->mon.y * ((double)VH / (double)CH));
//	ptr->win.z = (double)2;
////	ptr->d = 1;
//}
//
//double  ft_dot(t_coord s1, t_coord s2)
//{
//	return ((s1.x * s2.x) + (s1.y * s2.y) + (s1.z * s2.z));
//}
//
//void    ft_int_sect_ray(t_struct *ptr)
//{
//	ptr->oc.x = ((double)ptr->cam.x - (double)ptr->sfr.center.x);
//	ptr->oc.y = ((double)ptr->cam.y - (double)ptr->sfr.center.y);
//	ptr->oc.z = ((double)ptr->cam.z - (double)ptr->sfr.center.z);
//
//	double k1 = (double)ft_dot(ptr->win, ptr->win);
//	double k2 = ((double)2 * (double)ft_dot(ptr->oc, ptr->win));
//	double k3 = ((double)ft_dot(ptr->oc, ptr->oc) - (double)sqrt(ptr->sfr.r));
//
//	double discrim = (double)k2 * (double)k2 + 4 * (double)k1 * (double)k3;
//	if ((double)discrim < 0)
//	{
//		ptr->t1 = (double)ptr->t;
//		ptr->t2 = (double)ptr->t;
////		printf("1\n");
//		return ;
//	}
//	ptr->t1 = (-k2 + sqrt(discrim)) / (2 * k1);
//	ptr->t2 = (-k2 - sqrt(discrim)) / (2 * k1);
//	return ;
//}
//
//int     ft_trace_ray(t_struct *ptr, double t_min, double t_max)
//{
//	double sf_t = t_max;
//	double close = 0;
//	ft_int_sect_ray(ptr);
//
//	if (ptr->t1 >= 1 && ptr->t1 <= ptr->t)
//	{
//		sf_t = ptr->t1;
//		close = 1;
//	}
////	if (ptr->t2 >= 1 && ptr->t2 <= ptr->t)
////	{
////		sf_t = ptr->t2;
////		close = 0;
////	}
//	if (close == 0)
//		return (0);
//	return (((256 * 256 * ptr->sfr.color.x) + (256 * ptr->sfr.color.y) + ptr->sfr.color.z));
//}
//

void    ft_D(t_struct *ptr)
{
	ptr->D.x = ptr->mon.x * ((double)VW / (double)CW);
	ptr->D.y = ptr->mon.y * ((double)VH / (double)CH);
	ptr->D.z = 1;
}

void    ft_intersect(t_struct *ptr)
{
	ptr->oc.x = ((double)ptr->cam.x - (double)ptr->sfr.center.x);
	ptr->oc.y = ((double)ptr->cam.y - (double)ptr->sfr.center.y);
	ptr->oc.z = ((double)ptr->cam.z - (double)ptr->sfr.center.z);

	double k1 = (double)ft_dot(ptr->D, ptr->D);
	double k2 = ((double)2 * (double)ft_dot(ptr->oc, ptr->D));
	double k3 = ((double)ft_dot(ptr->oc, ptr->oc) - (double)sqrt(ptr->sfr.r));

	double discrim = (double)k2 * (double)k2 + 4 * (double)k1 * (double)k3;
	if ((double)discrim < 0)
	{
		ptr->t1 = (double)ptr->t;
		ptr->t2 = (double)ptr->t;
//		printf("1\n");
		return ;
	}
	ptr->t1 = (-k2 + sqrt(discrim)) / (2 * k1);
	ptr->t2 = (-k2 - sqrt(discrim)) / (2 * k1);
	return ;
}

void    close_ft(t_struct *ptr, int t_min, int t_max)
{
	int closest_t = t_max;
	int closest_sfr = 0;
	
	ft_inersect(ptr);
	
	
}

void    trace_ray(t_struct *ptr, int t_min, int t_max)
{
	close_ft(ptr, t_min, t_max);
}

void    ft_main(t_struct *ptr)
{
	ptr->mon.x = CW / 2 * -1;


	while (ptr->mon.x < (double)CW / 2)
	{
		ptr->mon.y = (double)CH / 2 * -1;
		while (ptr->mon.y < (double)CH / 2)
		{
			ft_D(ptr);
			int color = ft_trace_ray(ptr, 1, ptr->t);
			if (color != 0)
				mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, ptr->mon.x + CW / 2, ptr->mon.y + CH / 2, color);
			ptr->mon.y++;
		}
		ptr->mon.x++;
	}
}