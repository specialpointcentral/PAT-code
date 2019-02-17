// B1031.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
bool isCorrect(string s);
int main()
{
	int n;
	string id;
	bool flag = false; // 标志，是否有错误
	cin >> n;
	while (n--) {
		cin >> id;
		if (!isCorrect(id)) {
			flag = true;
			cout << id << endl;
		}
	}
	if (!flag) {
		cout << "All passed";
	}
	return 0;
}
bool isCorrect(string s) {
	char check[] = { '1' , '0' , 'X' , '9' , '8' , '7' , '6' , '5' , '4' , '3' , '2' };
	int weight[] = { 7 , 9 , 10 , 5 , 8 , 4 , 2 , 1 , 6 , 3 , 7 , 9 , 10 , 5 , 8 , 4 , 2 };
	int sum = 0;
	for (int i = 0; i < 17; ++i) {
		if (s[i] >= '0'&&s[i] <= '9') {
			// 要注意判断是否符合最基础条件
			sum = sum + (weight[i] * (s[i] - '0'));
		}
		else {
			return false;
		}
	}
	if (s[17] == check[sum % 11]) return true;
	else return false;
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
