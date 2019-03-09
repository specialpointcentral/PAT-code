// A1069.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
using namespace std;
int stringToInt(string a);
string intToString(int a);
int main()
{
	string sresult;
	int result;
	cin >> result;
	sresult = intToString(result);
	while (1) {
		int a, b;
		sort(sresult.begin(),sresult.end());
		b = stringToInt(sresult);
		reverse(sresult.begin(), sresult.end());
		a = stringToInt(sresult);
		result = a - b;
		printf("%04d - %04d = %04d\n", a, b, result);
		if (!result || result == 6174) break;
		sresult = intToString(result);
	}
}

int stringToInt(string a) {
	stringstream ss;
	int tmp;
	ss << a;
	ss >> tmp;
	return tmp;
}

string intToString(int a) {
	string tmp;
	for (int i = 0; i < 4; ++i) {
		tmp.push_back(a % 10 + '0');
		a /= 10;
	}
	return tmp;
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
