// A1033.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef struct {
	int id;
	double dis;
	double price;
}Oil;
int main()
{
	int n;
	double  dis, c, davg; // 加油站个数，距离，油箱大小，平均耗油
	cin >> c >> dis >> davg >> n;
	vector<Oil> oilStation;
	while (n--) {
		Oil tmp;
		cin >> tmp.price >> tmp.dis;
		oilStation.push_back(tmp);
	}
	// 距离排序
	sort(oilStation.begin(), oilStation.end(), [](Oil a, Oil b) {
		return a.dis < b.dis;
	});
	for (int i = 0; i < oilStation.size(); ++i) {
		oilStation[i].id = i;
	}
	int arrived = 0; // 到达位置（加油站位置）
	double cost = 0;
	double haveOil = 0;
	double arriveRoute = 0;
	vector<Oil> sortStation;
	if (oilStation[0].dis != 0) {
		// 说明不能前进
		cout << "The maximum travel distance = 0.00";
		return 0;
	}
	else {
		while (1) {
			// 加油站加油
			sortStation.clear();
			for (auto it = oilStation.begin() + arrived + 1; it != oilStation.end(); ++it) {
				// 循环加入能到达的位置
				if (it->dis >= arriveRoute && it->dis <= arriveRoute + c * davg) {
					sortStation.push_back(*it);
				}
			}
			// 判断是否后续没有加油站了
			if (sortStation.size() == 0) {
				if ((dis - arriveRoute) > davg * c) {
					// 无法顺利到达，加满油
					haveOil = 0;
					arriveRoute += davg * c;
				}
				else {
					// 能到达
					cost += ((dis - arriveRoute) / davg - haveOil) *oilStation[arrived].price;
					haveOil = 0;
					arriveRoute = dis;
				}

				break;
			}

			sort(sortStation.begin(), sortStation.end(), [](Oil a, Oil b) {
				if (a.price == b.price)
					return a.dis < b.dis;
				else
					return a.price < b.price;
			});

			if (sortStation[0].price < oilStation[arrived].price) {
				// 比当前油价低，则加到达第一个加油站的油
				cost += ((sortStation[0].dis - oilStation[arrived].dis) / davg - haveOil) * oilStation[arrived].price;
				haveOil = 0;
				arrived = sortStation[0].id;
				arriveRoute = oilStation[arrived].dis; // 到达
			}
			else {
				// 加油到加满，同时要查看是否一定要加满
				if ((dis - arriveRoute) > davg * c) {
					// 找距离最远价格最低的
					int i = 0; // 距离最远的
					for (; i < sortStation.size() && sortStation[0].price == sortStation[i].price; ++i);
					cost += (c - haveOil) *oilStation[arrived].price;
					haveOil = c - (sortStation[i - 1].dis - oilStation[arrived].dis) / davg;
					arrived = sortStation[i - 1].id;
					arriveRoute = oilStation[arrived].dis; // 到达
				}
				else {
					// 不必加满
					cost += ((dis - arriveRoute) / davg - haveOil) *oilStation[arrived].price;
					haveOil = 0;
					arriveRoute = dis;
					break;
				}

			}
		}
		// 后续判断是否走完路程
		if (arriveRoute < dis) {
			// 走不到
			printf("The maximum travel distance = %.2f", arriveRoute);
		}
		else {
			printf("%.2f", cost);
		}
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
