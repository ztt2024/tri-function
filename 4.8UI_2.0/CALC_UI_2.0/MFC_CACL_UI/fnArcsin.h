#pragma once

#include <stdio.h>

#define PI (3.1415926535898)


/**
 * @description: 实现arcsin函数计算
 * @param {bool} inputMode: 输入为角度时，inputMode为1；为弧度时，inputMode为0
 * @param {double} inputNum: 输入的x
 * @param {double} precision: 精度(可选)
 * @return {double} outputNum: 输出数值
 */
double fnArcsin(bool inputMode, double inputNum, double precision = 0.000000001)
{        
    double outputNum = inputNum ; //输出
    double squareX = inputNum * inputNum;
    
    //进行麦克劳林展开式的计算
    double curPrecision = inputNum;
    int m = 1;
    while (curPrecision >= precision || curPrecision <= -precision) {
		double tmp = 2.0 * m;
        curPrecision *= ((1 + 1.0 / tmp -4.0 / (tmp + 1)) * squareX);
        outputNum += curPrecision;
        ++m;
    }

    //解决输出负0的问题
    if(outputNum< precision && outputNum > -precision)
    {
        outputNum = 0;
    }
    else{}

    //弧度转角度：inputMode = 1，输出角度
    if(inputMode)
    {
        outputNum = outputNum * 180 / PI;
    }
    else{}

    return outputNum;
}


