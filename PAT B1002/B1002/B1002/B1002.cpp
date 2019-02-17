// B1002.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <cstdio>
#include <stack>
using namespace std;
void printOut(int);
int main()
{
	int sum = 0;
	char s[101];
	scanf("%s", s);
	int i = 0;
	while (1) {
		if (s[i] == 0) break;
		sum += (s[i] - '0');
		++i;
	}
	stack<int> b;
	if (sum == 0) {
		b.push(0);
	}
	while (sum != 0) {
		b.push(sum % 10);
		sum /= 10;
	}
	while (!b.empty()) {
		printOut(b.top());
		b.pop();
		if (!b.empty()) printf("%c",' ');
	}
	return 0;
}

void printOut(int n) {
	switch (n)
	{
	case 0:
		printf("%s", "ling");
		break;
	case 1:
		printf("%s", "yi");
		break;
	case 2:
		printf("%s", "er");
		break;
	case 3:
		printf("%s", "san");
		break;
	case 4:
		printf("%s", "si");
		break;
	case 5:
		printf("%s", "wu");
		break;
	case 6:
		printf("%s", "liu");
		break;
	case 7:
		printf("%s", "qi");
		break;
	case 8:
		printf("%s", "ba");
		break;
	case 9:
		printf("%s", "jiu");
		break;
	default:
		break;
	}
}
// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
