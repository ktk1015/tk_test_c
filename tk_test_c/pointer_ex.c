#include <stdio.h>

void p_test1()
{
	int *p; // int* p ������ ǥ����
	int a;

	p=&a;

	printf("������ p�� ��� �ִ� ��: %x \n",p);
	printf("int ���� a�� ����� �ּ�: %x \n",&a);
}

void p_test2()
{
	// ������ *�� "���� ���� ����� �ּҰ��� �ش��ϴ� �����ͷ� �����Ͻÿ�!"
	int *p;
	int a;
	p=&a; //a�� �ּҰ� ����
	a=2;

	printf("a�� ��: %d\n",a);
	printf("*p�� ��: %d\n",*p);
}

void p_test3()
{	
	int *p;
	int a;
	p=&a; //a�� �ּҰ� ����
	*p=3;

	printf("a�� ��: %d\n",a);
	printf("*p�� ��: %d\n",*p);
}

void pointer_test()
{
	p_test3();
}