// A1089.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <algorithm>
using namespace std;
bool insertSort(int *o, int *r, int n);
void mergeSort(int *o, int *r, int n);
bool cmpOrigin(int *a, int *b, int n);
int main()
{
	int n;
	cin >> n;
	int *origin = new int[n];
	int *result = new int[n];
	int *tmp = new int[n];
	for (int i = 0; i < n; ++i) {
		cin >> origin[i];
		tmp[i] = origin[i];
	}
	for (int i = 0; i < n; ++i) {
		cin >> result[i];
	}
	if (insertSort(origin, result, n)) {
		cout << "Insertion Sort" << "\n";
		for (int i = 0; i < n; ++i) {
			cout << origin[i];
			if (i != n - 1) cout << " ";
		}
	}
	else {
		mergeSort(tmp, result, n);
		cout << "Merge Sort" << "\n";
		for (int i = 0; i < n; ++i) {
			cout << tmp[i];
			if (i != n - 1) cout << " ";
		}
	}


	delete(origin);
	delete(result);
	delete(tmp);
	return 0;
}

bool insertSort(int *o, int *r, int n) {
	bool flag = false; // 是否相同
	// 先写插入排序
	for (int i = 1; i < n; ++i) {
		// 确定排序的元素
		// 先开始判断是否同
		if (i != 1 && cmpOrigin(o, r, n)) flag = true;
		int j = i, tmp = o[i];
		while (j > 0 && tmp < o[j - 1]) {
			o[j] = o[j - 1];
			j--;
		}
		o[j] = tmp;
		if (flag) {
			return true;
		}
	}
	return false;
}

void mergeSort(int *o, int *r, int n) {
	bool flag = false; // 是否相同
	// 先写归并排序
	for (int step = 2; step / 2 < n; step *= 2) {
		if (step != 2 && cmpOrigin(o, r, n)) flag = true;
		for (int i = 0; i < n; i += step) {
			sort(o + i, o + min(step + i, n));
		}
		if (flag) {
			break;
		}
	}
}
bool cmpOrigin(int *a, int *b, int n) {
	for (int i = 0; i < n; ++i) {
		if (a[i] != b[i]) {
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
