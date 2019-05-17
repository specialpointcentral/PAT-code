// A1088.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <cstdio>
#include <cmath>
#include <cstdlib>
using namespace std;
long gcd(long a, long b) {
	if (b == 0) return a;
	else return gcd(b, a % b);
}

class R
{
public:
	R();
	void scanIn();
	void show();
	void formate();
	R operator+ (const R &a);
	R operator- (const R &a);
	R operator* (const R &a);
	R operator/ (const R &a);
private:
	long up, down;
	bool INF = false;
};
R::R()
{
	up = 0;
	down = 1;
}
void R::scanIn()
{
	scanf("%ld/%ld", &up, &down);
	formate();
}
void R::show() {
	if (INF) {
		printf("Inf");
		return;
	}
	if (up < 0) printf("(");
	if (down == 1) {
		printf("%ld", up);
	}
	else if (abs(up) > down)
	{
		printf("%ld %ld/%ld", up / down, abs(up) % down, down);
	}
	else {
		printf("%ld/%ld", up, down);
	}
	if (up < 0) printf(")");
}
void R::formate()
{
	if (this->up == 0) {
		this->down = 1;
	}
	else {
		long g = gcd(abs(this->up), abs(this->down));
		this->down /= g;
		this->up /= g;
	}
	if (this->down < 0) {
		this->down = -this->down;
		this->up = -this->up;
	}
}
R R::operator+ (const R &a) {
	// 加法运算
	R tmp;
	tmp.up = this->up * a.down + this->down * a.up;
	tmp.down = this->down * a.down;
	tmp.formate();
	return tmp;
}
R R::operator- (const R &a) {
	// 减法运算
	R tmp;
	tmp.up = this->up * a.down - this->down * a.up;
	tmp.down = this->down * a.down;
	tmp.formate();
	return tmp;
}
R R::operator* (const R &a) {
	// 乘法运算
	R tmp;
	tmp.up = this->up * a.up;
	tmp.down = this->down * a.down;
	tmp.formate();
	return tmp;
}
R R::operator/ (const R &a) {
	// 除法运算
	R tmp;
	if (a.up == 0) {
		tmp.INF = true;
	}
	else {
		tmp.up = this->up * a.down;
		tmp.down = this->down * a.up;
		tmp.formate();
	}
	return tmp;
}
int main()
{
	R first, second;
	first.scanIn();
	second.scanIn();
	// 开始计算并输出
	first.show();
	printf(" + ");
	second.show();
	printf(" = ");
	(first + second).show();
	printf("\n");

	first.show();
	printf(" - ");
	second.show();
	printf(" = ");
	(first - second).show();
	printf("\n");

	first.show();
	printf(" * ");
	second.show();
	printf(" = ");
	(first * second).show();
	printf("\n");

	first.show();
	printf(" / ");
	second.show();
	printf(" = ");
	(first / second).show();
	printf("\n");
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
