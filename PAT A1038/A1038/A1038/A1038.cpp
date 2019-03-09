// A1038.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector<string> inputNum;
	while (n--) {
		string tmp;
		cin >> tmp;
		inputNum.push_back(tmp);
	}
	// 字典序小的放在最前面
	sort(inputNum.begin(), inputNum.end(), [](string a, string b) {
		return a + b < b + a;
	});
	for (int i = 1; i < inputNum.size(); ++i) {
		inputNum[0].append(inputNum[i]);
	}
	while (inputNum[0].size() > 1 && inputNum[0][0] == '0') {
		inputNum[0].erase(inputNum[0].begin());
	}
	cout << inputNum[0];
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
