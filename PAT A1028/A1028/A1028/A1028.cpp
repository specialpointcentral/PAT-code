// A1028.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;
typedef struct {
	string id;
	string name;
	int score;
}Student;
bool cmp1(Student, Student);
bool cmp2(Student, Student);
bool cmp3(Student, Student);
int main()
{
	ios::sync_with_stdio(false);
	int n, c;
	cin >> n >> c;
	vector<Student> stu;
	while (n--) {
		Student tmp;
		cin >> tmp.id >> tmp.name >> tmp.score;
		stu.push_back(tmp);
	}
	bool(*p[3])(Student, Student) = { cmp1,cmp2,cmp3 };
	sort(stu.begin(), stu.end(), p[c - 1]);
	for (int i = 0; i < stu.size(); ++i) {
		// 使用"\n"，若用endl，运行超时
		cout << stu[i].id << " " << stu[i].name << " " << stu[i].score << "\n";
	}
	return 0;
}
bool cmp1(Student a, Student b) {
	return a.id < b.id;
}
bool cmp2(Student a, Student b) {
	if (a.name != b.name)
		return a.name < b.name;
	else
		return a.id < b.id;
}
bool cmp3(Student a, Student b) {
	if (a.score != b.score)
		return a.score < b.score;
	else
		return a.id < b.id;
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
