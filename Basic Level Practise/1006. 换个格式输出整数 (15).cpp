/**
让我们用字母B来表示“百”、字母S表示“十”，用“12...n”来表示个位数字n（<10），换个格式来输出任一个不超过3位的正整数。例如234应该被输出为BBSSS1234，因为它有2个“百”、3个“十”、以及个位的4。

输入格式：每个测试输入包含1个测试用例，给出正整数n（<1000）。

输出格式：每个测试用例的输出占一行，用规定的格式输出n。

输入样例1：
234
输出样例1：
BBSSS1234
输入样例2：
23
输出样例2：
SS123
*/
#include<iostream>
#include<string>
using namespace std;
int main() {
	int n;
	cin >> n;
	int a = n / 100, b = (n - a * 100) / 10, c = n % 10;
	string res;
	while (a-- > 0) {
		res += "B";
	}
	while (b-->0) {
		res += "S";
	}
	while (c-->0) {
		res += to_string(n % 10 - c);
	}
	cout << res;
	system("pause");
	return 0;
}