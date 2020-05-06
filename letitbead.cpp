#include <iostream>
#include <string>
#include <vector>
using namespace std;

int FindDiffClass(int start, string res, vector<string> &resList, int &end, int &numColor)
{
	if (start == end)
	{
		bool findSame = false;
		int j = end;
		string temp = res;
		int len = temp.size();
		do
		{
			for (int i = 0; i < resList.size(); i++)
			{
				if(temp == resList[i]){
					findSame = true;
					break;
				}
			}
			if(findSame){
				break;
			}
			if(temp.size() > 1){
				temp = temp + temp;
				temp = temp.substr(1, len);
			}
			j--;
		}while (j);

		if (findSame)
		{
			return 0;
		}else{
			resList.push_back(res);
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
	vector<string> resL;
	cin >> n >> m;

	int a = FindDiffClass(0, res, resL, m, n);
	cout << a << endl;
		for (int i = 0; i < resL.size(); i++)
			{
				cout<< resL[i] << endl;
			}
	return 0;
}
