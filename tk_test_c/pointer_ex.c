#include <stdio.h>

void p_test1()
{
	int *p; // int* p 동일한 표현임
	int a;

	p=&a;

	printf("포인터 p에 들어 있는 값: %x \n",p);
	printf("int 변수 a가 저장된 주소: %x \n",&a);
}

void p_test2()
{
	// 포인터 *란 "나를 나에 저장된 주소값에 해당하는 데이터로 생각하시오!"
	int *p;
	int a;
	p=&a; //a의 주소값 전달
	a=2;

	printf("a의 값: %d\n",a);
	printf("*p의 값: %d\n",*p);
}

void p_test3()
{	
	int *p;
	int a;
	p=&a; //a의 주소값 전달
	*p=3;

	printf("a의 값: %d\n",a);
	printf("*p의 값: %d\n",*p);
}

void pointer_test()
{
	p_test3();
}