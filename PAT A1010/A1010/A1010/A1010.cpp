// A1010.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
long changeToOCT(string num, long radix);
int main()
{
	string n1, n2;
	int tag, radix;
	cin >> n1 >> n2 >> tag >> radix;
	if (tag == 2) {
		swap(n1, n2);
	}
	long n1Num = changeToOCT(n1, radix);
	long left, right = n1Num + 1, mid;
	char p = *max_element(n2.begin(),n2.end());           
	if (p >= 'a') {
		left += p - 'a' + 10;
	}
	else {
		left += p - '0';
	}
	left++;
	long n2Num = -1;
	while (left <= right) {
		mid = (left + right) >> 1;
		n2Num = changeToOCT(n2, mid);
		if (n2Num == n1Num) {
			left = mid;
			break;
		}
		if (n2Num<0 || n2Num > n1Num) {
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	if (n2Num != n1Num) {
		// Impossible
		cout << "Impossible";
	}
	else {
		cout << left;
	}
	return 0;
}
long changeToOCT(string num, long radix) {
	long nNum = 0;
	for (int i = 0; i < num.size(); ++i) {
		nNum *= radix; // 准备移位，做乘法，进行进制转化
		if (num[i] >= 'a') {
			nNum += num[i] - 'a' + 10;
		}
		else {
			nNum += num[i] - '0';
		}
	}
	return nNum;
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
