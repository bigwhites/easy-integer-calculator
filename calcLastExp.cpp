#include"nead.h"

LDouble calcLastExperssion(char* lastExp)
{
    int len = strlen(lastExp);
    char buff;
    stack<LDouble> num;
    for (int i = 0; i < len; ++i)
    {
        buff = lastExp[i];
        if (isNumber(buff))
        {
            int j = i;
            LDouble n = 0;
            LDouble lastNum = 0;
            stack<char> x;
            while (isNumber(lastExp[j]))
            {
                x.push(lastExp[j]);
                ++j;
            }
            while (!x.empty())
            {
                lastNum += chToNum(x.top()) * pow(10, n);
                ++n;
                x.pop();
            }
            num.push(lastNum);
            i = j - 1;
        }
        else
        {
            LDouble n = num.top();
            num.pop();
            LDouble m = num.top();
            num.pop();
            num.push(calc(buff, n, m));
        }
        if (lastExp[i + 1] == ' ')  ++i;
    }
    return num.top();
}

LDouble calc(char op, LDouble n, LDouble m)
{
    switch (op)
    {
    case '+':
        return m + n;
        break;
    case '-':
        return m - n;
        break;
    case '*':
        return m * n;
        break;
    case '/':
        if (n == 0)
        {
            printf("\a表达式非法！");
            exit(1);
        }
        return m / n;
        break;
    }
    return -1;
}
