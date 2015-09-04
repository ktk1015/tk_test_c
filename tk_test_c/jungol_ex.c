#include <stdio.h>

/*
	3행 5열의 2차원 문자배열을 선언하고 차례로 대문자를 입력 받은 후 소문자로 바꾸어서 
	공백으로 구분하여 출력하는 프로그램을 작성하시오.
	hit:대문자 A는 65로 저장되고 소문자 a는 97로 저장된다. 즉 소문자는 대문자보다 32가 더 크다.
*/
void arr_test1()
{
	char arr[3][5];
	int i,j;
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{
			scanf(" %c",&arr[i][j]);			
		}
	}
	
	for(i=0;i<3;i++)
	{
		for(j=0;j<5;j++)
		{			
			printf("%c ",arr[i][j] + 32);
		}
		printf("\n");
	}
}

void Recursive(int n)
{		
	if(n <= 0)
	{
		printf("end of func\n");
		return;
	}

	printf("재귀함수\n");	
	Recursive(n-1);	
}

/*
	사각형의 높이 n과 너비 m을 입력받은 후 n행 m열의 사각형 형태로 1부터 n*m번까지 숫자가 차례대로 출력되는 프로그램을 작성하시오.

	< 처리조건 > 
	숫자의 진행 순서는 처음에 맨 윗줄의 왼쪽에서 오른쪽으로 1부터 차례대로 너비 m만큼 출력한 후 다음 줄로 바꾸어서 다시 왼쪽에서 
	오른쪽으로 1씩 증가하면서 출력하는 방법으로 n번 줄까지 반복한다
*/


int jungol_main()
{	
	int n=0;
	scanf("%d",&n);
	Recursive(n);

	//arr_test1();
	return 0;
}