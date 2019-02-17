// B1012.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdio>

int main()
{
	int temp;
	int A1 = 0, A2 = 0, A3 = 0, A4 = 0, A5 = 0;
	int A1count=0, A2count = 0, A3count = 0,A4count = 0, A5count = 0;
	bool A2flag = true; // 交错求和标志，true表示+
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &temp);
		if (temp % 10 == 0) { // A1
			A1 += temp;
			++A1count;
		}
		if (temp % 5 == 1) { // A2
			if (A2flag) {
				A2 += temp;
				A2flag = false;
			}
			else {
				A2 -= temp;
				A2flag = true;
			}
			++A2count;
		}
		if (temp % 5 == 2) { // A3
			++A3;
			++A3count;
		}
		if (temp % 5 == 3) { // A4
			A4 += temp;
			++A4count;
		}
		if (temp % 5 == 4) { // A5
			if (temp > A5) {
				A5 = temp;
			}
			++A5count;
		}
	}

	if (A1count == 0) {
		printf("N ");
	}
	else {
		printf("%d ", A1);
	}
	if (A2count == 0) {
		printf("N ");
	}
	else {
		printf("%d ", A2);
	}
	if (A3count == 0) {
		printf("N ");
	}
	else {
		printf("%d ", A3);
	}
	if (A4count == 0) {
		printf("N ");
	}
	else {
		printf("%.1f ", (double)A4 / A4count);
	}
	if (A5count == 0) {
		printf("N");
	}
	else {
		printf("%d", A5);
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
