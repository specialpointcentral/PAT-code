// B1028.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

typedef struct {
	string name;
	string birthday;
} People;
bool compare(People p1, People p2);
int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	string compare1 = "2014/09/06";
	string compare2 = "1814/09/06";
	vector<People> man;
	while (n--) {
		People temp;
		cin >> temp.name >> temp.birthday;
		if (temp.birthday <= compare1 && temp.birthday >= compare2) {
			man.push_back(temp);
		}
	}
	sort(man.begin(), man.end(), compare);
	if (man.size() == 0)
		cout << man.size();
	else
		cout << man.size() << " " << man.front().name << " " << man.back().name;
}
bool compare(People p1, People p2) {
	return p1.birthday < p2.birthday;
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
