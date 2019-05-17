// A1024.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool isPalindromic(vector<int> input);
void caculate(vector<int> a, vector<int> b, vector<int> &c);

int main()
{
	string inputNumber;
	vector<int> bitNumber;
	int step;
	cin >> inputNumber >> step;
	for (int i = inputNumber.size() - 1; i >= 0; --i) {
		// 将数据打入到vector
		bitNumber.push_back(inputNumber[i] - '0');
	}
	// 开始计算
	int i;
	for (i = 0; i < step; ++i) {
		if (isPalindromic(bitNumber)) {
			// 输出
			break;
		}
		vector<int> bitRevNumber = bitNumber,tmp;
		reverse(bitRevNumber.begin(), bitRevNumber.end());
		caculate(bitNumber, bitRevNumber, tmp);
		bitNumber = tmp;
	}
	for (int i = bitNumber.size() - 1; i >= 0; --i) {
		cout << bitNumber[i];
	}
	cout << "\n" << i;
}
bool isPalindromic(vector<int> input) {
	for (int i = 0; i < input.size() / 2; ++i) {
		if (input[i] != input[input.size() - 1 - i]) {
			return false;
		}
	}
	return true;
}
void caculate(vector<int> a, vector<int> b, vector<int> &c) {
	// c = a + b
	int carry = 0, i;
	for (i = 0; i < max(a.size(), b.size()); ++i) {
		int atmp = (a.size() > i) ? a[i] : 0;
		int btmp = (b.size() > i) ? b[i] : 0;
		int bitNubmer = atmp + btmp + carry;
		carry = bitNubmer / 10;
		c.push_back(bitNubmer % 10);
	}
	// 更高位加入
	while (carry) {
		c.push_back(carry % 10);
		carry = carry / 10;
	}
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
