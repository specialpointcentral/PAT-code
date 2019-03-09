// A1029.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <climits>
#define INF INT_MAX
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int m, n;
	cin >> n;
	int *s1 = new int[n + 1];
	for (int i = 0; i < n; ++i) {
		cin >> s1[i];
	}
	s1[n] = INF;
	cin >> m;
	// 计算中位数个数
	int point = (m + n + 1) >> 1;

	// 开始排序
	int i = 0, j = 0; // i-s1
	int s2;
	cin >> s2;
	while (1) {
		if (point == 1) {
			if (s1[i] > s2) {
				cout << s2;
			}
			else {
				cout << s1[i];
			}
			break;
		}
		if (s1[i] > s2) {
			++j;
			if (j < m) {
				cin >> s2;
			}
			else s2 = INF;
		}
		else {
			++i;
		}
		--point;
	}
	delete(s1);
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
