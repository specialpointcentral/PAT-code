// A1036.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
using namespace std;
typedef struct {
	string name;
	string id;
	char sex;
	int score;
}People;
int main()
{
	int n;
	cin >> n;
	People F, M;
	F.score = -1;
	M.score = 101;
	while (n--) {
		People temp;
		cin >> temp.name >> temp.sex >> temp.id >> temp.score;
		if (temp.sex == 'M'&&temp.score < M.score) {
			// 男生，求最低分
			M = temp;
		}
		else if (temp.sex == 'F'&&temp.score > F.score) {
			// 女生，求最高分
			F = temp;
		}
	}
	if (F.score == -1) {
		cout << "Absent" << endl;
	}
	else {
		cout << F.name << " " << F.id << endl;
	}
	if (M.score == 101) {
		cout << "Absent" << endl;
	}
	else {
		cout << M.name << " " << M.id << endl;
	}
	if (F.score == -1 || M.score == 101) {
		cout << "NA";
	}
	else {
		cout << F.score - M.score;
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
