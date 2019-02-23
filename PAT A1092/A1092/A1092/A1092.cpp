// A1092.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <map>
using namespace std;
int main()
{
	map<char, int> contain;
	string before, need;
	getline(cin, before);
	getline(cin, need);
	// 添加需要什么
	for (int i = 0; i < before.size(); ++i) {
		if (contain.count(before[i]) > 0) {
			++contain[before[i]];
		}
		else {
			contain[before[i]] = 1;
		}
	}
	// 用了
	for (int i = 0; i < need.size(); ++i) {
		if (contain.count(need[i]) > 0) {
			--contain[need[i]];
		}
		else {
			contain[need[i]] = -1;
		}
	}
	// 检查需要多少缺少多少
	int needs = 0, mores = 0;
	for (auto it = contain.begin(); it != contain.end(); ++it) {
		if (it->second > 0) {
			// 多余
			mores += it->second;
		}
		else if (it->second < 0) {
			// 少了
			needs += (-it->second);
		}
	}
	if (needs > 0) {
		// 少了
		cout << "No " << needs;
	}
	else {
		cout << "Yes " << mores;
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
