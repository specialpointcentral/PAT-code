// A1095.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <cstdio>
#include <vector>
#include <map>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;
typedef struct {
	string id;
	int timestamp; // 时间戳
	int status; // 状态，1-in,0-out
}Car;
int main()
{
	int n, query; // 记录数，查询数量
	map<string, vector<Car>> allRec;
	scanf("%d %d", &n, &query);
	while (n--) {
		Car tmp;
		tmp.id.resize(8);
		int hh, mm, ss;
		string status;
		status.resize(4);
		scanf("%s %d:%d:%d %s", tmp.id.c_str(), &hh, &mm, &ss, status.c_str());
		tmp.timestamp = hh * 3600 + mm * 60 + ss;
		tmp.status = (!strcmp(status.c_str(), "in") ? 1 : 0);

		allRec[tmp.id].push_back(tmp);
	}
	map<string, int> timeRec;
	vector<Car> allCar;
	int maxTime = 0; // 最大时间
	// 对车辆排序
	for (auto it = allRec.begin(); it != allRec.end(); ++it) {
		sort((it->second).begin(), (it->second).end(), [](Car a, Car b) {
			return a.timestamp < b.timestamp;
		});
		// 统计时间并剔除无效数据
		int flag = 1; // 期望得到的状态
		int caculateTime = 0; // 计算的时间
		int beginTime = 0; // 开始时间
		for (int j = 0; j < (it->second).size() - 1; ++j) {
			if ((it->second)[j].status == 1 && (it->second)[j + 1].status == 0) {
				// 符合要求的时间段
				caculateTime += ((it->second)[j + 1].timestamp - (it->second)[j].timestamp);
				allCar.insert(allCar.end(), (it->second).begin() + j, (it->second).begin() + j + 2);
			}
		}
		timeRec[it->first] = caculateTime;
		if (maxTime < caculateTime) maxTime = caculateTime;
	}
	sort(allCar.begin(), allCar.end(), [](Car a, Car b) {
		return a.timestamp < b.timestamp;
	});
	int count = 0; // 全局计数
	int i = 0; // 指针
	while (query--) {
		int hh, mm, ss, timestamp;
		scanf("%d:%d:%d", &hh, &mm, &ss);
		timestamp = hh * 3600 + mm * 60 + ss;
		for (; i < allCar.size() && allCar[i].timestamp <= timestamp; ++i) {
			if (allCar[i].status == 1) {
				// in
				++count;
			}
			else {
				// out
				--count;
			}
		}
		printf("%d\n", count);
	}
	// 输出
	for (auto it = timeRec.begin(); it != timeRec.end(); ++it) {
		if (it->second == maxTime)
			printf("%s ", it->first.c_str());
	}
	printf("%02d:%02d:%02d", maxTime / 3600, maxTime % 3600 / 60, maxTime % 60);
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
