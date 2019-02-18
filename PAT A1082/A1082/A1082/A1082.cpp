// A1082.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <cmath>
using namespace std;
int main()
{
	string num[] = { "ling","yi","er","san","si","wu","liu","qi","ba","jiu" };
	string bit[] = { "","Shi","Bai","Qian","Wan","Yi" };
	long input;
	cin >> input;
	if (input < 0) {
		cout << "Fu ";
		input = -input;
	}
	bool outZero = false; // 输出ling标志

	if (input >= 100000000) {
		// 亿
		cout << num[input / 100000000] << " " << bit[5];
		input %= 100000000;
		if (input > 0) cout << " "; // 输出空格分割下一级
		outZero = true; // 允许下一级输出ling
	}
	if (input >= 10000) {
		// 万
		int tmp = input / 10000;
		for (int i = 3; i >= 0; --i) {
			// 万里面按位
			if (outZero && (tmp / (int)pow(10, i)) % 10 == 0) {
				cout << "ling ";
				outZero = false; // 后续不再输出
			}
			else if ((tmp / (int)pow(10, i)) % 10 != 0) {
				if (tmp % (int)pow(10, i) != 0)
					outZero = true; // 后续输出
				else outZero = false;
				cout << num[(tmp / (int)pow(10, i)) % 10] << " " ;
				if (i != 0) cout << bit[i] << " ";
			}
		}
		cout << bit[4];
		outZero = true; // 允许下一级输出
		input %= 10000;
		if (input > 0) cout << " "; // 输出空格分割下一级
	}
	if (input > 0) {
		// 个
		for (int i = 3; i >= 0; --i) {
			// 个里面按位
			if (outZero && (input / (int)pow(10, i)) % 10 == 0) {
				cout << "ling ";
				outZero = false; // 后续不再输出
			}
			else if ((input / (int)pow(10, i)) % 10 != 0) {
				if (input % (int)pow(10, i) != 0)
					outZero = true; // 后续输出
				else outZero = false;
				cout << num[(input / (int)pow(10, i)) % 10];
				if (i != 0) cout << " " << bit[i];
				if (input % (int)pow(10, i) != 0) cout << " ";
			}
		}
	}
	if (!outZero&&input == 0) {
		cout << "ling";
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
