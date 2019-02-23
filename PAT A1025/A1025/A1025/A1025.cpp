// A1025.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
typedef struct {
	string id;
	int score;
	int roomrank;
	int allrank;
	int room;
}Student;
int main()
{
	int num; // 考场数
	cin >> num;
	vector<Student> testee;
	for (int i = 0; i < num; ++i) {
		int n;
		cin >> n;
		vector<Student> Stutmp;
		while (n--) {
			Student tmp;
			cin >> tmp.id >> tmp.score;
			tmp.room = i + 1;
			Stutmp.push_back(tmp);
		}
		sort(Stutmp.begin(), Stutmp.end(), [](Student a, Student b) {
			if (a.score != b.score) return a.score > b.score;
			else return a.id < b.id;
		});
		// 编号
		Stutmp[0].roomrank = 1;
		for (int i = 1; i < Stutmp.size(); ++i) {
			if (Stutmp[i].score == Stutmp[i - 1].score) {
				Stutmp[i].roomrank = Stutmp[i - 1].roomrank;
			}
			else {
				Stutmp[i].roomrank = i + 1;
			}
		}
		testee.insert(testee.end(), Stutmp.begin(), Stutmp.end());
	}

	sort(testee.begin(), testee.end(), [](Student a, Student b) {
		if (a.score != b.score) return a.score > b.score;
		else return a.id < b.id;
	});
	cout << testee.size() << endl;
	testee[0].allrank = 1;
	cout << testee[0].id << " " << testee[0].allrank << " " << testee[0].room << " " << testee[0].roomrank << endl;
	for (int i = 1; i < testee.size(); ++i) {
		if (testee[i].score == testee[i - 1].score) {
			testee[i].allrank = testee[i - 1].allrank;
		}
		else {
			testee[i].allrank = i + 1;
		}
		cout << testee[i].id << " " << testee[i].allrank << " " << testee[i].room << " " << testee[i].roomrank << endl;
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
