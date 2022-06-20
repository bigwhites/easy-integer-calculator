#include"nead.h"
void infixToSuffixExp(char* infixExp, char*& suffixExp)
{
    int len = strlen(infixExp);
    suffixExp = new char[100 * len+200];
    int writeLoc = 0;
    stack<char> op;
    for (int i = 0; i < len; ++i)
    {
        if (infixExp[i] == ' ') continue; //��������ı��ʽ�е����ÿո�
        if (isNegative(infixExp, i))
        {
            suffixExp[writeLoc++]='-'; //�Ѹ������
            continue;
        }
        if (isNumber(infixExp[i])) //������
        {
            int j = i;
            while (isNumber(infixExp[j])||infixExp[j]=='.')  //�ѴӸ�λ�ÿ�ʼ���������ȫ�����
            {
                suffixExp[writeLoc++] = infixExp[j];
                ++j;
            }
            i = j - 1;
            suffixExp[writeLoc++] = ' '; //���һ���ո�
        }

        else  //�������
        {
            if (canPush(infixExp[i], op)) //���Լ���ѹջ
            {
                op.push(infixExp[i]);
            }
            else  //Ҫ��ջ
            {
                if (infixExp[i] == ')')  //���������ؾ�һֱ��ջֱ������������
                {
                    char top = op.top();
                    op.pop();
                    while (top != '(')
                    {
                        suffixExp[writeLoc++] = top; //�ѣ� �����������׳�
                        suffixExp[writeLoc++] = ' '; //���һ���ո�
                        top = op.top();
                        op.pop();
                    }
                }
                else //ջ����������ȼ����ڵ���������� 
                {
                    for (; !canPush(infixExp[i], op); op.pop()) //�׳�ջ�������ֱ���µĿ�����ջ
                    {
                        suffixExp[writeLoc++] = op.top();
                        suffixExp[writeLoc++] = ' '; //���һ���ո�
                    }
                    op.push(infixExp[i]);
                }
            }
        }

    }
    for (; !op.empty(); op.pop())  //ջ�ﻹ����������׳�
    {
        suffixExp[writeLoc++] = op.top();
        suffixExp[writeLoc++] = ' ';
    }
    suffixExp[writeLoc] = '\0'; //��β���Ͻ�����
}


bool isNegative(char* infixExp, int pos)
{
    if (infixExp[pos] == '-')
    {
        if (pos == 0) return true; //��ͷ��Ϊ����
        if (infixExp[pos - 1] == '(') return true; //���������������Ǹ���
    }
    return false;
}