#include <iostream>
#include <cstring>
using namespace std;
const int BUFFER_LEN = 1024;
int main()
{
	int n, m;
	cin >> n >> m;
	char up[BUFFER_LEN];
	char mid[BUFFER_LEN];
	char temp[BUFFER_LEN];
	char add[] = "+";
	char des[] = "---";
	char space[] = "   ";
	char tab[] = "|";
	for (int j = 0; j < m; j++)
	{
		strcat(up, add);
		strcat(up, des);
		strcat(mid, tab);
		strcat(mid, space);
	}
	strcat(up, add);
	strcat(mid, tab);
	cout << up << endl;

	for (int i = 0; i < n; i++)
	{
		cout << mid << endl;
		cout << up << endl;

	}

	return 0;
}
