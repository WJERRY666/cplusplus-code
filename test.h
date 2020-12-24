//
// Created by JERRY on 2020/12/14.
//

#ifndef TEST_TEST_H
#define TEST_TEST_H

#include<iostream>
//测试构造函数与析构函数
class testgouzao
{
    int num;
public:
    testgouzao(int c1);//构造函数
    ~testgouzao();//析构函数
    int add(int a,int b);
};
#endif //TEST_TEST_H
