// A1062.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
	string id;
	int virtue;
	int talent;
}Student;
bool cmp(Student a, Student b);
int main()
{
	ios::sync_with_stdio(false);
	int n, L, H;
	cin >> n >> L >> H;
	vector<Student> L1, L2, L3, L4;
	while (n--) {
		Student temp;
		cin >> temp.id >> temp.virtue >> temp.talent;
		if (temp.virtue >= L && temp.talent >= L) {
			if (temp.virtue >= H) {
				if (temp.talent >= H) {
					// L1
					L1.push_back(temp);
				}
				else {
					// L2
					L2.push_back(temp);
				}
			}
			else {
				if (temp.virtue >= temp.talent) {
					// L3
					L3.push_back(temp);
				}
				else {
					// L4
					L4.push_back(temp);
				}
			}
		}
	}
	sort(L1.begin(), L1.end(), cmp);
	sort(L2.begin(), L2.end(), cmp);
	sort(L3.begin(), L3.end(), cmp);
	sort(L4.begin(), L4.end(), cmp);
	cout << L1.size() + L2.size() + L3.size() + L4.size() << endl;
	for (int i = 0; i < L1.size(); ++i) {
		cout << L1[i].id << " " << L1[i].virtue << " " << L1[i].talent << endl;
	}
	for (int i = 0; i < L2.size(); ++i) {
		cout << L2[i].id << " " << L2[i].virtue << " " << L2[i].talent << endl;
	}
	for (int i = 0; i < L3.size(); ++i) {
		cout << L3[i].id << " " << L3[i].virtue << " " << L3[i].talent << endl;
	}
	for (int i = 0; i < L4.size(); ++i) {
		cout << L4[i].id << " " << L4[i].virtue << " " << L4[i].talent << endl;
	}
}
bool cmp(Student a, Student b) {
	if ((a.talent + a.virtue) != (b.talent + b.virtue)) {
		return (a.talent + a.virtue) > (b.talent + b.virtue);
	}
	else if (a.virtue != b.virtue) {
		return a.virtue > b.virtue;
	}
	else {
		return a.id < b.id;
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
