#pragma once
const double pi = 3.1415926;


//麦克劳林公式在-1~1范围内的展开式
double arctan(double x, double precision){
    double sqr = x * x;
    double e = x;
    double r = 0;
    int i = 1;
    double f = e / i;
    while (f > precision || f < - precision){
        f = e / i;
        r = (i % 4 == 1)? r + f : r - f;
        e *= sqr;
        i += 2;
    }
    return r;
}

/**
 * @description: 实现arctan函数计算
 * @param {bool} inputMode: 输入为角度时，inputMode为1；为弧度时，inputMode为0
 * @param {double} x: 输入的x
 * @param {double} precision: 精度(可选)
 * @return {double} outputNum: 输出数值
 */
double fnArctan(bool inputMode, double x, double precision = 0.00001){
    double outputNum; //输出

    //扩展输入范围
    if (x >= -1 && x <= 1){
        outputNum = arctan(x, precision);
    }
    else{
        if (x > 0){
            outputNum = pi/2 - arctan(1 / x, precision);
        }
        else{
            outputNum = -pi/2 - arctan(1 / x, precision);
        }
   }

   //弧度转角度：inputMode = 1，输出角度
    if(inputMode)
    {
        outputNum = outputNum * 180 / pi;
    }
    else{}

    return outputNum;
}

