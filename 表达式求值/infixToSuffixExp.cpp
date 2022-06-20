#include"nead.h"
void infixToSuffixExp(char* infixExp, char*& suffixExp)
{
    int len = strlen(infixExp);
    suffixExp = new char[100 * len+200];
    int writeLoc = 0;
    stack<char> op;
    for (int i = 0; i < len; ++i)
    {
        if (infixExp[i] == ' ') continue; //过滤输入的表达式中的无用空格
        if (isNegative(infixExp, i))
        {
            suffixExp[writeLoc++]='-'; //把负号输出
            continue;
        }
        if (isNumber(infixExp[i])) //是数字
        {
            int j = i;
            while (isNumber(infixExp[j])||infixExp[j]=='.')  //把从该位置开始后面的数字全部输出
            {
                suffixExp[writeLoc++] = infixExp[j];
                ++j;
            }
            i = j - 1;
            suffixExp[writeLoc++] = ' '; //输出一个空格
        }

        else  //是运算符
        {
            if (canPush(infixExp[i], op)) //可以继续压栈
            {
                op.push(infixExp[i]);
            }
            else  //要出栈
            {
                if (infixExp[i] == ')')  //遇到左扩回就一直出栈直到遇到右括号
                {
                    char top = op.top();
                    op.pop();
                    while (top != '(')
                    {
                        suffixExp[writeLoc++] = top; //把（ ）间的运算符抛出
                        suffixExp[writeLoc++] = ' '; //输出一个空格
                        top = op.top();
                        op.pop();
                    }
                }
                else //栈顶运算符优先级大于等于新运算符 
                {
                    for (; !canPush(infixExp[i], op); op.pop()) //抛出栈内运算符直到新的可以入栈
                    {
                        suffixExp[writeLoc++] = op.top();
                        suffixExp[writeLoc++] = ' '; //输出一个空格
                    }
                    op.push(infixExp[i]);
                }
            }
        }

    }
    for (; !op.empty(); op.pop())  //栈里还有运算符就抛出
    {
        suffixExp[writeLoc++] = op.top();
        suffixExp[writeLoc++] = ' ';
    }
    suffixExp[writeLoc] = '\0'; //结尾加上结束符
}


bool isNegative(char* infixExp, int pos)
{
    if (infixExp[pos] == '-')
    {
        if (pos == 0) return true; //在头必为负号
        if (infixExp[pos - 1] == '(') return true; //被括号括起来的是负号
    }
    return false;
}