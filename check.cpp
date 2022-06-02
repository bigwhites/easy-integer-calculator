#include"nead.h"

bool canPush(char newOp, stack<char>& op)
{
    if (op.empty()) return true;  //栈空直接入
    if (newOp == ')') return false; //右扩回不能入栈
    int top = op.top();
    if (newOp == '(' || top == '(') return true; //栈顶是括号或者要入栈的是括号直接入
    if ((top == '+' || top == '-') && (newOp == '*' || newOp == '/'))  return true; //新的的优先级大于旧的 可以继续入
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

bool isMidExperssion(char* midExp)
{
    if (checkPerCh(midExp)&&checkBrackets(midExp)) return true;
    return false;
}

bool checkPerCh(char* midExp)
{
    bool noNumber = true;
    if (midExp[0] != '(' && !isNumber(midExp[0])) return false;
    int len = strlen(midExp);
    for (int j = 0; j < len; ++j)
    {
        char i = midExp[j];
        if(i==' ') continue;
        if (isNumber(i)) noNumber = false;
        if (!isNumber(i)&&!isOp(i)&&i!='('&&i!=')') return false; //不能有其他字符
        if (isOp(i))  //检查运算符的两边
        {
            char left = midExp[j - 1];
            char right = midExp[j + 1];
            if (i == '/') //除号右边不能是0 但若右边是值为0的子表达式则无法测出 会在最终计算时exit(1)
            {
                if (right == '0') return false;
            }
            if (isOp(left) || isOp(right)) return false; //两边都不能为运算符
            if (left == '(' || right == ')') return false;//左边不能是左括号（不支持负数） 右边不能是右括号
            //不检查括号两边 允许冗余括号
        }

    }
    if (noNumber) return false;
    return true;

}

bool checkBrackets(char* midExp)   //brackets 圆括号
{
    stack<char> Sbra;
    int len = strlen(midExp);
    for (int j = 0; j < len; ++j)
    {
        char i = midExp[j];
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
