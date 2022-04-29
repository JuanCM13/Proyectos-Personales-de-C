
#ifndef CALCULADORA_H_
#define CALCULADORA_H_

void Desplegar_menu(int* opcion);
int Get_numero(char[] , float*);
int Get_suma(float , float , float*);
int Get_resta(float , float , float*);
int Get_division(float , float , float*);
int Get_multiplo(float operadorUno , float operadorDos , float* resultado);
int Get_factorial(float operador , long long int* factorial , int* verificacion);
int Es_factorial(float operador);

#endif /* CALCULADORA_H_ */
