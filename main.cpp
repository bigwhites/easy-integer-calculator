#include"nead.h"

int main(void)
{
    printf("\t\t======================--++++��������������++++--======================\n");
    printf("\t\t ���������ı��ʽ ��֧�����븺�� ���Ǽ�����Ϊ��������������\n");
    printf("\t\t ������������ո���������������ɶ��� ������������λС��\n");
    printf("\t\t ������ı��ʽ�������ʾ�������� ��������ѧ�������ֹ����\n");
    printf("\t\t======================================================================\n\n");
    while (1)
    {
        char midExp[1000];
        char* lastExp;
        printf("\n������ʽ��");
        gets_s(midExp);
        if (!isMidExperssion(midExp))
        {
            printf("��ʽ���Ϸ������������룡\n");
            continue;
        }
        MidExpToLastExp(midExp, lastExp);
        printf("�Զ����ɵĺ�׺���ʽΪ ��%s\n", lastExp);  // (2+3)*60-9*(3+4)+3-50  == 190
        printf("���Ϊ��%.2llf\n\n", calcLastExperssion(lastExp));
        delete[] lastExp;
    }
    return 0;
}




