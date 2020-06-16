#include <iostream>
#include <map>

/*
3 3 2
82 3.3
85 3.7 
90 4.0
88 3.5
84 2.0
84 1.0 

output 0.1846
X 分拆解成背包问题
*/

using namespace std;

float GetMaxAddPiont( map<int, float> sKey,
    map<int, float> sGet, int score){

    float ret = GetMaxAddPiont();
}

int main(){
    int c,n,x;
    cin  >> c >> n >> x;
    int scores;
    float point;
    map<int, float> sKey;
    map<int, float> sGet;
    for(int i = 0; i < c; i++){
        cin >> scores >> point;
        sKey.insert(make_pair(scores, point));
    }
    for(int i = 0; i < n; i++){
        cin >> scores >> point;
        sGet.insert(make_pair(scores, point));
    }
    cout << GetMaxAddPiont(sKey, sGet, x);
}