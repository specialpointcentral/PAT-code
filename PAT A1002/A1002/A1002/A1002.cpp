// A1002.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <cstdio>
using namespace std;
int main()
{
	int n, max_n = 0;
	double p[1001] = { 0 };
	for (int i = 0; i < 2; ++i) {
		scanf("%d", &n);
		while (n--) {
			int a;
			double k;
			scanf("%d %lf", &a, &k);
			if (max_n < a) max_n = a; // 确定最高系数
			p[a] += k;
		}
	}
	int count = 0;
	for (int i = 0; i < max_n + 1; ++i) {
		if (p[i] != 0) ++count;
	}
	printf("%d", count);
	for (int i = max_n; i >=0; --i) {
		if (p[i] != 0) {
			printf(" %d %.1f", i, p[i]);
		}
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
