#include <iostream>
#include <vector>

using namespace std;

int GetValue(char c)
{
    switch (c)
    {
    case 'A':
        return 1;
    case '2':
        return 2;
    case '3':
        return 3;
    case '4':
        return 4;
    case '5':
        return 5;
    case '6':
        return 6;
    case '7':
        return 7;
    case '8':
        return 8;
    case '9':
        return 9;
    case 'T':
        return 10;
    case 'J':
        return 11;
    case 'Q':
        return 12;
    case 'K':
        return 13;
    default:
        return 0;
    }
}

char GetCalc(int index)
{
    static char calcs[4] = {'+', '-', '*', '/'};
    if (index >= 0 && index < 4)
    {
        return calcs[index];
    }
    return '\0';
}

int GetResult(vector<int> vals, vector<char> calc)
{
    int result = vals[0];
    for (int i = 1; i < vals.size(); i++)
    {
        if (calc[i - 1] == '+')
        {
            result = result + vals[i];
        }
        else if (calc[i - 1] == '-')
        {
            result = result - vals[i];
        }
        else if (calc[i - 1] == '*')
        {
            result = result * vals[i];
        }
        else if (calc[i - 1] == '/')
        {
            result = result / vals[i];
        }
    }
    for (int i = 0; i < vals.size() - 1; i++){
        cout << vals[i] << " " << calc[i] << " ";
    }
    cout << vals[vals.size()-1] << " = " << result << endl;
    return result;
}

bool orderAll(vector<int> &chars, vector<bool> charUsed, vector<int> chrOrder, vector<char> calcOrder)
{
    if (chrOrder.size() == chars.size())
    {
        if (GetResult(chrOrder, calcOrder) == 24)
        {
            return true;
        }else{
            return false;
        }
    }
    bool retReturn = false;
    bool ret = false;
    for (int i = 0; i < chars.size(); i++)
    {
        if (!charUsed[i])
        {
            chrOrder.push_back(chars[i]);
            charUsed[i] = true;
            for (int j = 0; j < 4; j++) // + - * /
            {   
                calcOrder.push_back(GetCalc(j));
                ret = orderAll(chars, charUsed, chrOrder, calcOrder);
                if (ret)
                {
                    retReturn = true;
                    return retReturn;
                }
                calcOrder.pop_back();
            }
            charUsed[i] = false;
            chrOrder.pop_back();
        }
    }
    return retReturn;
}

int main()
{
    vector<char> chars;
    vector<int> ints;
    vector<int> intOrder;
    vector<bool> charUsed;
    vector<char> calcOrder;

    char temp;
    for (int i = 0; i < 4; i++)
    {
        cin >> temp;
        chars.push_back(temp);
        charUsed.push_back(false);
        ints.push_back(GetValue(temp));
    }

    if (orderAll(ints, charUsed, intOrder, calcOrder))
    {
        cout << "YES" << endl;
    }
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}