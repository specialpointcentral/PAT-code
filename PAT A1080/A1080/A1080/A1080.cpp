// A1080.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
	int GE, GI;
	int id;
	int rank; // 排名
	int want[5]; // 志愿
}Student;
typedef struct {
	int remain; // 剩余招生名额
	int minrank = 0; // 招生最低的名次
	vector<Student> stu; // 收取的学生
}School;
int main()
{
	ios::sync_with_stdio(false);
	int n, m, k; // 学生数，院校数，志愿数
	vector<School> school;
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) {
		School tmp;
		cin >> tmp.remain;
		school.push_back(tmp);
	}
	vector<Student> stu;
	for (int i = 0; i < n; ++i) {
		Student tmp;
		cin >> tmp.GE >> tmp.GI;
		tmp.id = i;
		// 循环输入志愿
		for (int j = 0; j < k; ++j) {
			cin >> tmp.want[j];
		}
		stu.push_back(tmp);
	}
	// 排序
	sort(stu.begin(), stu.end(), [](Student a, Student b)->bool {
		int suma = a.GE + a.GI;
		int sumb = b.GE + b.GI;
		if (suma != sumb) return suma > sumb;
		else return a.GE > b.GE;
	});
	// 排名
	stu[0].rank = 1;
	for (int i = 1; i < stu.size(); ++i) {
		if (stu[i].GE == stu[i - 1].GE && stu[i].GI == stu[i - 1].GI) {
			stu[i].rank = stu[i - 1].rank;
		}
		else {
			stu[i].rank = i + 1;
		}
	}
	for (int i = 0; i < stu.size(); ++i) {
		// 按照名次从高到低开始录取
		for (int j = 0; j < k; ++j) {
			// 依次按照志愿顺序录取
			int schoolNum = stu[i].want[j];
			if (school[schoolNum].remain > 0 || school[schoolNum].minrank == stu[i].rank) {
				// 录取
				school[schoolNum].stu.push_back(stu[i]);
				--school[schoolNum].remain;
				school[schoolNum].minrank = stu[i].rank;
				break;
			}
		}
	}
	for (int i = 0; i < school.size(); ++i) {
		sort(school[i].stu.begin(), school[i].stu.end(), [](Student a, Student b)->bool {
			return a.id < b.id;
		});
		if (school[i].stu.size() == 0) cout << "\n";
		for (int j = 0; j < school[i].stu.size(); ++j) {
			cout << school[i].stu[j].id;
			if (j == school[i].stu.size() - 1) cout << "\n";
			else cout << " ";
		}
	}


	return 0;
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
