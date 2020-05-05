#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
	int n, m;
	cin >> n >> m;
	vector < int >scores;
	int res = 0, temp;
	int comp;

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		scores.push_back(temp);
	}
	sort(scores.begin(), scores.end(),[](int a, int b)
		 {
		 return a > b;
		 }
	);
     comp = scores[m];
	for (int i = 0; i < n; i++)
	{
		if (scores[i] >= comp)
		{
			res++;
		}
	}
	cout << res << endl;


	return 0;
}
