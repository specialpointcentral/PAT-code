// A1037.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main()
{
	int n;
	vector<int> club1;
	vector<int> club2;
	cin >> n;
	while (n--) {
		int tmp;
		cin >> tmp;
		club1.push_back(tmp);
	}
	cin >> n;
	while (n--) {
		int tmp;
		cin >> tmp;
		club2.push_back(tmp);
	}
	sort(club1.begin(), club1.end());
	sort(club2.begin(), club2.end());
	long result = 0;
	for (int i = 0; i < min(club1.size(), club2.size()); ++i) {
		if (club1[i] < 0 && club2[i] < 0) {
			result += club1[i] * club2[i];
		}
		else {
			break;
		}
	}
	for (int i = 0; i < min(club1.size(), club2.size()); ++i) {
		if (club1[club1.size() - i - 1] > 0 && club2[club2.size() - i - 1] > 0) {
			result += club1[club1.size() - i - 1] * club2[club2.size() - i - 1];
		}
		else {
			break;
		}
	}
	cout << result;
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
