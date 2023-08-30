#include <stdio.h>
#include <stdlib.h>

typedef struct
{
    int empID, jobType;
    float salary;
}
Employee;

Employee * readEmployeeArray(FILE *fp);
int getArraySize(void *array);
Employee * getEmployeeByID(Employee *record, int empID);
int setEmpSalary(Employee *record, int empID, float salary);
int getEmpSalary(Employee *record, int empID, float *salary);
int setEmpJobType(Employee *record, int empID, int job);
int getEmpJobType(Employee *record, int empID, int *job);
void freeArray(Employee *record);
