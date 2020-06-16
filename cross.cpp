#include <iostream>
#include <map>
#include <vector>

/*
1 
4 3 1 4
1 2 3
2 3 4
3 4 5

outpout NO
*/
using namespace std;

int main()
{
	int t;
	while (t)
	{
		int nPoint, mRoad, start, end;
		cin >> nPoint >> mRoad >> start >> end;
		map < pair < int, int >, int >path;
		int x, y, temp;

		for (int i = 0; i < mRoad; i++)
		{
			cin >> x >> y >> temp;
			path.insert(make_pair(make_pair(x, y), temp));
			path.insert(make_pair(make_pair(y, x), temp));
		}
		

		t--;
	}
}
