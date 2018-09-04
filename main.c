#include "fractol.h"


int		exit_x(t_struct *ptr)
{
	mlx_destroy_window(ptr->mlx_ptr, ptr->mlx_win);
	ptr = NULL;
	exit(0);
}

int		deal_key(int key, t_struct *ptr)
{
	if (key == 53)
		exit(0);
	
	return (0);
}

void    ft_asigned(t_struct *ptr)
{

	ptr->Cw = ptr->Ch = 700;
	ptr->Vw = ptr->Vh = ptr->Vz = ptr->d = 1;

	ptr->t = 0.5;

	ptr->O.x = 0;
	ptr->O.y = 0;
	ptr->O.z = 0;

	//Initialization sphere
	ptr->sfr.center.x = 2;
	ptr->sfr.center.y = 0;
	ptr->sfr.center.z = 4;

	ptr->sfr.r = 1;

	ptr->sfr.color.x = 255;
	ptr->sfr.color.y = 0;
	ptr->sfr.color.z = 0;


}
//
//
//void    ft_cam_p(t_struct *ptr)
//{
//	ptr->P.x = ptr->O.x + ptr->t * (ptr->Vx - ptr->O.x);
//	ptr->P.y = ptr->O.y + ptr->t * (ptr->Vy - ptr->O.y);
//	ptr->P.z = ptr->O.z + ptr->t * (ptr->Vz - ptr->O.z);
//}
//
//void    ft_solve(t_struct *ptr)
//{
//	int x , y;
//
//	x = -(ptr->Cw / 2);
//
//	while (x++ < ptr->Cw / 2)
//	{
//		y = -(ptr->Ch / 2);
//		while (y++ < ptr->Ch / 2)
//		{
//			ptr->Vx = (ptr->Vw / ptr->Cw) * x;
//			ptr->Vy = (ptr->Vh / ptr->Ch) * y;
//			ft_cam_p(ptr);
//			printf("%f\n", ptr->P.z);
//			printf("%f\n", ptr->Vx);
//		}
//	}
//}
//
//

double  ft_dot(t_coord s1, t_coord s2)
{
	return ((s1.x * s2.x) + (s1.y * s2.y) + (s1.z * s2.z));
}


void    ft_D(t_struct *ptr, int x, int y)
{
	ptr->D.x = x * (ptr->Vw / ptr->Cw);
	ptr->D.y = y * (ptr->Vh / ptr->Ch);
	ptr->D.z = ptr->d;
}

//t1,t2;
void    InterSectRay(t_struct *ptr)
{
	//OC;
	ptr->oc.x = ptr->O.x - ptr->sfr.center.x;
	ptr->oc.y = ptr->O.y - ptr->sfr.center.y;
	ptr->oc.z = ptr->O.z - ptr->sfr.center.z;
	
	ptr->k1 = ft_dot(ptr->D, ptr->D);
	ptr->k2 = 2 * ft_dot(ptr->oc, ptr->D);
	ptr->k3 = ft_dot(ptr->oc, ptr->oc) - ptr->sfr.r * ptr->sfr.r;
	
	double discrim = ptr->k2 * ptr->k2 - 4 * ptr->k1 * ptr->k3;
	
	if (discrim < 0)
	{
		ptr->t1 = 10000000;
		ptr->t2 = 10000000;
//		printf("1111");
		return ;
	}
	ptr->t1 = (-ptr->k2 + sqrt(discrim)) / (2 * ptr->k1);
	ptr->t2 = (-ptr->k2 - sqrt(discrim)) / (2 * ptr->k1);
//	printf("%f\n", ptr->t2);
}

void    closeinter(t_struct *ptr, double t_min, double t_max)
{
	ptr->inf = 10000000;
	ptr->sf = 0;
	InterSectRay(ptr);//t1,t2
	if (ptr->t1 >= t_min && ptr->t1 < t_max)
	{
		ptr->inf = ptr->t1;
		ptr->sf = 1;
//		printf("inf = %f\n", ptr->inf);
	}
	if (ptr->t2 >= t_min && ptr->t2 < t_max)
	{
		ptr->inf = ptr->t2;
		ptr->sf = 1;
//		printf("sf = %f\n", ptr->sf);
	}
	
	
}

void    ft_N(t_struct *ptr)
{
	ptr->N.x = ptr->P.x - ptr->sfr.center.x;
	ptr->N.y = ptr->P.y - ptr->sfr.center.y;
	ptr->N.z = ptr->P.z - ptr->sfr.center.z;
}

void    ft_P(t_struct *ptr)
{
	ptr->P.x = ptr->O.x + ptr->inf * ptr->D.x;
	ptr->P.y = ptr->O.y + ptr->inf * ptr->D.y;
	ptr->P.z = ptr->O.z + ptr->inf * ptr->D.z;
}


void    trace_ray(t_struct *ptr, double t_min, double t_max, int depth)
{
	closeinter(ptr, t_min, t_max);
	if (ptr->sf == 0)
	{
		ptr->color = 0xffffff;
		return;
	}
	printf("1");
}

void    ft_solve(t_struct *ptr)
{
	int x , y;

	x = -(ptr->Cw / 2);

	while (x++ < ptr->Cw / 2)
	{
		y = -(ptr->Ch / 2);
		while (y++ < ptr->Ch / 2)
		{
			ptr->Vx = (ptr->Vw / ptr->Cw) * x;
			ptr->Vy = (ptr->Vh / ptr->Ch) * y;
			ft_D(ptr, x, y);
			trace_ray(ptr, 1, 10000000, 500);
			
			ft_P(ptr);
			ft_N(ptr);
			
			mlx_pixel_put(ptr->mlx_ptr, ptr->mlx_win, x + ptr->Cw / 2, y + ptr->Ch / 2, ptr->color);
//			printf("%f\n", ptr->oc.x);
//			printf("%f\n", ptr->Vx);
		}
	}
}

int main(int argc, char *argv[])
{
	t_struct ptr[1];


	ft_asigned(ptr);
	




	ptr->mlx_ptr = mlx_init();
	ptr->mlx_win = mlx_new_window(ptr->mlx_ptr, ptr->Cw, ptr->Ch, "RTv_1");
	
	ft_solve(ptr);








	mlx_hook(ptr->mlx_win, 17, 1L << 17, exit_x, ptr);
	mlx_hook(ptr->mlx_win, 2, 5, deal_key, ptr);
	mlx_loop(ptr->mlx_ptr);
	return (0);
}
