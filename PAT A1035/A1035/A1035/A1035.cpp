// A1035.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	string team, pass; // 用户名 密码
	int counts = 0; // 记录更改数目
	int tempn = n;
	vector<string> outTmp;
	while (n--) {
		cin >> team >> pass;
		bool changed = false;
		for (int i = 0; i < pass.size(); ++i) {
			// 按位更改
			switch (pass[i])
			{
			case '1':
				pass[i] = '@';
				changed = true;
				break;
			case '0':
				pass[i] = '%';
				changed = true;
				break;
			case 'l':
				pass[i] = 'L';
				changed = true;
				break;
			case 'O':
				pass[i] = 'o';
				changed = true;
				break;
			default:
				break;
			}
		}
		if (changed) {
			outTmp.push_back(team);
			outTmp.push_back(pass);
			counts++;
		}
	}

	if (counts == 0) {
		if (tempn == 1)
			cout << "There is " << tempn << " account and no account is modified";
		else
			cout << "There are " << tempn << " accounts and no account is modified";
	}
	else {
		cout << counts;
		for (int i = 0; i < outTmp.size(); ++i) {
			if (i % 2 == 0) cout << endl;
			else cout << " ";
			cout << outTmp[i];
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
