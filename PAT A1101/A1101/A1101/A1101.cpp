// A1101.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int *all = new int[n];
	int *leftMax = new int[n];
	int *rightMin = new int[n];
	// 建立左区最大值
	int max = 0;
	for (int i = 0; i < n; ++i) {
		cin >> all[i];
		if (max < all[i]) {
			// 说明需要更改
			max = all[i];
		}
		leftMax[i] = max;
	}
	// 建立右区最小值
	int min = INT_MAX;
	for (int i = n - 1; i >= 0; --i) {
		if (min > all[i]) {
			min = all[i];
		}
		rightMin[i] = min;
	}
	// 每位判断
	vector<int> correct;
	for (int i = 0; i < n; ++i) {
		if (all[i] < leftMax[i] || all[i] > rightMin[i]) {
			continue;
		}
		else {
			correct.push_back(all[i]);
		}
	}

	sort(correct.begin(), correct.end());
	cout << correct.size() << "\n";
	for (int i = 0; i < correct.size(); ++i) {
		cout << correct[i];
		if (i < correct.size() - 1) cout << " ";
	}
	cout << endl;
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
