// A1077.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
	int n;
	cin >> n;
	string a, b, sub;
	if (n != 0) {
		getchar();
		getline(cin, a);
		reverse(a.begin(), a.end());
		--n;
	}
	while (n--) {
		getline(cin, b);
		// 全部反转
		reverse(b.begin(), b.end());
		// a,b的相同尾子串给sub
		sub.clear();
		for (int i = 0; i < min(b.size(), a.size()); ++i) {
			if (a[i] == b[i]) {
				sub += a[i];
			}
			else {
				break;
			}
		}
		if (a == "") {
			// 已经没有相同子串
			cout << "nai";
			return 0;
		}
		else {
			a = sub;
		}
	}
	reverse(sub.begin(), sub.end());
	cout << sub;
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
