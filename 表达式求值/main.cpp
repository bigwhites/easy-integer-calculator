#include"nead.h"

int main(void)
{
    printf("\t\t======================--++++简易整数计算器++++--======================\n");
    printf("\t\t 输入正常的表达式 但是计算结果为负可以正常计算\n");
    printf("\t\t 可以随意输入空格或冗余括号提升可读性 计算结果保留两位小数\n");
    printf("\t\t 若输入的表达式有误会提示重新输入 若出现数学错误会终止程序\n");
    printf("\t\t======================================================================\n\n");
    printf("请输入需要的辅助缓存器的个数(0-26个)：");
    int cacheSize;
    scanf("%d", &cacheSize);
    getchar();
    if (cacheSize > 26) cacheSize = 26;
    Cache C(cacheSize);
    if (cacheSize>0)
    {
        printf("请依次输入各缓存器的值，可以是个不带缓存变量的非负值表达式:\n");
        C.buildCache();
        C.showCache();
    }
    printf("\n\n计算程序开始，输入 \"EXIT\" 结束计算。\n\n");
    while (1)
    {
        char preInfixdExp[1000];
        char* infixdExp = nullptr;
        char* suffixExp = nullptr;
        char command[40];
        printf("\nInput command >>>");
        scanf("%s", command);
        getchar();
        if (!strcmp(command, "calc"))
        {
            gets_s(preInfixdExp);  //得到带缓存变量的准中缀表达式
            infixdExp = cacheSubtitute(preInfixdExp, C);  //缓存变量替换得到中缀表达式  
            //LINE32 存在的问题“10A"会把A直接替换 要做对变量两边的检查 1.设为禁止10A  2.转换为10*A
            if (!isInfixExperssion(infixdExp))  //检测最后生成的中缀表达式的合法性
            {
                printf("算式不合法，请重新输入！\n");
                delete[]suffixExp;
                continue;
            }
            infixToSuffixExp(infixdExp, suffixExp); //中缀转后缀
            printf("自动生成的后缀表达式为 ：%s\n", suffixExp);
            printf("结果为：%.2llf\n\n", calcSuffixExperssion(suffixExp)); //计算结果
            delete[]suffixExp;
            delete[]infixdExp;
        }
        if (!strcmp("EXIT", command)) break;
    }
    return 0;
}
// (2+3)*60-9*(3+4)+3-50  == 190 



