// A1012.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
	int score, rank;
	char name;
}Course;

typedef struct {
	string id;
	Course C, M, E, A; // 课程
}Student;


int main()
{
	ios::sync_with_stdio(false);
	int n, query;
	cin >> n >> query;
	vector<Student> collection;
	while (n--) {
		Student tmp;
		cin >> tmp.id >> tmp.C.score >> tmp.M.score >> tmp.E.score;
		tmp.A.name = 'A';
		tmp.C.name = 'C';
		tmp.M.name = 'M';
		tmp.E.name = 'E';
		tmp.A.score = (tmp.C.score + tmp.M.score + tmp.E.score) / 3;
		collection.push_back(tmp);
	}
	// A排序
	sort(collection.begin(), collection.end(), [](Student a, Student b) {
		return a.A.score > b.A.score;
	});
	collection[0].A.rank = 1;
	for (int i = 1; i < collection.size(); ++i) {
		if (collection[i - 1].A.score == collection[i].A.score) {
			collection[i].A.rank = collection[i - 1].A.rank;
		}
		else {
			collection[i].A.rank = i + 1;
		}
	}
	// C排序
	sort(collection.begin(), collection.end(), [](Student a, Student b) {
		return a.C.score > b.C.score;
	});
	collection[0].C.rank = 1;
	for (int i = 1; i < collection.size(); ++i) {
		if (collection[i - 1].C.score == collection[i].C.score) {
			collection[i].C.rank = collection[i - 1].C.rank;
		}
		else {
			collection[i].C.rank = i + 1;
		}
	}
	// M排序
	sort(collection.begin(), collection.end(), [](Student a, Student b) {
		return a.M.score > b.M.score;
	});
	collection[0].M.rank = 1;
	for (int i = 1; i < collection.size(); ++i) {
		if (collection[i - 1].M.score == collection[i].M.score) {
			collection[i].M.rank = collection[i - 1].M.rank;
		}
		else {
			collection[i].M.rank = i + 1;
		}
	}
	// E排序
	sort(collection.begin(), collection.end(), [](Student a, Student b) {
		return a.E.score > b.E.score;
	});
	collection[0].E.rank = 1;
	for (int i = 1; i < collection.size(); ++i) {
		if (collection[i - 1].E.score == collection[i].E.score) {
			collection[i].E.rank = collection[i - 1].E.rank;
		}
		else {
			collection[i].E.rank = i + 1;
		}
	}

	while (query--) {
		string tmpid;
		cin >> tmpid;
		vector<Student>::iterator it;
		for (it = collection.begin(); it < collection.end(); ++it) {
			if (it->id == tmpid) {
				// 找到
				vector<Course> courseCollection;
				courseCollection.push_back(it->A);
				courseCollection.push_back(it->C);
				courseCollection.push_back(it->M);
				courseCollection.push_back(it->E);
				sort(courseCollection.begin(), courseCollection.end(), [](Course a, Course b) {
					return a.rank < b.rank;
				});
				cout << courseCollection[0].rank << " " << courseCollection[0].name << endl;
				break;
			}
		}
		if (it == collection.end()) cout << "N/A" << endl;
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
