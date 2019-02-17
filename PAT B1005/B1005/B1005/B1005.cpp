// B1005.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
	int type; // 0-没被选中，1-首次，2-覆盖
	int number;
}Array;
void setType(Array*, int, int, int);
bool needContinue(Array*, int, int);
bool cmp(Array, Array);

int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	Array *p = new Array[n];
	for (int i = 0; i < n; ++i) {
		cin >> p[i].number;
		p[i].type = 0;
	}
	for (int i = 0; i < n; ++i) {
		if (p[i].type != 0) continue; // 已经被标记了
		else p[i].type = 1; // 标记成首次
		int temp = p[i].number;
		while (temp != 1) {
			if (temp % 2 == 0) {
				temp /= 2;
				// 短路，减少复杂度
				if (!needContinue(p, n, temp)) break;
				setType(p, n, temp, 2);
			}
			else {
				temp = (temp * 3 + 1) / 2;
				// 短路，减少复杂度
				if (!needContinue(p, n, temp)) break;
				setType(p, n, temp, 2);
			}
		}
	}
	vector<Array> box;
	for (int i = 0; i < n; ++i) {
		// 符合条件的压入容器中
		if (p[i].type == 1) box.push_back(p[i]);
	}
	sort(box.begin(), box.end(), cmp);
	for (int i = 0; i < box.size() - 1; ++i) {
		printf("%d ", box[i].number);
	}
	printf("%d", box[box.size() - 1].number);
	return 0;
}
void setType(Array *p, int n, int temp, int type) { //标记
	for (int i = 0; i < n; ++i) {
		if (p[i].number == temp) {
			p[i].type = type;
			break;
		}
	}
}
bool cmp(Array a, Array b) {
	return a.number > b.number;
}
bool needContinue(Array *p, int n, int temp) {
	for (int i = 0; i < n; ++i) {
		if (p[i].number == temp) {
			if (p[i].type == 2)
				return false;
		}
	}
	return true;
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
