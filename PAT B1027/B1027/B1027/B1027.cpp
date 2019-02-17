// B1027.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	int n;
	char k;
	cin >> n >> k;
	int x = (int)sqrt(2 * (n + 1)) - 1;
	if (x % 2 == 0) --x;
	int used = pow(x + 1, 2) / 2 - 1;
	for (int i = x; abs(i) <= x; i = i - 2) {
		// 列循环
		if (i != -1) {
			// 丢掉一个
			for (int j = 0; j < (x - abs(i)) / 2; ++j) {
				// 打印空格
				cout << " ";
			}
			for (int j = 0; j < abs(i); ++j) {
				// 打印图形
				cout << k;
			}
			cout << endl;
		}
	}
	cout << n - used;
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
