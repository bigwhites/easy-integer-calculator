#pragma once
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

typedef long double LDouble;

void MidExpToLastExp(char* midExp, char*& lastExp);  //��׺���ʽת��׺���ʽ
bool isNumber(char x); //������
LDouble chToNum(char x); //�ַ�ת��������
LDouble calc(char op, LDouble n, LDouble m); //��׺���ʽ�����׳������������
bool canPush(char newOp, stack<char>& op); //�ж��µ�������Ƿ�����ջ 
LDouble calcLastExperssion(char* lastExp); //�����׺���ʽ
bool isMidExperssion(char* midExp);  //�ж�������ʽ�Ƿ�Ϸ�
bool checkPerCh(char* midExp); //���ַ�ɨ������ʽ
bool checkBrackets(char* midExp); //��������Ƿ�ƥ��
bool isOp(char i); //��+ - * /�ĸ������������