// A1023.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	string inputNumber;
	cin >> inputNumber;
	vector<int> resoure, result;
	int count[10] = { 0 };
	for (int i = 0; i < inputNumber.size(); ++i) {
		count[inputNumber[i] - '0']++;
		resoure.push_back(inputNumber[i] - '0');
	}
	// 进行乘法计算
	int c = 0;
	for (int i = resoure.size() - 1; i >= 0; --i) {
		int thisBit = resoure[i] * 2 + c;
		c = thisBit / 10;
		result.push_back(thisBit % 10);
	}
	while (c != 0) {
		result.push_back(c % 10);
		c = c / 10;
	}
	reverse(result.begin(),result.end());
	if (result.size() != resoure.size()) {
		// 长度不等，则不同
		cout << "No\n";
	}
	else {
		bool flag = true;
		for (int i = 0; i < result.size(); ++i) {
			if (--count[result[i]] < 0) {
				// 发现小于零
				cout << "No\n";
				flag = false;
				break;
			}
		}
		if(flag)
			cout << "Yes\n";
	}
	for (int i = 0; i < result.size(); ++i) {
		cout << result[i];
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
