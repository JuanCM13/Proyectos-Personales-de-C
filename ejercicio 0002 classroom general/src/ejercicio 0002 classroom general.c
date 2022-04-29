/*
 ============================================================================
- Limpie la pantalla
- Asigne a las variables numero1 y numero2 los valores obtenidos
- Realice la resta de dichas variables
- Muestre el resultado por pantalla
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>


int main(void) {

	setbuf(stdout, NULL);

	int numeroUno;
	int numeroDos;
	int resta;

	printf("ingresa un numero: \n");
	scanf("%d",&numeroUno);

	printf("ingresa otro numero: \n");
	scanf("%d",&numeroDos);

	resta = numeroUno - numeroDos;

	printf("El resultado es: %d\n",resta);

}
