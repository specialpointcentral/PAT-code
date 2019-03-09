// B1003.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	while (n--) {
		string input;
		cin >> input;
		int beforeA = 0, midA = 0, afterA = 0;
		bool meetP = false, meetT = false; // 是否遇到P/T
		bool isFlag = true;
		for (int i = 0; i < input.size() && isFlag; ++i) {
			switch (input[i])
			{
			case 'A':
				if (!meetP) {
					// beforeA
					++beforeA;
				}
				else if (meetP && !meetT) {
					// midA
					++midA;
				}
				else if (meetT) {
					// afterA
					++afterA;
				}
				break;
			case 'P':
				if (meetP) {
					// 说明有多个P
					isFlag = false;
				}
				else if (meetT) {
					// 说明P前有T
					isFlag = false;
				}
				meetP = true;
				break;
			case 'T':
				if (meetT) {
					// 说明有多个T
					isFlag = false;
				}
				else if (!meetP) {
					// T前没P
					isFlag = false;
				}
				meetT = true;
				break;
			default:
				// error
				isFlag = false;
				break;
			}
		}

		// 判断是否正确
		if (beforeA * midA == afterA && midA > 0 && meetP && meetT) {
			isFlag = true;
		}
		else {
			isFlag = false;
		}

		if (isFlag) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
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
