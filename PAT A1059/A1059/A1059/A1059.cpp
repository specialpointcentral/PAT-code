// A1059.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
void findPrime(vector<int> &primeVector, int max);
struct factors
{
	int factor, cnt;
};
int main()
{
	int m, n;
	cin >> m;
	n = m;
	vector<int> primes;
	vector<struct factors> factors;
	findPrime(primes, (int)sqrt(m));
	for (auto it = primes.begin(); it != primes.end();) {
		if (m% *it == 0) {
			// 说明是一个
			if (factors.size() != 0 && factors.back().factor == *it) {
				++factors.back().cnt;
			}
			else {
				struct factors tmp;
				tmp.cnt = 1;
				tmp.factor = *it;
				factors.push_back(tmp);
			}
			m /= *it;
		}
		else {
			++it;
		}
	}
	if (n == 1 || m != 1) {
		// 说明有一个自己
		struct factors tmp;
		tmp.cnt = 1;
		tmp.factor = m;
		factors.push_back(tmp);
	}

	// 将结果输出
	cout << n << "=";
	for (auto it = factors.begin(); it != factors.end(); ++it) {
		cout << it->factor;
		if (it->cnt != 1) {
			cout << "^" << it->cnt;
		}
		if (it != factors.end() - 1) {
			cout << "*";
		}
	}

	return 0;
}
void findPrime(vector<int> &primeVector, int max) {
	bool *flag = new bool[max + 1];
	for (int i = 0; i < max + 1; ++i) {
		flag[i] = true;
	}
	for (int i = 2; i < max + 1; ++i) {
		if (flag[i]) {
			// 是素数
			primeVector.push_back(i);
			// 去除后续的非素数项
			for (int j = 2; j * i < max + 1; ++j) {
				flag[i * j] = false;
			}
		}
	}
	delete(flag);
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
