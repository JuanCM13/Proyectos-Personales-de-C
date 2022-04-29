/*
 * MENDEZ JUAN CRUZ DIV 1-C
 *
Ejercicio 1-1:
Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
a) El promedio de los números positivos.
b) El promedio de los números negativos.Ejercicio 1-1:
Ingresar números enteros, hasta que el usuario lo decida. Calcular y mostrar:
a) El promedio de los números positivos.
b) El promedio de los números negativos.
 */

#include <stdio.h>
#include <stdlib.h>


int main(void)

{
	setbuf(stdout, NULL);

	char respuesta;
	int i;
	int numero;
	int contadorP;
	int contadorN;
	int acumuladorP;
	int acumuladorN;

	contadorP=0;
	contadorN=0;
	acumuladorP=0;
	acumuladorN=0;

	respuesta==('s');

	while(respuesta=='s')
	{
		printf("Ingresa un numero: --LLevas ingresados %d numeros\n",i);
		scanf("%d",&numero);

		if(numero>0)
		{
			contadorP++;
			acumuladorP+=numero;
		}
		else
		{
			contadorN++;
			acumuladorN+=numero;
		}

		printf("seguimos? y/n\n");
		fflush(stdin);
		scanf("%c",&respuesta);

	}

	printf("El promedio de positivos es: %d \n el promedio de negativos es: %d\n");
}
