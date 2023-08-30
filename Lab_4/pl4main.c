#include "pl4.h"

int main(void)
{
    FILE *fp;
    fp = fopen("records.txt", "r");

    Employee *records = readEmployeeArray(fp);
    Employee *emp = getEmployeebyID(records, 6);
    printf("%f", (*emp).salary);

    setEmpSalary(records, , );

    float salary:
    getEmpSalary(records, , );

    retrun 0;
}
