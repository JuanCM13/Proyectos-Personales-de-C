//MENDEZ JUAN CRUZ DIV 1C TP2

#include "informes.h"


#define TAM 1000


int main(void)
{

    setbuf(stdout , NULL);

    Employee workList[TAM];/* =     //DATOS PARA HARDCODEAR, DESCOMENTAR Y SACAR ; Y DESCOMENTAR EL CONTADOR DEBAJO ASI ARRANCA EN 5
                            {{1,"Mauricio", "Macri" , 45800 , 3 , 0},
                            {2,"Alberto", "Fernandez" , 50000 , 1 , 0},
                            {4,"Carlos", "Menem" , 80000 , 1 , 0},
                            {3,"Cristina", "Fernandez" , 60000 , 2 , 0},
                            {5,"Nestor", "Kirchner" , 10000 , 2 , 0}};
                            for(int i =5 ; i<TAM ; i++)
                            {
                                workList[i].isEmpty = 1;
                            } */
    int contadorId;
    contadorId = 0;
    //contadorId = 5; //esto es para que por el hardcodeo no inicie en 1 de nuevo.. comentar o descomentar

    int respuesta;




    if(initEmployees(workList , TAM) != 0)
    {
        printf("Algo salio mal con la carga...\n");
    }

    do
    {
        if(DeployMenu(&respuesta) != 0)
        {
            printf("Algo salio mal reintente..\n");
        }

        switch(respuesta)
        {
            case 1:

                informeAlta(workList , TAM, contadorId , &contadorId);

            break;

            case 2:

                informeMod(workList , TAM);

            break;

            case 3:

                informeBaja(workList , TAM);

            break;

            case 4:

                informeResultadosOrdenamientoYpromedios(workList , TAM);

            break;
            case 5:
                printEmployees(workList , TAM);
            break;
        }

    }while(respuesta != 6);

    printf("\n\n-------------------FINALIZO EL PROGRAMA---------------------------");
    return 0;
}


