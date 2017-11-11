//Importe de librerias

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

//Primera parte del ejercicio

#define L 0.64 //Longitud de la cuerda en m.
#define c 250 //Velocidad de propagacion de la onda en m/s.
#define t 100000 //Tiempo en s.
#define dx 0.005 //Delta x de
#define dt 0.000004 //Delta t para un r=0.8

//Main
int main(){



//Lectura de datos
	float *actuales = malloc(129*sizeof(float));
	FILE* datos;
	datos = fopen("cond_ini_cuerda.dat", "r");
	int i;
	float *x = malloc(129*sizeof(float));
	float *Fx = malloc(129*sizeof(float));
	for(i=0; i<129; i++){
		fscanf(datos, "%f %f\n", &x[i], &Fx[i]);
		actuales[i] = Fx[i];
		//printf("%lf %lf\n",x[i], Fx[i]);
		//printf("%lf\n",actuales[i]);	
		}
	fclose(datos);

//Solucion ecuacion de onda en 1D
	
	FILE* resultados = fopen("resultados.dat","w");
	float* t_anteriores = malloc(129*sizeof(float));
	float* nuevas = malloc(129*sizeof(float));
	int j;
	float amp;
	float r;
	nuevas[0] = 0.0;
	nuevas[128] = 0.0;


	for(i=0;i<128;i++)
	{
    		t_anteriores[i] = Fx[i];
		actuales[i] = t_anteriores[i] + ((pow(r,2))/2)*(t_anteriores[i+1] - 2*t_anteriores[i] + t_anteriores[i-1]);	
				
	}
	
	for(j=1;j<=t;j++)
	{
		for(i=1;i<128;i++)
		{
			nuevas[i] = 2*(1-pow(r,2))*actuales[i] - t_anteriores[i] + (pow(r,2)*(actuales[i+1] + actuales[i-1]));
		}

		for(i=1;i<128;i++)
		{
			t_anteriores[i]=actuales[i];
			actuales[i]=nuevas[i];
			//printf("%f\n",actuales[i]);

			if(j%62500 == 0)
			{
				//printf("%f \n", actuales[i]);			
				fprintf(resultados,"%f ",actuales[i]);
			
			}
	
		}
	}
		

	
	
return 0;
}

