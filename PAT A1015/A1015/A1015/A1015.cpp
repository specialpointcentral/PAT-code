// A1015.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(int a) {
	if (a == 1) return false;
	for (int i = 2; i <= sqrt(a); ++i) {
		if (a % i == 0) return false;
	}
	return true;
}
int changeBack(int origin, int radix) {
	int tmp = 0;
	while (origin > 0) {
		// 顺序进制转化
		// 倒序累加
		tmp = tmp * radix + origin % radix;
		origin /= radix;
	}
	return tmp;
}
int main()
{
	int num, radix;
	while (cin >> num >> radix) {
		if (!isPrime(num)) {
			cout << "No\n";
		}
		else if (isPrime(changeBack(num, radix))) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
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
