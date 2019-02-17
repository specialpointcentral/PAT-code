// B1048.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
char getNum(int a);
int main()
{
	string A, B, temp;
	cin >> A >> B;
	reverse(A.begin(), A.end());
	reverse(B.begin(), B.end());
	for (int i = 0; i < max(A.size(), B.size()); ++i) {
		int Anum = i < A.size() ? A[i] - '0' : 0;
		int Bnum = i < B.size() ? B[i] - '0' : 0;
		if (i % 2 == 0) {
			temp += getNum((Bnum + Anum) % 13);
		}
		else {
			int tmp;
			tmp = Bnum - Anum;
			if (tmp < 0) tmp += 10;
			temp += (tmp + '0');
		}
	}
	reverse(temp.begin(), temp.end());
	cout << temp;
	return 0;
}
char getNum(int a) {
	if (a < 10) return a + '0';
	else
		switch (a)
		{
		case 10:
			return 'J';
		case 11:
			return 'Q';
		case 12:
			return 'K';
		default:
			break;
		}
	return '0';
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
