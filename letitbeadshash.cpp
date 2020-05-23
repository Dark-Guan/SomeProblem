#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

int FindDiffClass(int start, string res, unordered_map < string, bool > &resList,
				  int &end, int &numColor)
{
	if (start == end)
	{
		bool findSame = false;
		int j = end;
		string temp = res;
		string tempRes = temp;
		reverse(tempRes.begin(), tempRes.end());
		int len = temp.size();

		do
		{
			if (resList[temp] == true || true == resList[tempRes])
			{
				findSame = true;
				break;
			}

			if (findSame)
			{
				break;
			}
			if (temp.size() > 1)
			{
				temp = temp + temp;
				temp = temp.substr(1, len);
				tempRes = tempRes + tempRes;
				tempRes = tempRes.substr(1, len);
			}
			j--;
		}
		while (j);

		if (findSame)
		{
			return 0;
		}
		else
		{
			resList[res] = true;
			return 1;
		}
	}
	int num = 0;
	for (int i = 0; i < numColor; i++)
	{
		res.push_back('1' + i);
		num += FindDiffClass(start + 1, res, resList, end, numColor);
		res.pop_back();
	}
	return num;
}

int main()
{
	int n, m;
	string res;
	unordered_map < string, bool >resL;
	cin >> n >> m;

	int a = FindDiffClass(0, res, resL, m, n);
	cout << a << endl;
	return 0;
}
