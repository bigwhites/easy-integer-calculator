#include"nead.h"


void Cache::buildCache(void)
{
    char logo = 'A';
    for (int i = 1; i <= size; ++i,++logo)
    {
        printf("  输入变量%c = ", logo);

        char infixExp[100];
        gets_s(infixExp);
        if (!isInfixExperssion(infixExp))
        {
            printf("输入错误！");
            exit(1);
        }
        char* suffixExp;
        infixToSuffixExp(infixExp, suffixExp);
        int res = (int)calcSuffixExperssion(suffixExp); //表达式计算结果截断为整数然后存入缓存器
        setValue(logo, res);
    }
}

void Cache::setValue(char logo, int v)
{
    if (v < 0)
    {
        printf("\a\n缓存变量的值不能为负");
        exit(1);
    }
    int loc = logo - 'A';
    value[loc] = v;
}

int Cache::getValue(char logo)
{
    int loc = logo - 'A';
    return value[loc];
}

void Cache::showCache(void)
{
    char logo = 'A';
    printf("\n\n缓存的结果为：\n");
    for (int i = 1; i <= size; ++i,++logo)
    {
        printf("  %c = %d \n", logo, getValue(logo));
    }
}

char* cacheSubtitute(char* preInfixExp, Cache& C)
{
    int sizeOfCache = C.getSize();
    char* infixExp = new char[800 + strlen(preInfixExp)];
    strcpy(infixExp, preInfixExp);
    int i;
    for ( i = 0; i < strlen(infixExp); ++i)
    {
        char ch = infixExp[i];
        stack<char>chNum;
        if (ch >= 'A' && ch <= (sizeOfCache - 1) + 'A') //在缓存内的变量
        {
            if (infixExp[i + 1] >= 'A' && infixExp[i + 1] <= 'A' + (sizeOfCache - 1))
            {
                delete[]infixExp;
                return nullptr; //不允许两个变量一起出现以产生歧义 
            }
            int x = C.getValue(ch);
            while (x > 0)
            {
                chNum.push(x%10+48);
                x /= 10;
            }
            infixExp[i] = chNum.top();
            chNum.pop();
            i = numberInsert(infixExp, i, chNum);  //在startLoc后面递归的插入
        }
    }
    return infixExp;
}

int numberInsert(char* preInfixExp, int startLoc, stack<char>& chNum) 
{
    if (chNum.empty()) return startLoc;
    int len = strlen(preInfixExp);
    preInfixExp[len+1] = '\0';
    for (int i = len-1;i>=startLoc+1;--i)
    {
        preInfixExp[i + 1] = preInfixExp[i];
    }
    preInfixExp[startLoc + 1] = chNum.top();
    chNum.pop();
    numberInsert(preInfixExp, startLoc + 1, chNum);
    return startLoc;
}