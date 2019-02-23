// A1055.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
	string name;
	int age;
	int worth;
}People;
int main()
{
	ios::sync_with_stdio(false);
	int n, k;
	cin >> n >> k;
	vector<People> allPeople;
	while (n--) {
		People tmp;
		cin >> tmp.name >> tmp.age >> tmp.worth;
		allPeople.push_back(tmp);
	}
	// 对全部进行排序
	sort(allPeople.begin(), allPeople.end(), [](People a, People b) {
		if (a.worth != b.worth) return a.worth > b.worth;
		else if (a.age != b.age) return a.age < b.age;
		else return a.name < b.name;
	});
	// 每个年龄抽取M个，100个
	int age[200] = { 0 };
	vector<People> peoples;
	for (int i = 0; i < allPeople.size(); ++i) {
		if (age[allPeople[i].age - 1] < 100) {
			++age[allPeople[i].age - 1];
			peoples.insert(peoples.end(),allPeople[i]);
		}
	}
	// 按照要求开始查询
	int allk = k;
	while (k--) {
		int outnum, agemin, agemax;
		cin >> outnum >> agemin >> agemax;
		cout << "Case #" << allk - k << ":\n";
		bool flag = false; // 有输出
		for (int i = 0; outnum && i < peoples.size(); ++i) {
			if (peoples[i].age >= agemin && peoples[i].age <= agemax) {
				--outnum;
				flag = true;
				cout << peoples[i].name << " " << peoples[i].age << " " << peoples[i].worth << "\n";
			}
		}
		if (!flag) cout << "None\n";
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
