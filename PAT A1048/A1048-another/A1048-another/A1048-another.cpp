// A1048-another.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	int n, m; //n - total number m - amount of money
	cin >> n >> m;
	int *coins = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> coins[i];
	}
	sort(coins, coins + n);
	bool findOne = false;
	for (int i = 0; i < n ; ++i) {
		if (coins[i] + coins[n - 1] < m) {
			continue;
		}
		int left = i + 1, right = n - 1, mid;
		while (left <= right) {
			mid = (left + right) >> 1;
			int sum = coins[i] + coins[mid];
			if (sum == m) {
				cout << coins[i] << " " << coins[mid];
				findOne = true;
				break;
			}
			if (sum > m) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		// 找到就不再循环
		if (findOne) {
			break;
		}
	}
	if (!findOne) {
		cout << "No Solution";
	}
	delete(coins);
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
