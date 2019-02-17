// B1004.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <cstdio>
using namespace std;
typedef struct Stu {
	char name[11];
	char className[11];
	int grade;
}Student;
int main()
{
	int n,temp;
	scanf("%d", &n);
	temp = n;
	Student *stu = new Student[n];
	Student *max= stu, *min= stu;
	while (n--) {
		scanf("%s %s %d", stu[n].name, stu[n].className, &stu[n].grade);
	}
	
	for (int i = 1; i < temp; ++i) {
		// i=1目的是最后一个不用比较，起初就是他
		if (max->grade < stu[i].grade) {
			max = &stu[i];
		}
		if (min->grade > stu[i].grade) {
			min = &stu[i];
		}
	}
	printf("%s %s\n", max->name, max->className);
	printf("%s %s", min->name, min->className);
	delete(stu);
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
