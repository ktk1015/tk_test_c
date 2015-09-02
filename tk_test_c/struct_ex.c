#include <stdio.h>

struct employee
{
	int age;
	int salary;
};

struct company
{
	struct employee data;
	char name[10];
};

void struct_ex()
{
	struct company Kim;

	Kim.data.age = 31;
	Kim.data.salary = 300;

	printf("Kim's age: %d \n",Kim.data.age);
	printf("Kim's salary:%d \n",Kim.data.salary);
}