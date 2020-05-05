#include <iostream>
#include <cstring>
using namespace std;
const int BUFFER_LEN = 128;

void AddToRes(char *res, int n, int maxI)
{
	char temp[BUFFER_LEN];
	if (n > 0 && n <= maxI)
	{
		sprintf(temp, "%d", n);
		strcat(res, temp);

	}

}

int main()
{
	int n, m;
	cin >> n >> m;
	char res[BUFFER_LEN];
	char space[] = "...";
	char temp[BUFFER_LEN];

	if (n < 7)
	{
		for (int i = 1; i <= n; i++)
		{
			sprintf(temp, "%d", i);
			strcat(res, temp);
		}
		cout << res << endl;
	}
	else
	{
		if (m <= 3)
		{
			AddToRes(res, m - 2, n);
			AddToRes(res, m - 1, n);
			AddToRes(res, m, n);
			AddToRes(res, m + 1, n);
			AddToRes(res, m + 2, n);
			strcat(res, space);
			AddToRes(res, n, n);
		}
		else if (m >= (n - 2))
		{
			AddToRes(res, 1, n);
			strcat(res, space);
			AddToRes(res, m - 2, n);
			AddToRes(res, m - 1, n);
			AddToRes(res, m, n);
			AddToRes(res, m + 1, n);
			AddToRes(res, m + 2, n);
		}
		else
		{
			AddToRes(res, 1, n);
			strcat(res,space);
			AddToRes(res, m-2, n);
			AddToRes(res, m-1, n);
			AddToRes(res, m, n);
			AddToRes(res, m+1, n);
			AddToRes(res, m+2, n);
			strcat(res,space);
			AddToRes(res, n, n);
		}
	}

	return 0;
}
