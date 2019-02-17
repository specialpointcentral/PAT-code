// A1031.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	string input;
	cin >> input;
	int n1 = (input.size() + 2) / 3;
	int n2 = input.size() + 2 - n1 * 2;
	for (int i = 0; i < n1; ++i) {
		// 列
		if (i == n1 - 1) {
			// 最后一行
			for (int j = 0; j < n2; ++j) {
				cout << input[i + j];
			}
		}
		else {
			for (int j = 0; j < n2; ++j) {
				if (j == 0) cout << input[i];
				else if (j == n2 - 1) cout << input[input.size()-1-i];
				else cout << " ";
			}
			cout << endl;
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
