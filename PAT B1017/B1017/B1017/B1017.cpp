// B1017.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <queue>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	string bigNumber;
	int div;
	cin >> bigNumber >> div;
	queue<int> result;
	int c = 0; // 前序剩余的余数
	for (int i = 0; i < bigNumber.size(); ++i) {
		int thisBit = bigNumber[i] - '0';
		// 计算余数
		c = c * 10 + thisBit;
		// 第一步 得出位结果
		int bitRes = c / div;
		if (bitRes != 0 || !result.empty()) {
			// 第二步 计算出余数和此位的结果
			c = c % div;
			result.push(bitRes);
		}
	}
	if (result.size() == 0) result.push(0);
	while (!result.empty()) {
		cout << result.front();
		result.pop();
	}
	cout << " "<<c;
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
