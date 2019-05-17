// A1081.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <cstdio>
#include <cmath>
using namespace std;
long gcd(long a, long b);
class R {
public:
	long up, down;
	R operator+ (const R &a) {
		R tmp;
		tmp.down = a.down * this->down;
		tmp.up = a.up * this->down + this->up * a.down;
		if (tmp.up == 0) {
			tmp.down = 1;
		}
		else {
			long g = gcd(abs(tmp.down), abs(tmp.up));
			tmp.down /= g;
			tmp.up /= g;
		}
		if (tmp.down < 0) {
			tmp.down = -tmp.down;
			tmp.up = -tmp.up;
		}
		return tmp;
	}
};
int main()
{
	int n;
	scanf("%d", &n);
	R r = { 0,1 }, tmp;

	for (int i = 0; i < n; ++i) {
		scanf("%ld/%ld", &(tmp.up), &(tmp.down));
		r = tmp + r;
	}
	// 输出
	if (r.down == 1) {
		// 整数
		printf("%ld", r.up);
	}
	else if (abs(r.up) > r.down) {
		printf("%ld %ld/%ld",r.up/r.down,abs(r.up)%r.down,r.down);
	}
	else {
		printf("%ld/%ld", r.up, r.down);
	}
	
	return 0;
}

long gcd(long a, long b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
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
