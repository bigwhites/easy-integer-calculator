#include"nead.h"

bool canPush(char newOp, stack<char>& op)
{
    if (op.empty()) return true;  //ջ��ֱ����
    if (newOp == ')') return false; //�����ز�����ջ
    int top = op.top();
    if (newOp == '(' || top == '(') return true; //ջ�������Ż���Ҫ��ջ��������ֱ����
    if ((top == '+' || top == '-') && (newOp == '*' || newOp == '/'))  return true; //�µĵ����ȼ����ھɵ� ���Լ�����
    return false;
}

bool isNumber(char x)
{
    if (x >= '0' && x <= '9')
        return true;
    return false;
}

LDouble chToNum(char x)
{
    return (int)(x - '0');
}

bool isInfixExperssion(char* infixExp)
{
    if (!infixExp) return false;
    if (checkPerCh(infixExp)&&checkBrackets(infixExp)) return true;
    return false;
}

bool checkPerCh(char* infixExp)
{
    bool noNumber = true;
    if (infixExp[0] != '(' && !isNumber(infixExp[0])&&infixExp[0]!='-') return false;
    int len = strlen(infixExp);
    for (int j = 0; j < len; ++j)
    {
        char i = infixExp[j];
        if (i == ' ') continue;
        if (isNumber(i)) noNumber = false;
        if (!isNumber(i)&&!isOp(i)&&i!='('&&i!=')'&&i!='.') return false; //�����������ַ�
        if (isOp(i))  //��������������
        {
            char left = infixExp[j - 1];
            char right = infixExp[j + 1];
            if (i == '/') //�����ұ߲�����0 �����ұ���ֵΪ0���ӱ��ʽ���޷���� �������ռ���ʱexit(1)
            {
                if (right == '0') return false;
            }
            if (isOp(left) || isOp(right)) return false; //���߶�����Ϊ�����
            if (i != '-' && (left == '(' || right == ')')) return false;//��߲����������ţ���֧�ָ����� �ұ߲�����������
            if (i == '-' && right == ')') return false;//���������ж�
            //������������� ������������
        }
        if (i == '.') if (!isNumber(infixExp[j + 1]) || !isNumber(infixExp[j - 1]))  return false; //С�������߱���������

    }
    if (noNumber) return false;
    return true;

}

bool checkBrackets(char* infixExp)   //brackets Բ����
{
    stack<char> Sbra;
    int len = strlen(infixExp);
    for (int j = 0; j < len; ++j)
    {
        char i = infixExp[j];
        if (i == '(')
        {
            Sbra.push(i);
        }
        else if (i == ')')
        {
            if (!Sbra.empty())
            {
                Sbra.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (Sbra.empty())  return true;
    else  return false;
}


bool isOp(char i)
{
    if (i == '+' || i == '-' || i == '*' || i == '/') return true;
    return false;
}