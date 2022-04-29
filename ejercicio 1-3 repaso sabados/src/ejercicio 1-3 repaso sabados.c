/*
 ============================================================================

 MENDEZ JUAN CRUZ DIV 1-C

 Ejercicio 1-3:
Realizar el algoritmo que permita ingresar los datos de los alumnos de una división de
la UTN FRA, los datos solicitados son:
Legajo
Tipo cursada(L: &quot;libre&quot; - P: &quot;presencial&quot; – R: &quot;remota&quot;)
Cantidad de materias( mas de cero y menos de 8)
Sexo (F: “femenino” – M: “masculino” , O: “no binario”)
Nota promedio (entre 0 y 10)
Edad (validar)
Se debe informar de existir, o informar que no existe , en el caso que corresponda.
a) El Legajo del mejor promedio femenino.
b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
c) El promedio de nota por sexo.
d) La edad y legajo del que cursa más materias. (Sin importar su género)
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


int main(void)
{
	setbuf(stdout, NULL);

	char respuesta;
	int legajo;
	char tipo;
	int cantidad;
	char sexo;
	float nota;
	int edad;
	int flagMejorPormedioFemenino;
	int legajoMejorPromedioFemenino;
	float mayorNotaFemenina;
	int flagLegajoMasculinoMasJoven;
	int legajoMasculino;
	int edadMasJovenLegajo;
	float promedioNoBinario;
	int acumuladorNotaNoBinario;
	int contadorNoBinario;
	float promedioMasculino;
	int acumuladorNotaMasculino;
	int contadorMasculino;
	float promedioFemenino;
	int acumuladorNotaFemenino;
	int contadorFemenino;
	int flagMasMaterias;
	int cantidadMateriasMayor;
	int edadMasMaterias;
	int legajoMasMaterias;

	flagMasMaterias=1;
	flagLegajoMasculinoMasJoven=1;
	flagMejorPormedioFemenino=1;
	contadorNoBinario=0;
	acumuladorNotaNoBinario=0;
	contadorMasculino=0;
	acumuladorNotaMasculino=0;
	contadorFemenino=0;
	acumuladorNotaFemenino=0;


	do
	{
		printf("Ingrese el numero de legajo:\n");
		scanf("%d",&legajo);

		printf("Ingrese tipo de cursada: -----L--libre,P--presencial, R--remota\n");
		fflush(stdin);
		scanf("%c",&tipo);
		tipo=tolower(tipo);

		while(tipo!='l' && tipo!='r' && tipo != 'p')
		{
			printf("Error reingrese tipo de cursada: -----L--libre,P--presencial, R--remota\n");
			fflush(stdin);
			scanf("%c",&tipo);
			tipo=tolower(tipo);
		}

		printf("Ingrese la cantidad de materias.. entre 1 y 8:\n");
		scanf("%d",&cantidad);

		while(cantidad < 1 || cantidad > 8 )
		{
			printf("Error, reingrese la cantidad de materias.. entre 1 y 8:\n");
			scanf("%d",&cantidad);
		}

		printf("Ingrese el sexo-----F--femenino,M--masculimo, o--no binario \n");
		fflush(stdin);
		scanf("%c",&sexo);
		sexo=tolower(sexo);

		while(sexo!='f' && sexo!='m' && sexo != 'o')
		{
			printf("Error, reingrese el sexo-----F--femenino,M--masculimo, o--no binario \n");
			fflush(stdin);
			scanf("%c",&sexo);
			sexo=tolower(sexo);
		}

		printf("ingrese la nota, entre 0 y 10\n");
		scanf("%f",&nota);

		while(nota < 0 || nota > 10)
		{
			printf("Error, reingrese la nota, entre 0 y 10\n");
			scanf("%f",&nota);
		}

		printf("ingrese la edad, entre 18 y 100\n");
		scanf("%d",&edad);

		while(edad < 18 || edad > 100)
		{
			printf("Error, reingrese la edad, entre 18 y 100\n");
			scanf("%d",&edad);
		}

		//---------------------------------FIN VALIDACIONES-*---------------------------------------

		/*Se debe informar de existir, o informar que no existe , en el caso que corresponda.
a) El Legajo del mejor promedio femenino.
b) El legajo del más joven de los alumnos masculinos entre los que dan libre.
c) El promedio de nota por sexo.
d) La edad y legajo del que cursa más materias. (Sin importar su género)*/


		switch(sexo)
		{
		case 'f':

				contadorFemenino++;
				acumuladorNotaFemenino+=nota;

				if(flagMejorPormedioFemenino == 1 || mayorNotaFemenina < nota)
				{
					flagMejorPormedioFemenino=0;
					mayorNotaFemenina=nota;
					legajoMejorPromedioFemenino=legajo;
				}

			break;

		case 'm':

				contadorMasculino++;
				acumuladorNotaMasculino+=nota;

				if(tipo == 'l')
				{
					if(flagLegajoMasculinoMasJoven == 1 || edadMasJovenLegajo > edad )
					{
						flagLegajoMasculinoMasJoven=0;
						legajoMasculino=legajo;
						edadMasJovenLegajo=edad;
					}
				}

			break;

		default:

			contadorNoBinario++;
			acumuladorNotaNoBinario+=nota;

			break;

		}

//-------------------------FIN SWITCH---------------------------------

		//--------------C------------------------------

		if(flagMasMaterias==1 || cantidadMateriasMayor < cantidad)
		{
			flagMasMaterias=0;
			cantidadMateriasMayor=cantidad;
			edadMasMaterias=edad;
			legajoMasMaterias=legajo;

		}



		printf("seguimos?y/n \n");
		fflush(stdin);
		scanf("%c",&respuesta);
		respuesta=tolower(respuesta);

	}while(respuesta == 'y');

	if(contadorFemenino>0)
	{
		promedioFemenino=(float)acumuladorNotaFemenino/contadorFemenino;
	}
	else
	{
		promedioFemenino=0;
	}

	if(contadorMasculino>0)
	{
		promedioMasculino=(float)acumuladorNotaMasculino / contadorMasculino;
	}
	else
	{
		promedioMasculino=0;
	}

	if(contadorNoBinario>0)
	{
		promedioNoBinario=(float)acumuladorNotaNoBinario/contadorNoBinario;
	}
	else
	{
		promedioNoBinario=0;
	}


	//-------------------------PRINTEOS----------------------------------------

	//--------B

	if(flagLegajoMasculinoMasJoven == 0)
	{
		printf("El legajo del estudiante masculino mas joven que rinde libre es: %d \n",legajoMasculino);
	}
	else
	{
		printf("El legajo del estudiante masculino mas joven que rinde libre no se pudo conseguir \n");
	}

	//--------------A

	if(flagMejorPormedioFemenino == 0)
	{
		printf("El legajo del mejor promedio femenino es: %d\n",legajoMejorPromedioFemenino);
	}
	else
	{
		printf("El legajo del mejor promedio femenino no se pudo conseguir\n");
	}

	//------------------C

	printf("El promedio de notas de masculinos fue de: %f\n El promedio de notas de femenino fue de: %f\n El promedio de notas de no binarios fue de: %f \n ",promedioMasculino,promedioFemenino,promedioNoBinario);

	//-----------D

	if(flagMasMaterias == 0)
	{
		printf("La edad del alumno que cursa mas materias es: %d y su legajo fue Nª%d\n",edadMasMaterias,legajoMasMaterias);
	}


	return 0;


}
