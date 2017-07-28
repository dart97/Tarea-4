#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int Nx;
int Ny;
int N = 120877;
int d = 2;

void freePointer(int**matriz);
double Calcula_radio(double x0, double y0, double *x, double *y);
///int periodicidadc(int j,int contador );
///int periodicidadf(int i, int contador);
void genera_indice(double *x, double *y, double **m);
double func_random(void);
double MonteCarlo(double *x, double *y,double **matriz);

int main(void)
{
    int i, j;

 	int filas = 500;
 	int columnas = 744;
 	double **matriz = malloc(filas*sizeof(double));
 	double *x = malloc(sizeof(double));
 	double *y = malloc(sizeof(double));


 	for (i = 0; i < filas; ++i)
 	{
 		matriz[i]= malloc(columnas*sizeof(double));

 	}
 	FILE *mapamundi;
 	mapamundi = fopen("map_data.txt","r");
 	for (i = 0; i < filas; ++i)
 	{
 		for (j = 0; j < columnas; ++j)
 		{
 			fscanf(mapamundi,"%f\n",&matriz[i][j]);
 		}


 	}
 	
 	MonteCarlo(x,y,matriz);
 	
 	///Calcula_radio(400,100, x , y);
 	///printf("%d\n",periodicidadc(743,1));
 	///printf("%d\n",periodicidadf(499,1));
    return 0;
}


void freePointer(int **matriz)
{
    int i;
    for(i = 0; i<Ny; i++)
    {
        free(matriz[i]);
    }
    free(matriz);
}

double MonteCarlo(double *x, double *y, double **matriz)
	{
		FILE *mapamundi;
		mapamundi = fopen("mapamundi.txt","w+");
		double x_nuevo;
		double x_viejo;
		double y_viejo;
		double y_nuevo;
		double r_nuevo;
		double r_ultimo;
		double alfa;
		

		x_viejo = 2*func_random() *N/500;
		y_viejo = 2*func_random() *N/744;
		r_ultimo = Calcula_radio(x_viejo,y_viejo,x,y);

		int i;
		for ( i = 0; i < 1000; ++i)
		{
			x_nuevo = x_viejo + (2*func_random()-1)*d;
			y_nuevo = y_viejo + (2*func_random()-1)*d;

			if(x_nuevo<0)
			{
				x_nuevo = 744 - x_nuevo;

			}

			if(x_nuevo>744)
			{
				x_nuevo = x_nuevo - 744;
			}

			if(y_nuevo<0)
			{
				y_nuevo = 744 - y_nuevo;
			}

			if(y_nuevo>500)
			{
				y_nuevo = y_nuevo - 500;
			}

			r_nuevo = Calcula_radio(x_nuevo,y_nuevo,x,y);
			alfa = exp((r_nuevo - r_ultimo));

			if(alfa > 1)
			{
				alfa = 1;
			}

			if(alfa > func_random())
			{
				x_viejo = x_nuevo;
				y_viejo = y_nuevo;
				r_ultimo = r_nuevo;
			}
			fprintf(mapamundi,"%f %f %f\n", x_viejo, y_viejo, r_ultimo);

		}
	}	

double func_random(void)
{
    return (double) rand()/RAND_MAX;
}


double Calcula_radio(double x0, double y0,double *x, double *y)
{
    int i;
    double min, value;
    min = pow(pow(x[0] - x0, 2.0) + pow(y[0] - y0, 2.0), 0.5);
    for(i = 1; i<N; i++)
    {
        value = pow(pow(x[i] - x0, 2.0) + pow(y[i] - y0, 2.0), 0.5);
        if(value < min)
        {
            min = value;
        }
    }
    return min;
}

void genera_indice(double *x, double *y, double **m){
	int i;
	int j;
	int c = 0;
	for (int i = 0; i < 500; ++i)
	{
		for (int j = 0; i < 744; ++j)
		{
			if(m[i][j]== 1)
			{
				x[c]= i;
				y[c]= j;
				c = c+1;
			}
		}
	}
}

/*int periodicidadc(int j,int contador ){
	int c;
	
	if (j+contador > 743)
		{
			c = (j+contador) - 744;
			return c;
		}
}

int periodicidadf(int i, int contador){
d	int b;

	if(i+contador > 499)
		{
			b = (i+contador) -500;
			return b;
		}
}*/





