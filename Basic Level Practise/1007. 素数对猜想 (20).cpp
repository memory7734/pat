/**
让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20
输出样例：
4
*/
#include<iostream>
using namespace std;
bool is_prime(int n) {
	if (n < 2)return false;
	int i = 2;
	while (i*i <= n) {
		if (n%i == 0) return false;
		i++;
	}
	return true;
}
int main() {
	int n;
	cin >> n;
	int last = -1, count = 0;
	for (int i = 2; i <= n; i++) {
		bool flag = is_prime(i);
		if (flag && (i - last) == 2)count++;
		if (flag)last = i;

	}
	cout << count << endl;
	system("pause");
	return 0;
}