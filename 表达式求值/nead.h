#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

typedef long double LDouble;

class Cache  //���������  �����򻯸��ӵı��ʽ
{
protected:
	int *value;
	int size;
public:
	Cache(int cacheSize)
	{
		int s=cacheSize;
		if (s <= 0) return;
		value = new int[cacheSize + 1];
		size = cacheSize;
	}
	void setValue(char logo,int v);//���ñ���
	int getValue(char logo);  //�õ�����logo��ֵ
	void showCache(void);    //չʾ����
	void buildCache(void);  //��������
	int getSize(void)
	{
		return this->size;
	}
};

void infixToSuffixExp(char* infixExp, char*& suffixExp);  //��׺���ʽת��׺���ʽ
bool isNumber(char x); //������
LDouble chToNum(char x); //�ַ�ת��������
LDouble calc(char op, LDouble n, LDouble m); //��׺���ʽ�����׳������������
bool canPush(char newOp, stack<char>& op); //�ж��µ�������Ƿ�����ջ 
LDouble calcSuffixExperssion(char* lastExp); //�����׺���ʽ
bool isInfixExperssion(char* infixExp);  //�ж�������ʽ�Ƿ�Ϸ�
bool checkPerCh(char* infixExp); //���ַ�ɨ������ʽ
bool checkBrackets(char* infixExp); //��������Ƿ�ƥ��
bool isOp(char i); //��+ - * /�ĸ������������
char* cacheSubtitute(char* preInfixExp, Cache& C);//��������滻
int numberInsert(char* preInfixExp, int startLoc, stack<char>& chNum);  //��startLoc����ݹ�Ĳ��� ������Ѱ�ñ���.
bool isNegative(char* infixExp, int pos); //�ж��Ƿ��Ǹ���