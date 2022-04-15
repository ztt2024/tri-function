#include <iostream>
#include <cstdlib>
#include <iomanip>
#include"calc.h"
#include "pch.h"
/*
���ܣ��������Ǻ������㺯����calc.h����������������MFC_CACL_UIDlg.c��ɵ���
*/
constexpr auto PI = 3.1415926;

//double inputtrans(void) 
double inputtrans(double x)
{
	//double x;

	//std::cout << "Please input x: " << std::endl;
	//std::cin >> x;
	while (x >= 360.0)//����x�ķ�Χ
	{
		x -= 360.0;
	}
	return (x * PI / 180.0);//�Ƕ�or����
}

double factorial(double n) {//�׳�
	if (n <= 1) {
		return n;
	}
	else {
		return n * factorial(n - 1);
	}
}


//����Ϊ�����ֵ����
double myabs(double num1)
{
	return((num1 > 0) ? num1 : -num1);
}

//����Ϊ��sin(x)��ֵ
double snowsin(double num2)
{
	while (num2 >= 360.0)//����x�ķ�Χ
	{
		num2 -= 360.0;
	}
	num2 = (num2 * PI / 180.0);
	int i = 1, negation = 1;//ȡ��
	double sum;
	double index = num2;//ָ��
	double Factorial = 1;//�׳�
	double TaylorExpansion = num2;//̩��չ��ʽ���
	do
	{
		Factorial = Factorial * ((__int64)i + 1) * ((__int64)i + 2);//��׳�
		index *= num2 * num2;//��num2�Ĵη�
		negation = -negation;//ÿ��ѭ��ȡ��
		sum = index / Factorial * negation;
		TaylorExpansion += sum;
		i += 2;
	} while (myabs(sum) > 1e-15);
	return(TaylorExpansion);
}

//��cos
double snowcos(double x)
{
	double sin = snowsin(x);//�����SIN��ֵ
	double cos = 1 - sin * sin;//��ͨ����ʽ��ȥSIN

	return sqrt(cos);//����
}

//��arcsin x�ķ�ΧҪ�仯��-1��1��
double snowarcsin(double x)
{
	//float result = x, result_a = 1.0f, result_b = 1.0f, result_c = 1.0f;//�������
	//unsigned int i = 0, ii = 0;//�˷�����һ���ľ�����Խ����1�������Խ��
	//for (i = 0; i < 1000; i++)
	//{
	//	for (ii = 0; ii < (2 * i + 1); ii++)
	//	{
	//		result_a *= (float)(2 * ii + 1) / (float)(2 * ii + 2);
	//		result_b *= (x*x);
	//	}
	//	result_b = x;
	//	result_c = result_a / (float)(ii + 2);
	//	result += (float)(result_c)*(float)result_b;
	//	result_a = 1.0f; result_a = 1.0f;

	//}
	//return result;
	//���ĺ�İ汾�����Ӿ�ȷ
	double Y;
	if (-1 < x&& x < 1)
	{
		//Y = ((((355.8344664968055) * x * x -
			//1527.866163211568) * x * x + 2753.832624036205) * x * x - 2703.664106042975) * x * x;
		Y = ((((((((((355.8344664968055) * x * x -
			1527.866163211568) * x * x + 2753.832624036205) * x * x - 2703.664106042975) * x * x +
			1570.005944165283) * x * x - 547.8511412592482) * x * x + 111.6022805454461) * x * x - 12.131229199997044) * x * x + 0.767998895934955) * x * x
			+ 0.991408990431597) * x;
	}
	else if (x == 1)
	{
		Y = PI / 2;
	}
	else
	{
		Y = -(PI / 2);
	}
	Y = Y * 180 / PI;
	return Y;

}

double snowarctan(double x) {
	double sqr = x * x;
	double e = x;
	double r = 0;
	int i = 1;
	if (e >= -1 && e <= 1)//̩�ռ���
	{
		while (fabs(e / i) > 1e-7)
		{
			double f = e / i;
			r = (i % 4 == 1) ? r + f : r - f;
			e = e * sqr;
			i += 2;
		}
	}
	if (e <= -1 || e >= 1)//arctan(x)+arctan(1/x)=��/2
	{
		e = 1 / e;
		double h = e * e;
		while (fabs(e / i) > 1e-7)
		{
			double f = e / i;
			r = (i % 4 == 1) ? r + f : r - f;
			e = e * h;
			i += 2;
		}
		if (e > 0)
			r = PI / 2 - r;
		else
			r = -PI / 2 - r;
	}
	return r;
}