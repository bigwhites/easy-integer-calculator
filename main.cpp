#include"nead.h"

int main(void)
{
    printf("\t\t======================--++++简易整数计算器++++--======================\n");
    printf("\t\t 输入正常的表达式 不支持输入负数 但是计算结果为负可以正常计算\n");
    printf("\t\t 可以随意输入空格或冗余括号提升可读性 计算结果保留两位小数\n");
    printf("\t\t 若输入的表达式有误会提示重新输入 若出现数学错误会终止程序\n");
    printf("\t\t======================================================================\n\n");
    while (1)
    {
        char midExp[1000];
        char* lastExp;
        printf("\n输入算式：");
        gets_s(midExp);
        if (!isMidExperssion(midExp))
        {
            printf("算式不合法，请重新输入！\n");
            continue;
        }
        MidExpToLastExp(midExp, lastExp);
        printf("自动生成的后缀表达式为 ：%s\n", lastExp);  // (2+3)*60-9*(3+4)+3-50  == 190
        printf("结果为：%.2llf\n\n", calcLastExperssion(lastExp));
        delete[] lastExp;
    }
    return 0;
}




