// B1020.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef struct {
	double store;
	double sell;
}MoonCake;
int main()
{
	int n, need;
	cin >> n >> need;
	vector<MoonCake> cake;
	// 输入月饼的信息
	for (int i = 0; i < n; ++i) {
		MoonCake tmp;
		cin >> tmp.store;
		cake.push_back(tmp);
	}
	for (int i = 0; i < n; ++i) {
		cin >> cake[i].sell;
	}
	sort(cake.begin(), cake.end(), [](MoonCake a, MoonCake b) {
		return a.sell / a.store > b.sell / b.store;
	});
	double get = 0.0;
	for (auto it = cake.begin(); it != cake.end(); ++it) {
		if (need > it->store) {
			// 全部卖出
			get += it->sell;
			need -= it->store;
		}
		else {
			// 卖出部分
			get += (it->sell / it->store)*need;
			break;
		}
	}
	printf("%.2f", get);
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
