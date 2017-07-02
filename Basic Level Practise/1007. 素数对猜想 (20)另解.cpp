/**
让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20
输出样例：
4

这次尝试了另外一个找素数的方法，不过有一个测试点没通过
*/
#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	if (n <= 0) {
		cout << 0 << endl; return 0;
	}
	bool *prime = new bool[n + 1];
	for (int i = 2; i < n; i++)
		prime[i] = (i % 2 == 1);
	for (int i = 3; i*i <= n; i++) {
		if (prime[i])
			for (int j = i + i; j < n; j += i)
				prime[j] = false;
	}
	prime[0] = false;
	prime[1] = false;
	prime[2] = true;
	int last = -1, count = 0;
	for (int i = 2; i <= n; i++) {
		if (prime[i] && (i - last) == 2)count++;
		if (prime[i])last = i;

	}
	cout << count << endl;
	delete[] prime;
	system("pause");
	return 0;
}
