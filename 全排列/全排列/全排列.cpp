// 全排列.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
using namespace std;
void generate(int *p, vector<int> node, int remain);
int main()
{
	ios::sync_with_stdio(false);
	int n; // 全排列 从1到n
	cin >> n;
	int *p = new int[n];
	vector<int> node;
	memset(p, 0, sizeof(int)* n);
	generate(p, node, n);
}

void generate(int *p, vector<int> node, int remain) {
	if (remain == 0) {
		for (auto it = node.begin(); it != node.end(); ++it) {
			cout << *it;
			if	(it != node.end() - 1) cout << " ";
		}
		cout << "\n";
		return; // 递归出口
	}
	else {
		for (int i = 0, point = 0; i < remain; ++i) {
			point++;
			if (p[point - 1] == 0) {
				// 未被用
				node.push_back(point);
				p[point - 1] = 1;
				generate(p, node, remain - 1);
				// 恢复
				node.erase(node.end() - 1);
				p[point - 1] = 0;
			}
			else {
				--i;
			}
		}
	}
	return;
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
