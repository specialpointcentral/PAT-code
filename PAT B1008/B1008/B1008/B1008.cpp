// B1008.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;
int gcd(int a, int b) {
	if (a < b) swap(a, b);
	if (b == 0) return a;
	else {
		return gcd(b, a % b);
	}
}
int main()
{
	int n, move;
	cin >> n >> move;
	int *a = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}
	// 进行内存移动
	move = move % n;
	int d = gcd(n, move);
	if (d != n) {
		for (int i = 0; i < d; ++i) {
			int tmp = a[i], j;
			for (j = 0; j < n / d - 1; ++j) {
				a[(n * j + i - j * move) % n] = a[(n * (j + 1) + i - (j + 1) * move) % n];
			}
			a[(n * j + i - j * move) % n] = tmp;
		}
	}
	for (int i = 0; i < n; ++i) {
		cout << a[i];
		if (i < n - 1) cout << " ";
	}
	delete(a);
	return 0;
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
