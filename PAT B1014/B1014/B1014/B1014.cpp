// B1014.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>

using namespace std;
string getDay(int a);
int main()
{
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	char temp1, temp2;
	int temp3 = 0;
	int i;
	// 查找第一个
	for (i = 0; a[i] != 0 && b[i] != 0; ++i) {
		if (a[i] == b[i] && a[i] >= 'A'&&a[i] <= 'G') {
			temp1 = a[i];
			break;
		}
	}
	// 查找第二个
	for (i++; a[i] != 0 && b[i] != 0; ++i) {
		if (a[i] == b[i] && ((a[i] >= 'A'&&a[i] <= 'N') || (a[i] >= '0'&&a[i] <= '9'))) {
			temp2 = a[i];
			break;
		}
	}
	// 查找第三个
	for (i = 0; c[i] != 0 && d[i] != 0; ++i) {
		if (c[i] == d[i] && ((c[i] >= 'A'&&c[i] <= 'Z') || (c[i] >= 'a'&&c[i] <= 'z'))) {
			break;
		}
		++temp3;
	}
	cout << getDay(temp1 - 'A' + 1) << " ";
	if (temp2 <= '9') {
		cout << "0" << temp2 - '0' << ":";
	}
	else {
		cout << temp2 - 'A' + 10 << ":";
	}
	cout << temp3 / 10 << temp3 % 10;
}
string getDay(int a) {
	switch (a)
	{
	case 1:
		return "MON";
		break;
	case 2:
		return "TUE";
		break;
	case 3:
		return "WED";
		break;
	case 4:
		return "THU";
		break;
	case 5:
		return "FRI";
		break;
	case 6:
		return "SAT";
		break;
	case 7:
		return "SUN";
		break;
	default:
		return "";
		break;
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
