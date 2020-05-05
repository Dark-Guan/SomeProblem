#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
	long n;

	for (long i = 0; i < 5; i++)
	{
		cin >> n;
		bool flag = true;
		for (long j = 2; j < n; j++)
		{
			if (n % j == 0)
			{
				flag = false;
				break;
			}
		}
		if(n == 1){
		    flag = false;
		}
		if (flag == false)
		{
			cout << "NO" << endl;
		}
		else
		{
			cout << "YES" << endl;
		}
	}
	return 0;
}
