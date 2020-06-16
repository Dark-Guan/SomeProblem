#include <iostream>
#include <map>
#include <vector>

using namespace std;

/*
44 22 0.3 
1 1 1 1
5 7 9 12
0 1 10
1 3 10
0 2 10
2 3 10

output 21

先用floyd算法求得两点之间的最短路径，保存在map[i][j]中，
dp[i][j] i景点 j时间 游玩时的最大开心值
dp[i][k]=max(dp[i][k],dp[i][k-p[i].c-mp[i][j]]+p[i].s)
p[i].c 为旅行开销
p[i].s 为可获得的最大值；
*/

int main(){
    int nPoint, mRoad, timeLimit, start, end;
    cin  >> nPoint >> mRoad >> timeLimit >> start >> end;
    vector<int> cost;
    vector<int> happy;
    map<pair<int,int>,int> path;
    int x, y, temp;
    for(int i = 0; i < nPoint; i++){
        cin >> temp;
        cost.push_back(temp);
    }
    for(int i = 0; i < nPoint; i++){
        cin >> temp;
        happy.push_back(temp);
    }
    for(int i = 0; i < mRoad; i++){
        cin >> x >> y >> temp;
        path.insert(make_pair(make_pair(x,y), temp));
        path.insert(make_pair(make_pair(y,x), temp));
    }
    // max happy 
    // use all the time and max happy
}
