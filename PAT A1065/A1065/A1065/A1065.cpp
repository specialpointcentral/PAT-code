// A1065.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
using namespace std;

int main()
{
	int count = 1;
	long long a, b, c;
	int n;
	bool flag; // true - a + b > c
	cin >> n;
	while (n--) {
		cin >> a >> b >> c;
		long long temp = a + b;
		if (a > 0 && b > 0 && temp < 0) {
			// 正溢出
			flag = true;
		}
		else if (a < 0 && b < 0 && temp >= 0) {
			// 注意：要temp >= 0
			// 负溢出
			flag = false;
		}
		else flag = (temp > c);
		if (flag) {
			cout << "Case #" << count++ << ": true" << endl;
		}
		else {
			cout << "Case #" << count++ << ": false" << endl;
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
