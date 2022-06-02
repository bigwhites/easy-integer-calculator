#include"nead.h"
void MidExpToLastExp(char* midExp, char*& lastExp)
{
    int len = strlen(midExp);
    lastExp = new char[100 * len];
    int writeLoc = 0;
    stack<char> op;
    for (int i = 0; i < len; ++i)
    {
        if (midExp[i] == ' ') continue; //过滤输入的表达式中的无用空格
        if (isNumber(midExp[i])) //是数字
        {
            int j = i;
            while (isNumber(midExp[j]))  //把从该位置开始后面的数字全部输出
            {
                lastExp[writeLoc++] = midExp[j];
                ++j;
            }
            i = j - 1;
            lastExp[writeLoc++] = ' '; //输出一个空格
        }

        else  //是运算符
        {
            if (canPush(midExp[i], op)) //可以继续压栈
            {
                op.push(midExp[i]);
            }
            else  //要出栈
            {
                if (midExp[i] == ')')  //遇到左扩回就一直出栈直到遇到右括号
                {
                    char top = op.top();
                    op.pop();
                    while (top != '(')
                    {
                        lastExp[writeLoc++] = top; //把（ ）间的运算符抛出
                        lastExp[writeLoc++] = ' '; //输出一个空格
                        top = op.top();
                        op.pop();
                    }
                }
                else //栈顶运算符优先级大于等于新运算符 
                {
                    for (; !canPush(midExp[i], op); op.pop()) //抛出栈内运算符直到新的可以入栈
                    {
                        lastExp[writeLoc++] = op.top();
                        lastExp[writeLoc++] = ' '; //输出一个空格
                    }
                    op.push(midExp[i]);
                }
            }
        }

    }
    for (; !op.empty(); op.pop())  //栈里还有运算符就抛出
    {
        lastExp[writeLoc++] = op.top();
        lastExp[writeLoc++] = ' ';
    }
    lastExp[writeLoc] = '\0'; //结尾加上结束符
}
