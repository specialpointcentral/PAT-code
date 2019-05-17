// A1032.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	struct node
	{
		string data;
		int next;
		bool has = false;
	};
	node *list = new node[100000];
	int begin1, begin2;
	cin >> begin1 >> begin2;
	int n;
	cin >> n;
	getchar();
	while (n--) {
		int addr;
		cin >> addr;
		getchar();
		cin	>> list[addr].data >> list[addr].next;
	}
	// first pass
	while (begin1 != -1) {
		list[begin1].has = true;
		begin1 = list[begin1].next;
	}
	// second pass
	while (begin2 != -1) {
		if (list[begin2].has) {
			break;
		}
		else list[begin2].has = true;
		begin2 = list[begin2].next;
	}
	if (begin2 != -1) {
		char output[7];
		sprintf(output, "%05d", begin2);
		cout << output;
	}else
		cout << "-1";
	delete[]list;
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
