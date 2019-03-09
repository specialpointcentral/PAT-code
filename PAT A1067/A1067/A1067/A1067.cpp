// A1067.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	int pos[100000];
	int n, change = 0;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		int tmp;
		cin >> tmp;
		pos[tmp] = i;
		if (tmp != i) {
			// 需要移位
			++change;
		}
	}
	int swapTime = 0;
	                                                                                           
	while (change--) {
		if (pos[0] == 0) {
			// 0在原来位置，需要做调换
			if (change == 0) {
				// 最后一次调换，是0到原位
				break;
			}
			static int i = 1;
			// int i = 1; 若用此，会超时，原因：每次重复判断已经归位的数据
			while (pos[i] == i) ++i; // 寻找交换对象
			swap(pos[0],pos[i]);
			change += 1;
			++swapTime;
		}
		else {
			swap(pos[0], pos[pos[0]]);
			++swapTime;
		}
	}
	cout << swapTime;
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
