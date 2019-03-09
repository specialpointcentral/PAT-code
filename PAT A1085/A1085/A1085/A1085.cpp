// A1085.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int n, p;
	cin >> n >> p;
	int *group = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> group[i];
	}
	sort(group, group + n);
	int maxLenth = 0;
	for (int i = 0; i < n; ++i) {
		// 外层循环，控制第一个
		if (n - i + 1 < maxLenth) {
			// 剪枝，已经没有可能更长了
			break;
		}
		// 二分法
		int left = i + 1, right = n - 1, mid;
		if (left >= right) {
			left = n - 1;
		} 
		while (left < right) {
			// 因为有left = mid，所以使得mid游标要稍微向后走一点，避免出现left+1=right的尴尬局面
			mid = (left + right + 1) >> 1;
			if (group[i] * (long)p >= (long)group[mid]) {
				// 符合要求，可以更大一点
				left = mid;
			}
			else {
				right = mid - 1;
			}
		}
		int max = left - i + 1;
		if (max > maxLenth) maxLenth = max;
	}
	cout << maxLenth;
	delete(group);
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
