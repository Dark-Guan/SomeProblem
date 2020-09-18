#include <iostream>
#include <vector>

using namespace std;

vector<long long> fact;

long long factorial(long n)
{
    if (n < fact.size())
    {
        return fact[n];
    }
    long long f = 0;
    if (n == 0)
    {
        f = 0;
    }
    else if (n == 1)
    {
        f = 1;
    }
    else
    {
        f = factorial(n-1) * n;
    }
    fact.push_back(f);
    cout << "f :";
    cout << f << endl;
    return f;
}

void GetList(vector<long long> &list, long n)
{
    long long temp;
    for (long i = 1; i <= n; i++)
    {
        temp = factorial(2 * n) / (factorial(2 * n - 2*i + 1) * factorial(2*i -1));
        list.push_back(temp);
        cout << "temp:";
        cout << temp <<endl;
    }
}

long getCommonFact(vector<long long> &list)
{
    bool getFact;
    for (long i = list[0]; i > 0; i--)
    {
        getFact = true;
        for (int j = 0; j < list.size(); j++)
        {
            if (list[j] % i != 0)
            {
                getFact = false;
                break;
            }
        }
        if (getFact)
        {
            return i;
        }
    }
    return 1;
}

int main()
{
    long a;
    cin >> a;
    vector<long long> list;
    fact.push_back(0);
    GetList(list, a);
    cout << getCommonFact(list) << endl;
    return 0;
}