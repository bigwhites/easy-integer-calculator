#include"nead.h"

int main(void)
{
    printf("\t\t======================--++++��������������++++--======================\n");
    printf("\t\t ���������ı��ʽ ���Ǽ�����Ϊ��������������\n");
    printf("\t\t ������������ո���������������ɶ��� ������������λС��\n");
    printf("\t\t ������ı��ʽ�������ʾ�������� ��������ѧ�������ֹ����\n");
    printf("\t\t======================================================================\n\n");
    printf("��������Ҫ�ĸ����������ĸ���(0-26��)��");
    int cacheSize;
    scanf("%d", &cacheSize);
    getchar();
    if (cacheSize > 26) cacheSize = 26;
    Cache C(cacheSize);
    if (cacheSize>0)
    {
        printf("�������������������ֵ�������Ǹ�������������ķǸ�ֵ���ʽ:\n");
        C.buildCache();
        C.showCache();
    }
    printf("\n\n�������ʼ������ \"EXIT\" �������㡣\n\n");
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
            gets_s(preInfixdExp);  //�õ������������׼��׺���ʽ
            infixdExp = cacheSubtitute(preInfixdExp, C);  //��������滻�õ���׺���ʽ  
            //LINE32 ���ڵ����⡰10A"���Aֱ���滻 Ҫ���Ա������ߵļ�� 1.��Ϊ��ֹ10A  2.ת��Ϊ10*A
            if (!isInfixExperssion(infixdExp))  //���������ɵ���׺���ʽ�ĺϷ���
            {
                printf("��ʽ���Ϸ������������룡\n");
                delete[]suffixExp;
                continue;
            }
            infixToSuffixExp(infixdExp, suffixExp); //��׺ת��׺
            printf("�Զ����ɵĺ�׺���ʽΪ ��%s\n", suffixExp);
            printf("���Ϊ��%.2llf\n\n", calcSuffixExperssion(suffixExp)); //������
            delete[]suffixExp;
            delete[]infixdExp;
        }
        if (!strcmp("EXIT", command)) break;
    }
    return 0;
}
// (2+3)*60-9*(3+4)+3-50  == 190 



