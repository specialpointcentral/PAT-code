﻿// A1041.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<int> bets;
	map<int, bool> check; // false-有相同
	while (n--) {
		int tmp;
		cin >> tmp;
		bets.push_back(tmp);
		if (check.count(tmp)) {
			// 加入
			check[tmp] = false;
		}
		else {
			check[tmp] = true;
		}
	}
	auto it = bets.begin();
	for (; it != bets.end(); ++it) {
		if (check[*it]) {
			// 第一个不重复的
			cout << *it;
			break;
		}
	}
	if (it == bets.end()) {
		cout << "None";
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
