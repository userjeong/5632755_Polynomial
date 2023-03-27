#include<stdio.h>
#include<stdlib.h>
#define MAX_DEGREE 101

typedef struct {
	int degree; //다항식의 차수
	float coef[MAX_DEGREE]; //다항식의 계수
}polynomial;

polynomial poly_mul1(polynomial A, polynomial B)
{
	polynomial C;// 곱한 결과 다항식을 저장할 구조체
	int Apos = 0, Bpos = 0, Cpos = 0; //배열 인덱스 변수
	int degree_a = A.degree;
	int degree_b = B.degree;

	for (int i = 0; i < degree_a + degree_b + 1; i++)
	{
		C.coef[i] = 0;
	}
	C.degree = A.degree + B.degree;//결과 다항식 차수. A.degree와 B.degree의 최고차항 더한 값을 C의 최고차항에 대입


	for (int i = 0; i <= degree_a; i++)
	{
		for (int j = 0; j <= degree_b; j++)
		{
			C.coef[i + j] += A.coef[i] * B.coef[j];
		}
	}
	return C;
}

void print_poly(polynomial p)
{
	for (int i = p.degree; i > 0; i--)
	{
		printf("%3.1fx^%d + ", p.coef[p.degree - i], i);
	}
	printf("%3.1f\n", p.coef[p.degree]);
}

int main(void)
{
	//결과확인조건1
	/*polynomial a = {3,{4, 3, 2, 1}}; //{최대 차수{}}
	polynomial b = { 2, {3, 2, 8} };*/

	//결과확인조건2
	polynomial a = { 6,{7, 0, 0, 5, 9, 0, 1} }; //{최대 차수{}}
	polynomial b = { 3, {5, 2, 1, 10} };
	polynomial c; //a와 b 곱한 값
	print_poly(a);
	print_poly(b);
	c = poly_mul1(a, b);
	printf("----------------------------------------------------------------------------\n");
	print_poly(c);
	system("pause");
	return 0;
}