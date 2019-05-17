// B1007-another.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cout.tie(0);
	cin.tie(0);
	int n;
	vector<int> primes;
	cin >> n;
	bool *isPrime = new bool[n + 1];

	// 赋值 初始值
	for (int i = 2; i < n + 1; ++i) {
		isPrime[i] = true;
	}
	// 开始排除不是素数
	for (int i = 2; i < n + 1; ++i) {
		if (isPrime[i]) {
			// 是素数
			primes.push_back(i);
			// 剔除其他的不是素数的值
			for (int j = 2; j * i <= n + 1; ++j) {
				// j-倍数
				isPrime[j * i] = false;
			}
		}
	}
	// 判断是否是2
	int count = 0;
	for (int i = 0; i < primes.size() - 1; ++i) {
		if (primes[i + 1] - primes[i] == 2) {
			++count;
		}
	}
	cout << count;
	delete(isPrime);
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
