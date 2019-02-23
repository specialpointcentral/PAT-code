// A1075.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;

typedef struct {
	int id;
	int score[5] = { 0 }; // 每题
	bool haveDo[5] = { false }; // 是否做
	bool flag = false; // 是否输出
	int solved = 0; // 解决数
	int allScore = 0; // 总分
}Student;
int main()
{
	int n, k, m; // 用户数，题目数，提交数
	int score[5];
	cin >> n >> k >> m;
	for (int i = 0; i < k; ++i) {
		cin >> score[i];
	}
	Student *stu = new Student[n];
	// 输入提交信息
	while (m--) {
		int id, item, scores;
		cin >> id >> item; // id和题号
		stu[id - 1].id = id;
		cin >> scores;
		if (stu[id - 1].score[item - 1] < scores || stu[id - 1].score[item - 1] == 0) {
			if (scores == -1) scores = 0;
			else stu[id - 1].flag = true;
			stu[id - 1].score[item - 1] = scores;
			stu[id - 1].haveDo[item - 1] = true;
			if (scores == score[item - 1]) {
				// 完成
				++stu[id - 1].solved;
			}
		}
	}
	// 统计总分
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < k; ++j) {
			stu[i].allScore += stu[i].score[j];
		}
	}
	sort(stu, stu + n, [](Student a, Student b) {
		if (a.allScore != b.allScore) return a.allScore > b.allScore;
		else if (a.solved != b.solved) return a.solved > b.solved;
		else return a.id < b.id;
	});
	int rank = 1;
	for (int i = 0; i < n; ++i) {
		if (!stu[i].flag) continue;

		printf("%d %05d %d", rank, stu[i].id, stu[i].allScore);
		if (i < n - 1 && stu[i].allScore != stu[i + 1].allScore) {
			rank = i + 2;
		}
		// 输出分数
		for (int j = 0; j < k; ++j) {
			if (stu[i].haveDo[j]) {
				// 做过
				printf(" %d", stu[i].score[j]);
			}
			else {
				printf(" -");
			}
		}
		printf("\n");
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
