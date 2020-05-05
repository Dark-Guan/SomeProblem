#include <iostream>
#include <string>
#include <vector>
using namespace std;

int FindDiffClass(int start, string res, vector < string > resList, int &end, int &numColor)
{
	if (start == end)
	{
		bool findSame = false;
		for(int j = 0; j < end; j ++){
		for(int i = 0; i < resL.size(); i ++){
			
			for(int j = 0; j < end; j ++){
				
			}
		}
		if ()
		{

		}
	}
	int num = 0;
	for (int i = 0; i < numColor; i++)
	{
		res.push_back('1' + i);
		num += FindDiffClass(start + 1,);
		res.pop_back();
	}
	return num;
}

int main()
{
	int n, m;
	string res;
	vector < string > resL;
	cin >> n >> m;

	vector int a = FindDiffClass(0, res, resL, m, n);
	return 0;
}
