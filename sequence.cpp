#include <iostream>
#include <vector>
#include <cstdio>
using namespace std;
int main()
{
	long n;
	vector <char> a;
	char temp[3000];
	cin >> n;
	cout << n << endl;

	for (int i = 0; i < n; i++)
	{
		sprintf(temp, "%s", n);
		cout << temp << endl;
		int len = strlen(temp);
		for (int j = 0; j < len; j++)
		{
			a.push_back(temp[j]);
		}
		if (a.size() > n)
		{
			return a[n];
		}
	}
	return 0;
}
