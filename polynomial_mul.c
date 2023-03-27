#include<stdio.h>
#include<stdlib.h>
#define MAX_DEGREE 101

typedef struct {
	int degree; //���׽��� ����
	float coef[MAX_DEGREE]; //���׽��� ���
}polynomial;

polynomial poly_mul1(polynomial A, polynomial B)
{
	polynomial C;// ���� ��� ���׽��� ������ ����ü
	int Apos = 0, Bpos = 0, Cpos = 0; //�迭 �ε��� ����
	int degree_a = A.degree;
	int degree_b = B.degree;

	for (int i = 0; i < degree_a + degree_b + 1; i++)
	{
		C.coef[i] = 0;
	}
	C.degree = A.degree + B.degree;//��� ���׽� ����. A.degree�� B.degree�� �ְ����� ���� ���� C�� �ְ����׿� ����


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
	//���Ȯ������1
	/*polynomial a = {3,{4, 3, 2, 1}}; //{�ִ� ����{}}
	polynomial b = { 2, {3, 2, 8} };*/

	//���Ȯ������2
	polynomial a = { 6,{7, 0, 0, 5, 9, 0, 1} }; //{�ִ� ����{}}
	polynomial b = { 3, {5, 2, 1, 10} };
	polynomial c; //a�� b ���� ��
	print_poly(a);
	print_poly(b);
	c = poly_mul1(a, b);
	printf("----------------------------------------------------------------------------\n");
	print_poly(c);
	system("pause");
	return 0;
}