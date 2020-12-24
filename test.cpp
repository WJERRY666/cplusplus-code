//
// Created by JERRY on 2020/12/14.
//
#include"test.h"

int testgouzao::add(int a,int b)
{
    int sum = 0;
    sum = a+b;
    return (sum+num);
}

testgouzao::testgouzao(int orinum)//构造函数
{
    num=orinum;
    std::cout<<"gouzao function"<<std::endl;
}

testgouzao::~testgouzao()//析构函数
{
    std::cout<<"xigou function"<<std::endl;
}

