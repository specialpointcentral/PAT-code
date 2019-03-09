// A1044.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n, m;
	cin >> n >> m;
	int *sum = new int[n + 1];
	for (int i = 0; i < n + 1; ++i) {
		// 将总和加入
		if (i == 0) {
			sum[0] = 0;
		}
		else {
			int tmp;
			cin >> tmp;
			sum[i] = sum[i - 1] + tmp;
		}
	}

	// 开始查找
	vector<string> output;
	int small = INT_MAX;
	for (int i = 0; i < n + 1; ++i) {
		int left = i, right = n, mid;
		while (left <= right) {
			mid = (left + right) >> 1;
			int cmps = sum[mid] - sum[i];
			if (cmps == m) {
				// 是，输出
				cout << i + 1 << "-" << mid << "\n";
				small = m;
				break;
			}
			if (cmps < m) {
				// 小了，要大一点
				left = mid + 1;
			}
			else {
				// 大了，要小一点，但要同时记录大中最小的，保证之后输出
				if (small >= cmps) {
					if (small > cmps) {
						// 此时产生新的更小的
						output.clear();
						small = cmps;
					}
					// 记录
					string s;
					stringstream tmp;
					tmp << i + 1 << "-" << mid;
					tmp >> s;
					output.push_back(s);
				}
				right = mid - 1;
			}
		}
	}
	if (small > m) {
		// 输出记录
		for (auto it = output.begin(); it != output.end(); ++it) {
			cout << *it << "\n";
		}
	}
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
