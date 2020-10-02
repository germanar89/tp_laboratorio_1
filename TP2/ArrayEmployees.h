#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
typedef struct
{
 int id;
 char name[51];
 char lastName[51];
 float salary;
 int sector;
 int isEmpty;
}Employee;
typedef struct
{
    float suma;
    float contador;
    float salarioPromedio;
    float salariosAltos;
}Resultadose;



#endif // ARRAYEMPLOYEES_H_INCLUDED


Resultadose promedioSalarios(Employee list[],int len);
int initEmployees(Employee list[], int len);
Employee addEmployee(Employee list[], int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee list[], int len,int id);
int removeEmployee(Employee list[], int len, int idRemove);
int sortEmployees(Employee list[], int len, int order);
int printEmployees(Employee list[], int length);
int serchFree(Employee list[], int len);
int subMenuModificar();
int subMenu();
int menu();
