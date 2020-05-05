#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
	int n;
	cin >> n;
	vector <string> origin;
	vector <string> result;
	int res = 0;
	string temp;
	

	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		scores.push_back(temp);
	}
	
	for (int i = 0; i < n; i++)
	{
		cin >> temp;
		result.push_back(temp);
	}
	
	for (int i = n-1; i > 0; i--)
	{
	    while(result[i] != origin[i]){
	        temp = origin[i];
	    }
	    
	    
	}
	return 0;
}
