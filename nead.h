#pragma once
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

typedef long double LDouble;

void MidExpToLastExp(char* midExp, char*& lastExp);  //中缀表达式转后缀表达式
bool isNumber(char x); //是数字
LDouble chToNum(char x); //字符转换成数字
LDouble calc(char op, LDouble n, LDouble m); //后缀表达式计算抛出的最基本运算
bool canPush(char newOp, stack<char>& op); //判断新的运算符是否能入栈 
LDouble calcLastExperssion(char* lastExp); //计算后缀表达式
bool isMidExperssion(char* midExp);  //判断输入表达式是否合法
bool checkPerCh(char* midExp); //逐字符扫描检查表达式
bool checkBrackets(char* midExp); //检查括号是否匹配
bool isOp(char i); //是+ - * /四个基本运算符号