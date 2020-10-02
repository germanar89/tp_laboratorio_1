#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"

#define TAME 4

int main()
{
    Resultadose salarios;
    Employee list[TAME];
    int i;
    int id=1000;
    int idBusqueda;
    int indice;
    int sectorModificar;
    int idRemove;
    int flag=0;
    char nombreModificar[51];
    char ApellidoModificar[51];
    char salir = 'n';
    char salir2 = 'n';
    char salir3 ='n';
    char order[4];
    float salarioModificar;



    initEmployees(list,TAME);



    do
    {

        switch(menu())//MENU PRINCIPAL
        {
        case 1:
            //SE CARGA UN EMPLEADO DATO A DATO
            loadEmployee(list,TAME,id);
            id++;
            flag=1;
            break;

        case 2:

            //MUESTRO LOS EMPLEADOS CARGADOS PARA QUE ELIJAN EL ID A MODIFICAR
            if(flag)
            {
                printEmployees(list,TAME);
                fflush(stdin);

                //SE TOMA EL ID A MODIFICAR
                printf("Ingrese ID a modificar\n");
                scanf("%d", &idBusqueda);

                //SE BUSCA EL ID Y SE DEVUELVE EL INDICE EN EL ARRAY
                indice =findEmployeeById(list,TAME,idBusqueda);
                if (indice != -1)
                {


                    do
                    {
                        switch(subMenuModificar())//MENU MODIFICAR
                        {
                        case 1:
                            //CAMBIO EL NOMBRE
                            fflush(stdin);
                            printf("ingrese nuevo nombre: \n");
                            scanf("%s", nombreModificar);
                            strcpy(list[indice].name,nombreModificar);
                            break;

                        case 2:
                            //CAMBIO EL APELLIDO
                            fflush(stdin);
                            printf("ingrese nuevo Apellido: \n");
                            scanf("%s", ApellidoModificar);
                            strcpy(list[indice].lastName,ApellidoModificar);
                            break;

                        case 3:

                            //CAMBIO EL SALARIO
                            fflush(stdin);
                            printf("ingrese nuevo Salario: \n");
                            scanf("%f", &salarioModificar);
                            list[indice].salary = salarioModificar;
                            break;

                        case 4:

                            //CAMBIO EL SECTOR
                            fflush(stdin);
                            printf("ingrese nuevo sector: \n");
                            scanf("%d", &sectorModificar);
                            list[indice].sector = sectorModificar;
                            break;

                        case 5:

                            //SALIR EL MANU ANTERIOR

                            fflush(stdin);
                            printf("desea salir? s/n ");
                            scanf("%c", &salir3);

                            break;
                        default:

                            printf("ingrese una opcion valida \n");


                        }
                    }
                    while(salir3 =='n');
                }
                else
                {
                    printf("El ID no existe \n\n");
                    system("pause");
                }
            }
            else
            {
                printf("Debe ingresar un dato primero \n\n");
                system("pause");
            }

            break;
        case 3:
            if(flag)
            {
                printEmployees(list,TAME);
                fflush(stdin);
                printf("ingrese ID a remover\n");
                scanf("%d",&idRemove);
                removeEmployee(list,TAME,idRemove);
            }
            else
            {
                printf("Debe ingresar un dato primero \n\n");
                system("pause");
            }
            break;
        case 4:
            if (flag)
            {


                do
                {
                    switch (subMenu())//MENU DE INFORMES
                    {
                    case 1:
                        //SE MUESTRAN ORDENADOS LOS DATOS POR APELLIDO ALFABETICAMENTE SEGUN SE INDIQUE CON EL ORDEN UP/DOWN
                        fflush(stdin);
                        printf("elija criterio de ordenamiento: UP/DOWN \n");
                        gets(order);
                        if(stricmp(order,"UP")==0)
                        {
                            sortEmployees(list,TAME,0);
                            printEmployees(list,TAME);
                        }
                        else if(stricmp(order,"DOWN")==0)
                        {
                            sortEmployees(list,TAME,1);
                            printEmployees(list,TAME);
                        }
                        else
                        {
                            printf("elija opcion valida \n");

                        }
                        system("pause");
                        break;

                    case 2:
                        salarios=promedioSalarios(list,TAME);
                        printf("Salario promedio: %2.f\nPersonas que superan el salario promedio: %0.f\nTotal salarios: %2.f\n",salarios.salarioPromedio,salarios.salariosAltos,salarios.suma);
                        system("pause");
                        break;

                    case 3:

                        fflush(stdin);
                        printf("desea retroceder al menu anterior? s/n \n");
                        scanf("%c", &salir2);

                        break;
                    default:

                        printf("ingrese una opcion valida \n");
                        system("pause");
                    }

                }

                while(salir2 =='n');


            }
            else
            {
                printf("Debe ingresar un dato primero \n\n");
                system("pause");
            }
            break;
        case 5:
            fflush(stdin);
            printf("desea salir? s/n ");
            scanf("%c", &salir);
            break;
        default:

            printf("ingrese una opcion valida \n");


        }
    }
    while(salir =='n');



    return 0;
}
