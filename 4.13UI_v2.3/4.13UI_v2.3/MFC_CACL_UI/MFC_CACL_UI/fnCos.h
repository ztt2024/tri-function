/*
 * @Description: cos函数
 * @Author: Dongxin Yan
 * @FilePath: \tri_func\tri_funcs\fnCos.h
 * @Date: 2022-03-28 15:27:19
 * @LastEditTime: 2022-03-31 17:25:10
 */
#pragma once

#include "fnSin.h"
#include <stdio.h>

/**
 * @description: 实现cos函数计算
 * @param {bool} inputMode: 输入为角度时，inputMode为1；为弧度时，inputMode为0
 * @param {double} inputNum: 输入的x
 * @param {double} precision: 精度(可传参数)
 * @return {double} outputNum: 输出的cosx
 */
double fnCos(bool inputMode, double inputNum, double precision = 0.0000001)
{
    double outputNum = 1;  //输出
    double coefficient = 1, denominator = 1, numerator = 1; //系数，分母，分子

    //判断输入是角度还是弧度
    if(inputMode)
    {
        inputNum = fMod(inputNum, 360);
        inputNum = inputNum / 180 * PI;
    }
    else   
    {
        inputNum = fMod(inputNum, 2*PI);
    }

    //进行麦克劳林展开式的计算
    int i = 1;
    double curPrecision = numerator / denominator;
    while (curPrecision >= precision  || curPrecision <= -precision) {
        numerator = numerator * inputNum;
        denominator = denominator * i;
        if(i % 2 == 0)
        {
            coefficient = -coefficient;
            outputNum += coefficient * numerator / denominator;
        }
        else{}
        ++i;
        curPrecision = numerator / denominator;
    }

    //解决输出负0的问题
    if(outputNum< precision && outputNum >-precision)
    {
        outputNum = 0;
    }
    else{}
    return outputNum;
}