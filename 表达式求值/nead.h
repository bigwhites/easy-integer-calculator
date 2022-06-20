#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;

typedef long double LDouble;

class Cache  //缓存变量类  用来简化复杂的表达式
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
	void setValue(char logo,int v);//设置变量
	int getValue(char logo);  //得到变量logo的值
	void showCache(void);    //展示缓存
	void buildCache(void);  //构建缓存
	int getSize(void)
	{
		return this->size;
	}
};

void infixToSuffixExp(char* infixExp, char*& suffixExp);  //中缀表达式转后缀表达式
bool isNumber(char x); //是数字
LDouble chToNum(char x); //字符转换成数字
LDouble calc(char op, LDouble n, LDouble m); //后缀表达式计算抛出的最基本运算
bool canPush(char newOp, stack<char>& op); //判断新的运算符是否能入栈 
LDouble calcSuffixExperssion(char* lastExp); //计算后缀表达式
bool isInfixExperssion(char* infixExp);  //判断输入表达式是否合法
bool checkPerCh(char* infixExp); //逐字符扫描检查表达式
bool checkBrackets(char* infixExp); //检查括号是否匹配
bool isOp(char i); //是+ - * /四个基本运算符号
char* cacheSubtitute(char* preInfixExp, Cache& C);//缓存变量替换
int numberInsert(char* preInfixExp, int startLoc, stack<char>& chNum);  //在startLoc后面递归的插入 并更新寻访变量.
bool isNegative(char* infixExp, int pos); //判断是否是负号