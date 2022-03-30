// 本程序测试sin函数计算结果的正确性
#include<iostream>
#include<fstream>
#include <cstdlib>
#include <time.h>
#include <typeinfo>
#include"Trifuncs_test.h"
constexpr auto PI = 3.1415926;
using namespace std;

bool Equal(double num1, double num2)
{
    if ((num1 - num2 > -0.0001) && (num1 - num2 < 0.0001))  //考虑精度为小数点后4位数
        return true;
    else
        return false;
}

int main()
{
    //0 90 -90 1800/20 测试边界值的表现
    double input[] = { 0,90,-600,360000 / 20 };
    double result = 0;  //初始化一个变量用于存放自写函数的计算结果
    double accuration = 0;    //存放正确结果
    double input_aftertrans = 0;  //对输入值进行转换
    int i;
    int count1 = sizeof(input) / sizeof(input[0]);

    for (i = 0; i < count1; i++)
    {
        input_aftertrans = inputtrans(input[i]);
        cout << "测试值为：" << input[i] << endl;
        accuration = cos(input_aftertrans);
        result = snowcos(input_aftertrans);
        cout << result << endl;
        //cout << "The same result ?" << Equal(result, accuration) << endl;
        if (Equal(result, accuration)) {
            cout << "Test passed！" << endl;           //如果调用sin库和自定义snowsin函数值误差在一定范围，则认为测试通过
        }
        else {
            cout << "Test failed！" << endl;            //如果调用sin库和自定义snowsin函数值误差超过一定范围，则认为测试失败
        }
    }


}