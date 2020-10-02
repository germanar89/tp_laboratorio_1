#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include "ArrayEmployees.h"

/** \brief To indicate that all position in the array are empty,
 * this function put the flag (isEmpty) in TRUE in all
 * position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee list[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        list[i].isEmpty = 1;
    }
    return 0;
}

/** \brief add in a existing list of employees the values received as parameters
 * in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
 */

Employee addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int indice;
    Employee newEmp;

    indice=serchFree(list,len);
    if (indice == -1)
    {
        printf("No hay registros disponibles para cargar el empleado \n");
    }
    else
    {


        newEmp.id = id;
        strcpy(newEmp.name,name);
        strcpy(newEmp.lastName,lastName);
        newEmp.sector =sector;
        newEmp.salary =salary;
        newEmp.isEmpty = 0;

        ;
    }

    return newEmp;
}





/** \brief find an Employee by Id en returns the index position in array.
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
 *
 */
int findEmployeeById(Employee list[], int len,int id)
{
    int i;
    int indice = -1;


    for (i=0; i<len; i++)
    {
        if (list[i].id == id)
        {
            indice=i;
        }
    }

    return indice;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
 *
 * \param list Employee*
 * \param len int
 * \param id int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
 *
 */
int removeEmployee(Employee list[], int len, int id)
{
    char opcion;
    int indice;

    indice=findEmployeeById(list,len,id);


    printf("%5d %10s %10s %2.f 2%d\nDesea eliminarlo s/n\n",list[indice].id,list[indice].lastName,list[indice].name,list[indice].salary,list[indice].sector);
    fflush(stdin);
    scanf("%c",&opcion);
    if(indice!=-1 && opcion== 's')
    {
        list[indice].isEmpty=1;

        printf("baja exitosa\n");
        system("pause");

    }
    else
    {
        printf("baja no realizada\n");
        system("pause");
    }
    return -1;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
 *
 * \param list Employee*
 * \param len int
 * \param order int [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int sortEmployees(Employee list[], int len, int order)
{
    Employee auxEmployee;
    int i;
    int j;

    if (order == 1)
    {
        for (i=0; i<(len -1); i++)
        {
            for(j=i+1; j<len; j++)
            {
                if (stricmp(list[i].lastName,list[j].lastName)==-1)
                {
                    auxEmployee = list[i];
                    list[i]     = list[j];
                    list[j]     = auxEmployee;
                }

                else if  (stricmp(list[i].lastName,list[j].lastName)==0)

                    if (list[i].sector < list[j].sector)
                    {
                        auxEmployee = list[i];
                        list[i]     = list[j];
                        list[j]     = auxEmployee;
                    }
            }
        }
    }

    else if(order == 0)
    {
        for (i=0; i<(len -1); i++)
        {
            for(j=i+1; j<len; j++)
            {
                if (stricmp(list[i].lastName,list[j].lastName)==1)
                {
                    auxEmployee = list[i];
                    list[i]     = list[j];
                    list[j]     = auxEmployee;
                }
                else if (stricmp(list[i].lastName,list[j].lastName)==0)
                {


                    if (list[i].sector > list[j].sector)
                    {
                        auxEmployee = list[i];
                        list[i]     = list[j];
                        list[j]     = auxEmployee;
                    }
                }
            }
        }
    }

    return 0;
}

/** \brief print the content of employees array
 *
 * \param list Employee*
 * \param length int
 * \return int
 *
 */
int printEmployees(Employee list[], int length)
{
    int i;
    system("cls");


    printf("\n");
    for (i=0; i< length; i++)
    {
        if (list[i].isEmpty==0)
        {


            printf("%5d %10s %10s %5.f %2d \n\n",list[i].id,list[i].lastName,list[i].name,list[i].salary,list[i].sector);
        }
    }
    return 0;
}

int menu()
{
    system("cls");
    int opcion;

    printf("*** ABM EMPLEADOS ***\n\n");
    printf("1. ALTAS:\n");
    printf("2. MODIFICAR:\n");
    printf("3. BAJA:\n");
    printf("4. INFORMAR:\n");
    printf("5. Salir\n");

    scanf("%d",&opcion);

    return opcion;
}

int serchFree(Employee list[], int len)
{
    int i=0;
    int indice;


    for(i=0; i<len; i++)
    {

        indice =-1;

        if (list[i].isEmpty==1)
        {
            indice = i;
            break;
        }
    }

    return indice;
}
int loadEmployee(Employee list[], int len, int id)
{
    system("cls");
    int exito = 0;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int indice;

    indice=serchFree(list,len);

    if (indice == -1)
    {
        printf("No hay registros disponibles para cargar el empleado \n");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(name);

        printf("Ingrese apellido: ");
        fflush(stdin);
        gets(lastName);

        printf("Ingrese salario: ");
        scanf("%f", &salary);

        printf("Ingrese sector: ");
        scanf("%d", &sector);
        list[indice]=addEmployee(list,len,id,name,lastName,salary,sector);
        exito = 1;
        printf("\nalta exitosa\n\n");
    }




    system("pause");

    return exito;;
}

int subMenu()
{
    system("cls");
    int opcion;

    printf("*** INFORMES ***\n\n");
    printf("1. Listado de los empleados ordenados por Apellido y Sector.\n");
    printf("2. Total y promedio de los salarios _ empleados superan el salario promedio.\n");

    printf("3. Retroceder \n");

    scanf("%d",&opcion);

    return opcion;
}
int subMenuModificar()
{
    system("cls");
    int opcion;

    printf("*** MODIFICAR ***\n\n");
    printf("1. Modificar Nombre\n");
    printf("2. Modificar Apellido\n");
    printf("3. Modificar Salario\n");
    printf("4. Modificar Sector\n");
    printf("5. Salir\n");

    scanf("%d",&opcion);

    return opcion;
}

Resultadose promedioSalarios(Employee list[],int len)
{
    Resultadose salarios;
    int i;
    float suma = 0;
    float contador = 0;
    float salarioPromedio = 0;
    float salariosAltos = 0;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0)
        {
            contador++;
            suma= suma + (list[i].salary);

        }
    }
    salarioPromedio= suma / contador;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty == 0 && list[i].salary >= salarioPromedio)
        {
            salariosAltos++;


        }
        salarios.contador=contador;
        salarios.salarioPromedio=salarioPromedio;
        salarios.salariosAltos=salariosAltos;
        salarios.suma=suma;
    }
    return salarios;
}
