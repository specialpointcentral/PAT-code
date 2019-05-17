// A1096.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

struct factors
{
	int factor, cnt;
};
int main()
{
	int m;
	cin >> m;
	int maxLen = 0, startNum = 1, tmpm = m;
	int tmpMaxLen, pvote;
	for (int i = 2; i < sqrt(m); ++i) {
		if (tmpm != m) {
			// 恢复一步，开始位还原
			tmpm = tmpm * (i - 1);
			--tmpMaxLen;
		}
		else {
			tmpMaxLen = 0;
			pvote = i;
		}
		while (1) {
			if (tmpm % pvote == 0) {
				++tmpMaxLen;
				tmpm /= pvote;
				++pvote;
			}
			else break;
		}
		if (maxLen < tmpMaxLen) {
			maxLen = tmpMaxLen;
			startNum = i;
		}
	}

	if (maxLen == 0) {
		// 说明在范围内没有解
		cout << "1\n" << m;
	}
	else {
		cout << maxLen <<"\n";
		for (int i = 0; i < maxLen; ++i) {
			cout << startNum + i;
			if (i < maxLen - 1) {
				cout << "*";
			}
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
