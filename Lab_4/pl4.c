#include "pl4.h"

Employee * readEmployeeArray(File *fp)
{
    int size;
    int *arr;

    fscanf(fp,"%d", &size);
    arr = malloc(size * sizeof(Employee)+sizeof(int));
    arr[0] = size;
    arr++;

    Employee *worker = (void *)worker;

    for(int i = 0; i < size; i++)
    {
        fscanf(fp, "%d, %d, %f", &(arr[i].empID), &(arr[i].jobType), &(arr[i].salary));
    }

    return worker;
}

int getArraySize(void *array)
{
    return ((int*)array)[-1];
}

Employee * getEmployeeByID(Employee *record, int empID)
{
    Employee *x = NULL;
    for(int i = 0; i < getArraySize(record); i++)
    {
        if(record[i].empID == empID)
        {
            x = &record[i];
        }
    }
    if(x != NULL)
    {
        return x;
    }
    else
    {
        return 0;
    }
}

int setEmpSalary(Employee *record, int empID, float salary)
{
    Employee *emp = getEmployeeByID(record, empID);
    if(emp == NULL)
    {
        return 1;
    }
    else
    {
        (*emp).salary = salary;
        return 0;
    }
}

int getEmpSalary(Employee *record, int empID, float *salary)
{
    Employee *emp = getEmployeeByID(record, empID);
    if(emp == NULL)
    {
        return 1;
    }
    else
    {
        (*emp).salary = *salary;
    }
}

int setEmpJobType(Employee *record, int empID, int job)
{
    Employee *emp = getEmployeeByID(record, empID);
    if(emp == NULL)
    {
        return 1;
    }
    else
    {
        (*emp).jobType = job;
    }
}

int getEmpJobType(Employee *record, int empID, int *job)
{
    Employee *emp = getEmployeeByID(record, empID);
    if(emp == NULL)
    {
        return 1;
    }
    else
    {
        (*emp).jobType = *job;
    }
}

void freeArray(Employee *record)
{
    free(((int*)record)-1);
    record = NULL;
}
