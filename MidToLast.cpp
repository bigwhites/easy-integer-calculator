#include"nead.h"
void MidExpToLastExp(char* midExp, char*& lastExp)
{
    int len = strlen(midExp);
    lastExp = new char[100 * len];
    int writeLoc = 0;
    stack<char> op;
    for (int i = 0; i < len; ++i)
    {
        if (midExp[i] == ' ') continue; //��������ı��ʽ�е����ÿո�
        if (isNumber(midExp[i])) //������
        {
            int j = i;
            while (isNumber(midExp[j]))  //�ѴӸ�λ�ÿ�ʼ���������ȫ�����
            {
                lastExp[writeLoc++] = midExp[j];
                ++j;
            }
            i = j - 1;
            lastExp[writeLoc++] = ' '; //���һ���ո�
        }

        else  //�������
        {
            if (canPush(midExp[i], op)) //���Լ���ѹջ
            {
                op.push(midExp[i]);
            }
            else  //Ҫ��ջ
            {
                if (midExp[i] == ')')  //���������ؾ�һֱ��ջֱ������������
                {
                    char top = op.top();
                    op.pop();
                    while (top != '(')
                    {
                        lastExp[writeLoc++] = top; //�ѣ� �����������׳�
                        lastExp[writeLoc++] = ' '; //���һ���ո�
                        top = op.top();
                        op.pop();
                    }
                }
                else //ջ����������ȼ����ڵ���������� 
                {
                    for (; !canPush(midExp[i], op); op.pop()) //�׳�ջ�������ֱ���µĿ�����ջ
                    {
                        lastExp[writeLoc++] = op.top();
                        lastExp[writeLoc++] = ' '; //���һ���ո�
                    }
                    op.push(midExp[i]);
                }
            }
        }

    }
    for (; !op.empty(); op.pop())  //ջ�ﻹ����������׳�
    {
        lastExp[writeLoc++] = op.top();
        lastExp[writeLoc++] = ' ';
    }
    lastExp[writeLoc] = '\0'; //��β���Ͻ�����
}
